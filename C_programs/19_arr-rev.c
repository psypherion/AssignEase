#include<stdio.h>

int main(){
    int n, arr[100];
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter %d elements : ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Reversed array : ");
    for(int i = n-1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    return 0;
}