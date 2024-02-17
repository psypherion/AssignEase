#include <stdio.h>

int sum(int *arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Sum of all elements : %d", sum(arr, n));
    return 0;
}