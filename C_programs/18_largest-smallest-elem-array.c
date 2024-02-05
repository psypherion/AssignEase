#include<stdio.h>

int main(){
    int n, largest, smallest;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements : ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    largest = arr[0];
    smallest = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    printf("Largest element : %d\nSmallest element : %d", largest, smallest);
    return 0;
    }
