#include<stdio.h>

int main(){
    int a,b;
    printf("Enter a number : ");
    scanf("%d", &a);
    b=a;
    printf("a = %d\n", a);
    printf("a++ = %d\n", a++);
    a=b;
    printf("a-- = %d\n", a--);
    a=b;
    printf("++a = %d\n", ++a);
    a=b;
    printf("--a = %d\n", --a);
    return 0;
}