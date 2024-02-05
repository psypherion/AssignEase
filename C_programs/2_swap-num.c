#include<stdio.h>
int main(){
    int a, b;
    printf("Enter Two Numbers :");
    scanf("%d %d", &a, &b);
    printf("a stores %d and b stores %d\n", a, b);
    a = a*b;
    b = a/b;
    a = a/b;
    printf("After Swapping :\na stores %d and b stores %d\n", a, b);
    return 0;
}