#include<stdio.h>

int main(){
    char arr[] = "Hello";
    char *ptr = &arr[0];
    int len = 0;
    while(*ptr != '\0'){
        len++;
        ptr++;
    }
    printf("Length of string : %d", len);
    return 0;
}