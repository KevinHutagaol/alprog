#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void name_input(char * name, int * size);
int count(char * name, int * size);

int size = 2;
int main() {
    char name_temp[50];
    printf("Masukkan nama Anda:\n\n");

    char * name = malloc(2 * sizeof(char));

    name_input(name, &size);


    while (1) {

        printf("\nOpsi (Nama: %s)\n", name);
        printf("a. Value Nama ASCII\nb. Ganti Nama\nc. Exit\n\n");
        char option;
        scanf(" %c", &option);
        while (getchar() != '\n');

        if (option == 'a') {
            int x = count(name, &size);
            printf("\nValue nama Anda adalah: %d\n\n", x);
        } else if (option == 'b') {
            printf("Masukkan nama Anda:\n\n");
            name_input(name, &size);
        } else if (option == 'c') {
            printf("Program Diselesaikan\n");
            break;
        }
    }

    free(name);
    return 0;
}

void name_input(char * name, int * size) {
    int i = 0;
    while (1) {
        char holder = getchar();
        if (holder == '\n') {
            name[i] = '\0';
            *size = i + 1;
            break;
        }
        name = realloc(name, (i+2) * sizeof(char));
        name[i] = holder;
        i++;
    }
}

int count(char * name, int * size) {
    int value = 0;
    for (int i = 0; i <= *size; i++) {
        value += (int) name[i];
    }

    return value;
}

int val(char*** list_of_str) {

}