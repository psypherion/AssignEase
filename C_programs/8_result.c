#include<stdio.h>
int main(){
    float maths, physics, computer, philosophy, psychology,total, percentage;
    char first_name[20], last_name[20];
    printf("Enter your First name : ");
    scanf("%s", first_name);
    printf("Enter your Last name : ");
    scanf("%s", last_name);
    printf("Enter marks of five subjects \n(Maths, Physics, Computer, Philosophy, Psychology): ");
    scanf("%f %f %f %f %f", &maths, &physics, &computer, &philosophy, &psychology);
    total = maths+physics+computer+philosophy+psychology;
    percentage = ((maths+physics+computer+philosophy+psychology)/500)*100;
    printf("-----------------------------------------Result-----------------------------------------------\n");
    printf("Name : %s %s\n", first_name, last_name);
    printf("Total marks : %0.2f\n", total);
    printf("Percentage : %0.2f\n", percentage);
    if (maths>=40 && physics>=40 && computer>=40 && philosophy>=40 && psychology>=40){
        printf("Result : Pass");
        if (percentage>=40){
            printf("\nGrade : A");
        }
        else if (percentage>=30){
            printf("\nGrade : B");
        }
        else if (percentage>=20){
            printf("\nGrade : C");
        }
        else{
            printf("\nGrade : D");
        }
    }
    else{
        printf("Result : Fail");
    }
    printf("\n-----------------------------------------xxx-----------------------------------------------\n");
    return 0;
}