#include <stdio.h>

void swapArrays(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        int temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

int main() {
    int size;
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);
    int arr1[size], arr2[size];
    printf("Enter elements for the first array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter elements for the second array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr2[i]);
    }
    swapArrays(arr1, arr2, size);
    printf("Arrays after swapping:\n");
    for (int i = 0; i < size; i++) {
        printf("First Array: ");
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("Second Array: ");
        printf("%d ", arr2[i]);
    }
    return 0;
}
