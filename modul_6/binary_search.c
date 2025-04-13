#include <stdio.h>

int binarySearch(const int *arr, int size, int key);

int main() {
    int arr[] = {
        77, 78, 83, 83, 90, 98, 100
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 98;
    int result = binarySearch(arr, size, target);

    if (result == -1) {
        printf("Student with score %d not found", target);
    } else {
        printf("Student with score %d found at index %d", target, result);
    }
}

int binarySearch(const int *arr, const int size, const int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
