#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(){
  int fd;
  int rd;
  char buf[80];

  if((fd=open("/tmp/fifo001", O_RDWR)) == - 1)  {
    perror("fifo");
    exit(0);
  }
  bzero(buf,80);
//  fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
  while ((rd=read(fd, &buf, sizeof(buf))) > -1){
     dprintf(1,"Data[%d]: ",rd);
//     fflush(1);
     write(1,buf,rd);
     bzero(buf,80);
//     sleep(1);
  }
  if(rd == -1) perror("fifo");
  return 0;

} 

