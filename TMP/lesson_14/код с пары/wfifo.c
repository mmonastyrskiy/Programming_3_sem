#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int fd;
  int i=0;
  char buffer[]="Hello world!\n";

  unlink("/tmp/fifo001");
  if((mkfifo("/tmp/fifo001", S_IFIFO|0777)) == -1)  {
    perror("fifo");
    exit(0);
  }

  if((fd=open("/tmp/fifo001", O_RDWR)) == - 1)  {
    perror("fifo");
    exit(0);
  }
//  fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
  while(i++<100){
    printf("%d %s",i,buffer);
    write(fd,buffer,strlen(buffer));
    sleep(1);
  }
  return 0;

} 

