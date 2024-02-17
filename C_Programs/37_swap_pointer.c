#include<stdio.h>

int main(){
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    printf("Before swap : a = %d and b = %d\n", a, b);
    int *ptr1 = &a;
    int *ptr2 = &b;
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    printf("After swap : a = %d and b = %d\n", a, b);
    return 0;
}