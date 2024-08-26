#include<stdio.h>
 union student{
    int marks;
    int id;
    char name;
} s1,s2;

int main(){
    union student  s1,s2;
    s1.marks= 56;
    s2.marks= 44;
    s1.id= 6;
    s2.id= 5;
    

    printf("marks of s1 is: %d\n",s1.marks);
printf("marks of s2 is: %d\n",s2.marks);
printf("id of s1 is: %d\n",s1.id);
printf("id of s2 is: %d\n",s2.id);
    return 0;

}
