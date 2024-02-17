#include <stdio.h>

int main()
{
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    if (remove(filename) == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("Error deleting file.\n");
    }
    return 0;
}