#include<stdio.h>

int main(){
    char arr1[10] = "Hello";
    char arr2[10] = "World";
    char *ptr1 = &arr1[0];
    char *ptr2 = &arr2[0];
    while(*ptr1 == *ptr2){
        if(*ptr1 == '\0'){
            printf("Strings are equal");
            break;
        }
        ptr1++;
        ptr2++;
    }
    if(*ptr1 != *ptr2){
        printf("Strings are not equal");
    }
    return 0;
}