#include<stdio.h>
#include<math.h>
int main(){
    int a, b, c;
    printf("Enter coefficients of quadratic equation : ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Roots of the equation are : %0.2f %0.2f", (-b+sqrt(b*b-4*a*c))/(2*a), (-b-sqrt(b*b-4*a*c))/(2*a));
}