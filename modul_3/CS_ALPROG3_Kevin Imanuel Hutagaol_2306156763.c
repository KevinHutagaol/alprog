#include <stdio.h>
#include <stdlib.h>

void cypher_string(char *str, int num_shift);

int main() {
    printf("Caesar Cipher\n");
    char name[100]; // max 99 char
    printf("Masukkan String: ");
    fgets(name, 100, stdin);
    int num_shift;
    printf("Masukkan Jarak Geser: ");
    scanf(" %d", &num_shift);

    printf("---\n");

    cypher_string(name, num_shift);

    printf("Output: %s", name);
}

void cypher_string(char *str, int num_shift) {
    while (*str != '\n') {
        if (*str == 32) {
            str++;
            continue;
        }
        char temp = (char) (*str) + num_shift;
        if (temp < 'A') {
            printf("out of bounds");
            exit(1);
        }
        if (temp > 'Z' && temp < 'a') {
            printf("out of bounds");
            exit(1);
        }
        if (temp > 'z') {
            printf("out of bounds");
            exit(1);
        }
        if (temp == 'a' || temp == 'A') { temp = '4'; }
        if (temp == 'e' || temp == 'E') { temp = '3'; }
        if (temp == 'u' || temp == 'U') { temp = 'V'; }
        if (temp == 'o' || temp == 'O') { temp = '0'; }
        (*str) = temp;
        str++;
    }
}
