#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#include <math.h>
#define N 4
float factor(float a, float b){}

int main(int argc, const char* argv[]){
    float global_a, global_b,a,b,step;
    pid_t pid[N];
    int pipefd[N][2];
    int i,sum;
    sum =0;
    if (argc != 3 )
    {
        printf("Bad args");
        perror(1);

    }
    global_a = atof(argv[1]);
    global_b = atof(argv[2]);
    step = fabs(global_a-global_b)/N;
    for(i=0;i<N;i++){
        if(pipefd[i]==-1){
            printf("pipe");
            perror(2);
        }

        a = global_a + step * i;
        b = global_b - step*(N-1-i);
        pid[i] = fork();
        if(pid[i]==-1){
            perror(3);
        }
        if(pid[i]==0){
            close(pipefd[i][0]);
            float r;
            char buff[20];
         r=factor(a,b);
        write(pipefd[i][1],sprintf(buffer,"%f",r));
        }




    }

    for(i = 0; i< N ;i++){
        if(pid[i] != 0){
            if(waitpid(pid[i],NULL,0)> 0){
            sum +=atof(read(pipefd[i][0]));
            close(pipefd[i[1]]);
        }
    }
    }
printf("INTEGRAL : %f", sum);
}
