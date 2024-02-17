//W.A.P to check whether a string is palindrome or not
#include<stdio.h>

int len(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
int main(){
    char str[100];
    int i, j, flag = 0;
    printf("Enter string : ");
    scanf("%s", str);

    for(i = 0, j = len(str) - 1; i < j; i++, j--){
        if(str[i] != str[j]){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("String is palindrome");
    }
    else{
        printf("String is not palindrome");
    }
    return 0;
}