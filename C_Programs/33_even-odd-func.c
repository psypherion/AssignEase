#include <stdio.h>

int evenodd(int n){
    if(n%2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    if(evenodd(n)){
        printf("Number is even");
    }
    else{
        printf("Number is odd");
    }
    return 0;
}