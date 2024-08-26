#include<stdio.h>
int new1(int *x,int *y){
    int sum,sub;
    sum=*x+*y;
    *x=sum;
     
    sub=*x-*y;
    *y=sub;
}

   

int main()
    {
        int a=10,b=20;
        printf("value of a is %d, value of b is %d\n",a,b);
        new1(&a,&b);
        printf("now a is %d\n",a);
        printf("Now b is %d",b);
        return 0;
    }