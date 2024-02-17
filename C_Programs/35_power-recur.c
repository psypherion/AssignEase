#include<stdio.h>

int power(int a, int b){
    if(b == 0){
        return 1;
    }
    else{
        return a*power(a, b-1);
    }
}
int main(){
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    printf("Power of %d raised to %d is : %d", a, b, power(a, b));
    return 0;
}