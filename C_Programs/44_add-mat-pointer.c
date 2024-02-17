#include<stdio.h>

int main(){
    int arr1[2][2] = {{1, 2}, {3, 4}};
    int arr2[2][2] = {{5, 6}, {7, 8}};
    int arr3[2][2];
    int *ptr1 = &arr1[0][0];
    int *ptr2 = &arr2[0][0];
    int *ptr3 = &arr3[0][0];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            *(ptr3 + i*2 + j) = *(ptr1 + i*2 + j) + *(ptr2 + i*2 + j);
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", *(ptr3 + i*2 + j));
        }
        printf("\n");
    }
    return 0;
}