#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define N 4



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
    return Integral;
}

int main(int argc, const char* argv[]){
    float global_a, global_b,a,b,step,sum;
    pid_t pid[N];
    int pipefd[N][2];
    char buff[20];
    float r;
    int i,status;
    sum =0;
    if (argc != 3 )
    {
        printf("Bad args");
        exit(1);

    }
    global_a = atof(argv[1]);
    global_b = atof(argv[2]);
    step = fabs(global_a-global_b)/N;
    for(i=0;i<N;i++){
        if(pipe(pipefd[i])==-1){
            printf("pipe");
            exit(2);
        }

        a = global_a + step * i;
        b = global_b - step*(N-1-i);
        pid[i] = fork();
        if(pid[i]==-1){
            exit(3);
        }
        if(pid[i]==0){
            close(pipefd[i][0]);
         r=intrgral(a,b);
         sprintf(buff,"%f",r);
        write(pipefd[i][1],buff,20);
        }




    }

    for(i = 0; i< N ;i++){
        if(pid[i] != 0){
            if(waitpid(pid[i],&status,WNOHANG)> 0){
            read(pipefd[i][0],buff,20);
            sum += atof(buff);
            close(pipefd[i][1]);
        }
        else{
            if(status == ECHILD){
                printf("No child exists");
                break;
            }
            else{
                printf("Critical error %d", status);
                exit(status);
            }
        }
    }
    }
printf("INTEGRAL : %f", sum);
}
