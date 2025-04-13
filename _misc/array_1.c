#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_arr(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap_generic(void *x, void *y, size_t size) {
    char temp[size];

    memcpy(temp, y, size);
    memcpy(y, x, size);
    memcpy(x, temp, size);
}

int main() {
    int arr[] = {1, 2, 3,  4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }


    printf("\n");
    swap_generic(&arr[0], &arr[1], sizeof(arr[0]));

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}
