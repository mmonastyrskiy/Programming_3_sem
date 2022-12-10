#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#include <poll.h>
#define NUM 4
#define errExit(msg)    do { perror(msg); _exit(EXIT_FAILURE); } while (0)

void child_handler(int sig) {
    pid_t pid;
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0);
}

int main(int argc, char *argv[]) {


  int pipefd[NUM][2];
  pid_t cpid[NUM];

  int nfds, num_open_fds;
  struct pollfd *pfds;
  int ready;

  unsigned char i,tt;
  char buf;
  int rr;

  sigaction (SIGCHLD, &new_act, &old_act);

if (argc != 2) {
   fprintf(stderr, "Usage: %s <string>\n", argv[0]);
   _exit(EXIT_FAILURE);
}

srand(time(NULL));

num_open_fds = nfds = NUM;
pfds = calloc(nfds, sizeof(struct pollfd));
if (pfds == NULL) errExit("malloc");

for (i=0;i<NUM;i++){           
  tt=(unsigned char)rand()%10;
  dprintf(STDOUT_FILENO,"time[%X]\n",tt);
           
  if (pipe(pipefd[i]) == -1) errExit("pipe");
  pfds[i].fd = pipefd[i][0];
  pfds[i].events = POLLIN;
  if ((cpid[i] = fork()) == -1) errExit("fork");

  if (cpid[i] == 0) {    
     close(pipefd[i][0]);
     sleep(tt);
     write(pipefd[i][1], argv[1], strlen(argv[1]));
     write(pipefd[i][1], &i, 1);
     write(pipefd[i][1], &tt, 1);
     close(pipefd[i][1]);
     _exit(EXIT_SUCCESS);
  } else {           
     close(pipefd[i][1]);
  }
}

printf("waiting... %d\n",num_open_fds);
fflush(stdout);
sleep(7);

while (num_open_fds > 0) {
  printf("\ntry poll:\n");
  fflush(stdout);
  for (i = 0; i < NUM; i++) pfds[i].revents=0;
  if ((ready = poll(pfds, nfds, -1)) == -1) errExit("poll");
  for (i = 0; i < NUM; i++) {
     if (pfds[i].revents != 0) {
        printf("  fd=%d; events: %7s%8s%8s  ", pfds[i].fd,
                (pfds[i].revents & POLLIN)  ? "POLLIN "  : "",
                (pfds[i].revents & POLLHUP) ? "POLLHUP " : "",
                (pfds[i].revents & POLLERR) ? "POLLERR " : "");
                fflush(stdout);
        if (pfds[i].revents & POLLIN) {
           while ((rr=read(pfds[i].fd, &buf, 1)) > 0){
              write(STDOUT_FILENO, &buf, 1);
              printf("[%X]",buf);
              fflush(stdout);
           }
           printf("\n"); 
           fflush(stdout);
           if(rr < 0 ) errExit("read");
           if(rr == 0 ) write(STDOUT_FILENO, "\n", 1);
        } else 
        if ((pfds[i].revents & POLLHUP)&&~(pfds[i].revents & POLLIN)) {
           printf("closing [%d] %d %d\n",i,pipefd[i][0],pfds[i].fd);
           fflush(stdout);
           if (close(pfds[i].fd) < 0 ) errExit("close pfds");
           pfds[i].fd = -1;
           pfds[i].events=0;
           num_open_fds--;
        }
     }
  }
}

  exit(EXIT_SUCCESS);
}

