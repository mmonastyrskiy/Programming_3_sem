#include <stdio.h>
union num {
    unsigned int inum;
    float fnum;

};
void bprint(unsigned int a){
    int i;
    for(i=31;i>=0;i--){
        ((a &((unsigned int)1 << i))!= 0) ? printf('1') : printf('0');
        if(i==23 || i==31){
            printf(" ");
        }
    }
    printf("\n");

}
void b2print(unsigned int a){

        int i;
    for(i=63;i>=0;i--){
        ((a &((unsigned int)1 << i))!= 0) ? printf('1') : printf('0');
        if(i==52 || i==63){
            printf(" ");
        }
    }
    printf("\n");

}

int main(int argc, const char*[]){
    union num a1, a2, a3, a4;
    a1.fnum =1.23;
    a2.fnum =6.625;
    a3.fnum =-31.567825;
    a1.fnum =-31.567824;
    /*printf("%f %d\n",a1.fnum,a1.inum);*/
    bprint(a1.inum);
}