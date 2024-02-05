#include <stdio.h>
#include <math.h>

int main() {
    float p, r, t, n;
    double si, ci;
    int choice;
    printf("Enter Your Choice :\n1. Simple interest \n2. Compound interest\n--->");
    scanf("%d", &choice);
    printf("Enter Principle : ");
    scanf("%f", &p);
    printf("Enter Rate : ");
    scanf("%f", &r);
    printf("Enter Time : ");
    scanf("%f", &t);
    r = r / 100;

    if (choice == 1) {
        si = p * r * t;
        printf("Simple interest is: %f\n", si);
    } else if (choice == 2) {
        printf("Enter Number of times interest is compunded : ");
        scanf("%f", &n);
        ci = p * (pow((1 + r), n*t)) - p;
        printf("Compound interest is: %f\n", ci);
    }

    return 0;
}
