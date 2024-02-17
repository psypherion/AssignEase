// arr deletion from any specified location
#include<stdio.h>

int main(){
    int n, arr[100], pos, i;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the position from where you want to delete : ");
    scanf("%d", &pos);
    if(pos > n){
        printf("Invalid position");
    }
    else{
        for(i = pos-1; i < n-1; i++){
            arr[i] = arr[i+1];
        }
        printf("Array after deletion : ");
        for(i = 0; i < n-1; i++){
            printf("%d ", arr[i]);
        }
    }
    return 0;
}