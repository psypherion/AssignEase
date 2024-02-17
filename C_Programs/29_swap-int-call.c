// Write a program to swap two integers using call by value and call by reference methods of passing arguments to a function.

#include<stdio.h>

void swapbyval(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swapbyref(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    printf("Before swap : a = %d and b = %d\n", a, b);
    swapbyval(a, b);
    printf("After swap by value : a = %d and b = %d\n", a, b);
    swapbyref(&a, &b);
    printf("After swap by reference : a = %d and b = %d\n", a, b);
    return 0;
}