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
    int key;
    printf("Enter key : ");
    scanf("%d", &key);
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(*(ptr + i) == key){
            printf("Key found at index %d", i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Key not found");
    }
    return 0;
}