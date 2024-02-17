#include <stdio.h>

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int a, b;
    printf("Enter Two Numbers : ");
    scanf("%d %d", &a, &b);
    printf("Maximum number is : %d", max(a, b));
    return 0;
}