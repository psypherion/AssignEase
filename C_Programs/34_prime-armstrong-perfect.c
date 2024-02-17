#include<stdio.h>

int prime(int n){
    int i;
    for(i = 2; i < n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
int armstrong(int n){
    int temp = n, sum = 0, rem;
    while(temp != 0){
        rem = temp%10;
        sum += rem*rem*rem;
        temp /= 10;
    }
    if(sum == n){
        return 1;
    }
    return 0;
}
int perfect(int n){
    int sum = 0, i;
    for(i = 1; i < n; i++){
        if(n%i == 0){
            sum += i;
        }
    }
    if(sum == n){
        return 1;
    }
    return 0;
}
int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    if(prime(n)){
        printf("Number is prime");
    }
    else if(armstrong(n)){
        printf("Number is armstrong");
    }
    else if(perfect(n)){
        printf("Number is perfect");
    }
    else{
        printf("Number is neither prime, armstrong nor perfect");
    }
    return 0;
}