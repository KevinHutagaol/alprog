#include <stdio.h>

void shift_ascii(char *s);

int main(void) {
    char hero[5][10] = {"gusion", "fanny", "yin", "johnson", "nana"};

    for (int i = 0; i < sizeof(hero) / sizeof(hero[0]); i++) {
        shift_ascii(hero[i]);
        printf("Hero %d: %s \n", i, hero[i]);
    }
}

void shift_ascii(char *s) {
    for (; *s; s++) {
        // kalo dia 'z' di shift jadi 'a'
        if (*s == 'z') {
            *s = 'a';
            continue;
        }
        // kalo dia 'Z' di shift jadi 'A'
        if (*s == 'Z') {
            *s = 'A';
            continue;
        }
        // kalo dia '9' di shift jadi '0'
        if (*s == '9') {
            *s = '0';
            continue;
        }
        // shift biasa
        (*s)++;
    }
}
