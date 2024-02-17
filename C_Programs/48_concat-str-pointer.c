#include<stdio.h>

int main(){
    char arr1[10] = "Hello";
    char arr2[10] = "World";
    char *ptr1 = &arr1[0];
    char *ptr2 = &arr2[0];
    while(*ptr1 != '\0'){
        ptr1++;
    }
    while(*ptr2 != '\0'){
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';
    printf("%s", arr1);
    return 0;
}