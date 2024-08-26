#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    p=(int*)malloc(3* sizeof(int));

    for(int i=0;i<3;i++){
        printf("The value at %d is:",i);
        scanf("%d",p[i]);
    }
    for(int i=0;i<3;i++){
        printf("The value at %d is:%d",i,p[i]);
    }
    return 0;

}

