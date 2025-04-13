#include <stdio.h>
#include <stdlib.h>

int my_func(const int a, const int b) {
    return a + b;
}

int my_func2(const int a, int (*fun)(const int, const int)) {
    return fun(a, a);
}

int main() {
    printf("Hello World\n");
    int val = my_func2(2, my_func);
    printf("%d\n", val);
}
