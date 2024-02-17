#include<stdio.h>

int main(){
    int n, m, arr1[100][100], arr2[100][100], arr3[100][100];
    printf("Enter number of rows and columns : ");
    scanf("%d %d", &n, &m);
    printf("Enter elements of first matrix : ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter elements of second matrix : ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("First matrix : \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("Second matrix : \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr3[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
    printf("Product of matrices : \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}