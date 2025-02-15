#include <stdio.h>

int main() {
    int hasil = tambah(3, 4); // ERROR: Compiler belum tahu tentang fungsi ini
    printf("Hasil: %d\n", hasil);
    return 0;
}

int tambah(int a, int b) {
    return a + b;
}
