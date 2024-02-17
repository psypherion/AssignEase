// 39.Write a program to input and print array elements using pointer.

#include<stdio.h>

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = &arr[0];
    printf("Enter array elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array elements are : ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(ptr + i));
    }
    return 0;