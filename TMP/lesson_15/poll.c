#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <poll.h>
#define N 10





float f(float x ){
    return sin(x);
}
float intrgral(float a, float b){
  int i;
  double Integral;
  double h = 0.001;

  double n;

  n = (b - a) / h;
  Integral = 0.0;
  for(i = 1; i <= n; i++)
    Integral = Integral + h * f(a + h * (i - 0.5));
printf("Counted: %f[PID: %d]\n",Integral,getpid());
    return Integral;
}

int main(int argc, const char* argv[]){


    int nfds, num_open_fds;
  struct pollfd *pfds;

    float global_a, global_b,a,b,step,sum,tmp;
    pid_t pid[N];
    int pipefd[N][2],parentpid,stat,ready;
    char buff[20];
    float r;
    int i;
    sum =0;
    stat=0;
    parentpid = getpid();
    /*printf("Parent: %d",parentpid);*/
    if (argc != 3 )
    {
        printf("Bad args");
        exit(1);

    }
    srand(time(NULL));

    num_open_fds = nfds = N;
pfds = calloc(nfds, sizeof(struct pollfd));
if(pfds == NULL){
    printf("Malloc error");
    exit(4);

}
    global_a = atof(argv[1]);
    global_b = atof(argv[2]);
    if (global_a>global_b){
        tmp = global_b;
        global_b = global_a;
        global_a = tmp;
        stat = 1;
    }
    step = fabs(global_a-global_b)/N;
    for(i=0;i<N;i++){
        if(pipe(pipefd[i])==-1){
            pfds[i].fd = pipefd[i][0];
            pfds[i].events = POLLIN;
            printf("pipe");
            exit(2);
        }

        a = global_a + step * i;
        b = global_b - step*(N-1-i);
        if(getpid() ==parentpid){
        pid[i] = fork();
    }
        if(pid[i]==-1){
            exit(3);
        }
        if(pid[i] != 0){
        dprintf(STDOUT_FILENO,"BORN %f %f [PID %d]\n",a,b,pid[i]);
    }
        if(pid[i]==0){
            close(pipefd[i][0]);
         r=intrgral(a,b);
         sprintf(buff,"%f",r);
        write(pipefd[i][1],buff,20);
        _exit(0);
        }
        }


        for (i = 0; i < N; i++) pfds[i].revents=0;
         if ((ready = poll(pfds, nfds, -1)) == -1) {
            printf("poll error");
            exit(10);
         }

            printf("try poll\n");
            while(num_open_fds > 0){
        for(i=0;i<N;i++){
            if(pid[i] != 0){
            if(pfds[i].revents & POLLIN){
            read(pipefd[i][0],buff,20);
            sum += atof(buff);
            dprintf(STDOUT_FILENO,"Transmitted %f [PID: %d]\n",atof(buff),pid[i]);
            if(pfds[i].revents & POLLHUP){
            close(pipefd[i][1]);        
            num_open_fds--;
        }
        }
        else if(pfds[i].revents & POLLHUP){
            close(pipefd[i][1]);
            num_open_fds--;
        }
        else{
            /*printf("error");*/
        }
    }
        }

        }

        if(stat ==1){
            sum*=-1;
        }
    printf("\n\n\nANSWER:%f\n",sum);
    return 0;
    }