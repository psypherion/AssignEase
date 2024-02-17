#include<stdio.h>
int main(){
    int n, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &n);
    int count = 0, first_digit, last_digit;
    printf("\nValue of n : %d\n", n);
    int num = n;
    while(n>0){
        n = n/10;
        count += 1;
    }
    int count_digit = 0;
    for(int i = 0; i < count; i++){
        count_digit +=1;
        if (count_digit == 1){
            first_digit = num%10;
        }
        else if(count_digit == count){
            last_digit = num%10;
        }
        num = num/10;
    }
    printf("Sum of first and last digit is : %d", first_digit+last_digit);
    return 0;
}