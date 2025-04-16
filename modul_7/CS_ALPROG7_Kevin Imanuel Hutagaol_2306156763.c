#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_of_zeroes(int n);
void bubble_sort_generic(void *array, size_t member_size, int array_size, int (*compare)(const int *, const int *));
int comparison(const int* a, const int* b);
void print_with_brackets(int *arr, int n);

int main() {
    printf("How many numbers: ");
    int size;
    scanf("%d", &size);

    int *nums = (int *) malloc(size * sizeof(int));
    printf("Enter Numbers:\n");

    for (int i = 0; i < size; i++) fscanf(stdin, "%d", &nums[i]);
    printf("Before sort\n");
    for (int i = 0; i < size; i++) printf("%d ", nums[i]);


    printf("\nAfter sort\n");
    bubble_sort_generic(nums, sizeof(int), size, comparison);
    for (int i = 0; i < size; i++) printf("%d ", nums[i]);

    printf("\nWith Brackets\n");
    print_with_brackets(nums, size);

    free(nums);
}


int num_of_zeroes(int n)
{
    long long bin = 0;
    int rem, zeroes = 0, i = 1;

    while (n != 0)
    {
        rem = n % 2;
        if (rem == 0)
            zeroes++;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return zeroes;
}

void bubble_sort_generic(void *array, size_t member_size, int array_size, int (*compare)(const int *, const int *)) {
    for (int step = 0; step < array_size - 1; ++step) {
        for (int i = 0; i < array_size - step - 1; ++i) {
            void *arr1 = &array[i * member_size];
            void *arr2 = &array[(i + 1) * member_size];

            if (compare(arr1, arr2) > 0) {
                char temp[member_size];
                memcpy(temp, arr2, member_size);
                memcpy(arr2, arr1, member_size);
                memcpy(arr1, temp, member_size);
            }
        }
    }
}

int comparison(const int* a, const int* b) {
    int a_zeros = num_of_zeroes(*a);
    int b_zeros = num_of_zeroes(*b);


    if (a_zeros > b_zeros) return 1;
    if (a_zeros < b_zeros) return -1;

    if (*a > *b) return -1;
    if (*a < *b) return 1;

    return 0;
}

void print_with_brackets(int *arr, int n) {
    printf("[");
    int prev_zeros;
    int next_zeros;
    for (int i = 0; i < n; i++) {

        if (i == n - 1) {
            printf( "%d]", arr[i]);
            continue;
        }

        prev_zeros = num_of_zeroes(arr[i]);
        next_zeros = num_of_zeroes(arr[i + 1]);

        if (next_zeros == prev_zeros) {
            printf("%d ", arr[i]);
        } else {
            printf("%d], [", arr[i]);
        }

    }
}