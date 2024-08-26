#include<stdio.h>
#include<stdlib.h>

int k,l,z;

typedef struct poly_term{
    int coeff;
    int xdegree;
    int ydegree;
}p_term;

p_term* poly_mergesort(p_term arr[], int size){
    z=0;
    p_term* arr2 = (p_term*)malloc(size*sizeof(p_term));
    int i,j,n;
    for(i = size; i>1; i--){
        for(j = 0; j< i-1; j++){
            if((arr[j].xdegree<arr[j+1].xdegree)||(arr[j].xdegree==arr[j+1].xdegree&&arr[j].ydegree<arr[j+1].ydegree)){
                p_term temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(j = 0; j <size; j++){
        if(arr[j].xdegree==arr[j+1].xdegree&&arr[j].ydegree==arr[j+1].ydegree){
            arr2[z].coeff = arr[j].coeff+arr[j+1].coeff;
            arr2[z].xdegree = arr[j].xdegree;
            arr2[z].ydegree = arr[j].ydegree;
            j++;
            z++;
        }
        else{
            arr2[z].coeff = arr[j].coeff;
            arr2[z].xdegree = arr[j].xdegree;
            arr2[z].ydegree = arr[j].ydegree;
            z++;
        }
    }
    return arr2;
}

p_term* poly_addition(p_term arr1[],int size1, p_term arr2[], int size2){
    int size3 = size1 + size2;
    k = 0;
    p_term* arr3 = (p_term*)malloc((size3)*sizeof(p_term));
    int i,j;
    for(i = 0; i<size1; i++){
        for(j = 0; j<size2; j++){
            if(arr1[i].xdegree==arr2[j].xdegree&&arr1[i].ydegree==arr2[j].ydegree){
                arr3[k].coeff = arr1[i].coeff+arr2[j].coeff;
                arr3[k].xdegree = arr1[i].xdegree;
                arr3[k].ydegree = arr1[i].ydegree;
                k++;
                arr1[i].coeff = 0;
                arr2[j].coeff = 0;
            }
        }
    }
    for(i = 0; i<size1; i++){
        if(arr1[i].coeff!=0){
            arr3[k].coeff = arr1[i].coeff;
            arr3[k].xdegree = arr1[i].xdegree;
            arr3[k].ydegree = arr1[i].ydegree;
            k++;
        }
    }
    for(j = 0; j<size2; j++){
        if(arr2[j].coeff!=0){
            arr3[k].coeff = arr2[j].coeff;
            arr3[k].xdegree = arr2[j].xdegree;
            arr3[k].ydegree = arr2[j].ydegree;
            k++;
        }
    }

    arr3 = poly_mergesort(arr3,k);
    k = z;
    return arr3;
}

p_term* poly_multiply(p_term arr1[],int size1, p_term arr2[],int size2){
    int size3 = size1*size2,i,j;
    l=0;
    p_term* arr3 = (p_term*)malloc(size3*sizeof(p_term));
    for(i = 0; i<size1; i++){
        for(j = 0; j<size2; j++){
            arr3[l].coeff = arr1[i].coeff*arr2[j].coeff;
            arr3[l].xdegree = arr1[i].xdegree+arr2[j].xdegree;
            arr3[l].ydegree = arr1[i].ydegree+arr2[j].ydegree;
            l++;
        }
    }
    arr3 = poly_mergesort(arr3,size3);
    l = z;
    return arr3;
}

int main(){
    int size1, size2, i;
    printf("Enter size of first polynomial: ");
    scanf("%d",&size1);
    printf("Enter size of second polynomial: ");
    scanf("%d",&size2);
    p_term* arr1 = (p_term*)malloc(size1*sizeof(p_term));
    p_term* arr2 = (p_term*)malloc(size2*sizeof(p_term));
    for(i = 0; i<size1; i++){
        printf("Enter coefficient of term %d: ",i+1);
        scanf("%d",&arr1[i].coeff);
        printf("Enter x degree of term %d: ",i+1);
        scanf("%d",&arr1[i].xdegree);
        printf("Enter y degree of term %d: ",i+1);
        scanf("%d",&arr1[i].ydegree);
    }
    for(i = 0; i<size2; i++){
        printf("Enter coefficient of term %d: ",i+1);
        scanf("%d",&arr2[i].coeff);
        printf("Enter x degree of term %d: ",i+1);
        scanf("%d",&arr2[i].xdegree);
        printf("Enter y degree of term %d: ",i+1);
        scanf("%d",&arr2[i].ydegree);
    }
    p_term* arr3 = poly_addition(arr1,size1,arr2,size2);
    p_term* arr4 = poly_multiply(arr1,size1,arr2,size2);
    printf("Result of additon: \n");
    for(i = 0; i<k; i++){
        printf("+%d*x^%d*y^%d ",arr3[i].coeff,arr3[i].xdegree,arr3[i].ydegree);
    }
    printf("\n\nResult of multiplication: \n");
    for(i = 0; i<l; i++){
        printf("+%d*x^%d*y^%d ",arr4[i].coeff,arr4[i].xdegree,arr4[i].ydegree);
    }

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    return 0;
}