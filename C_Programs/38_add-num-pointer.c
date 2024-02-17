#include<stdio.h>

int main(){
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    int *ptr1 = &a;
    int *ptr2 = &b;
    int sum = *ptr1 + *ptr2;
    printf("Sum = %d", sum);
    return 0;
}