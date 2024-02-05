#include<stdio.h>
int main(){
    int n, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("\n");
    // Length of Digit:
    int len = 0;
    int num = n;
    for(int i = 0; n!=0; i++){
        n = n/10;
        len = i+1;
    }
    for (int i = 0; i < len; i++){
        sum = sum + num%10;
        num = num/10;
    }
    printf("Sum of Digits : %d", sum);
    return 0;
}