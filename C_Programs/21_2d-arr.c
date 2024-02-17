// Create 2d array and also select a particular element from it
#include<stdio.h>

int main(){
    int n, m, arr[100][100];
    int row, col;
    printf("Enter number of rows and columns : ");
    scanf("%d %d", &n, &m);
    printf("Enter elements : ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Matrix : \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Enter row and column : ");
    scanf("%d %d", &row, &col);
    printf("Element : %d", arr[row-1][col-1]);
    return 0;
}