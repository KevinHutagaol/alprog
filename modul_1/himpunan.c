#include <stdio.h>

int main(void) { 
    // membuat himpunan A
    int min_number = 1;
    int max_number = 50; 
    // jumlah bilangan dalam range 1 - 50 yang dapat dibagi 3 dan dapat dibagi 5 (23)
    int length_array = (int) 50 / 3 + (int) 50 / 5 - (int) 50 / (3*5) - 1; 
    int himpunan_a[length_array];
    int count = 0;
    for (int i = min_number; i < max_number; i++) { 
        if (i % 3 == 0 || i % 5 == 0) { 
            himpunan_a[count] = i;
            count++;
        }
    }


    // memprint himpunan A
    int start_of_print = 5;
    int i = start_of_print; 
    while (i < sizeof(himpunan_a) / sizeof(int)) {
        printf("%d ", himpunan_a[i]);
        i++;
    }
    
    return 0;
}