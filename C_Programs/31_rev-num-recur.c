#include<stdio.h>

int reverse(int n){
    if(n == 0){
        return 0;
    }
    else{
        return (n%10) + reverse(n/10);
    }
}
int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("Reverse of number : %d", reverse(n));
    return 0;
}