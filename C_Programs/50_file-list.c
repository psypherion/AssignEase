#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char arr[100];
    printf("Enter directory name : ");
    scanf("%s", arr);
    char command[100] = "ls ";
    strcat(command, arr);
    system(command);
    return 0;
}