#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("/home/s4ms3pi0l/Documents/demo.txt", "r");
    if (fp == NULL)
    {
        printf("Error!");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}