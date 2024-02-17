#include<stdio.h>

int main(){
    char arr1[] = "Hello";
    char arr2[10] = "World";
    char *ptr1 = &arr1[0];
    char *ptr2 = &arr2[0];
    for(int i = 0; i < 10; i++){
        *(ptr2 + i) = *(ptr1 + i);
    }
    printf("%s", ptr2);
    return 0;
}