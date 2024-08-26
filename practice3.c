#include<stdio.h>
int func(int array[]){
    for(int i=0;i<4;i++){
        printf("The value of %d id %d",i,array[i]);
    }
}
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        printf("The value is %d: ",i);
        scanf("%d",arr[i]);
    }
    printf("THe array is:");
    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    
    func(arr);
    return 0;
    }