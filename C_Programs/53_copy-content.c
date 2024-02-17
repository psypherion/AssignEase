#include <stdio.h>
#include<string.h>
#define MAX_PATH_LENGTH 100

int main() {
    FILE *sourceFile, *destinationFile;
    char sourcePath[MAX_PATH_LENGTH], destinationPath[MAX_PATH_LENGTH];
    char ch;
    printf("Enter the source file path: ");
    fgets(sourcePath, MAX_PATH_LENGTH, stdin);
    sourcePath[strcspn(sourcePath, "\n")] = '\0';
    sourceFile = fopen(sourcePath, "r");

    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }
    printf("Enter the destination file path: ");
    fgets(destinationPath, MAX_PATH_LENGTH, stdin);
    destinationPath[strcspn(destinationPath, "\n")] = '\0';
    destinationFile = fopen(destinationPath, "w");

    if (destinationFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }
    fclose(sourceFile);
    fclose(destinationFile);
    printf("Text copied successfully!\n");
    return 0;
}
