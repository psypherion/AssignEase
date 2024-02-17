#include<stdio.h>

float add(float a, float b){
    return a + b;
}

float sub(float a, float b){
    return a - b;
}

float mul(float a, float b){
    return a * b;
}

float div(float a, float b){
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0; // You can choose to handle this error in a different way if needed
    }
}

int main(){
    float a, b;
    
    printf("Enter two numbers : ");
    scanf("%f %f", &a, &b); // Use %f for floating-point numbers
    
    printf("Addition : %f\nSubtraction : %f\nMultiplication : %f\n", add(a, b), sub(a, b), mul(a, b));
    
    // Check for division by zero before performing the division
    if (b != 0) {
        printf("Division : %f\n", div(a, b));
    } else {
        printf("Division : Undefined (division by zero)\n");
    }

    return 0;
}