#include <stdio.h>

void calculate(int *num) {
    // nilai num akan berubah secara langsung
    *num = 2 * (*num);
}

int main() {

    int num1 = 5;
    // pass by refrence
    calculate(&num1);

    printf("%d\n", num1);

}
