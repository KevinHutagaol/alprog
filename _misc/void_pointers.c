#include <stdio.h>
#include <stdlib.h>

typedef struct my_struct {
    int a;
    int b;
} my_struct;

int get_a(const my_struct *my_struct) {
    return my_struct->a;
}

int get_b(const my_struct *my_struct) {
    return my_struct->b;
}

void print_generic(void *arr, size_t member_size, size_t arr_size, int (*get_elem)(void const *)) {
    for (size_t i = 0; i < arr_size * member_size; i = i + member_size) {
        int val = get_elem(arr + i);
        printf("%d ", val);
    }
}


void fun_1(void *arr, size_t member_size, int length) {
    void *ptr = arr + (length - 1) * member_size;
    int val = get_a(ptr);
    printf("%d\n", val);
}

int main() {
    my_struct test[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    //
    // print_generic(test, sizeof(test[0]), sizeof(test) / sizeof(test[0]), get_a);
    // printf("\n");
    // print_generic(test, sizeof(test[0]), sizeof(test) / sizeof(test[0]), get_b);

    fun_1(test, sizeof(test[0]) , sizeof(test) / sizeof(test[0]));

}
