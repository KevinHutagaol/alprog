#include <stdio.h>

int max(int *a, int n) {
    int i, max;
    max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

int main() {
    // int arr[3] = {1,2,3};
    // int i = 0, j = 1;
    //
    // while (i < 3) {
    //     if (arr[i] % j == 0) {
    //         printf("%d ", arr[i]);
    //     }
    //     i++;
    //     j++;
    // }

    // int i, j, k = 5;
    //
    // for (i = 1; i <= 5; i++) {
    //     for (j = 1 ; j <= k; j++) {
    //         printf(" ");
    //     }
    //
    //     for (j = 1; j <= (2*i - 1); j++) {
    //         printf("*");
    //     }
    //
    //     printf("\n");
    //     k--;
    // }

    int size = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int max_val = max(arr, size);

    printf("%d", max_val);
}
