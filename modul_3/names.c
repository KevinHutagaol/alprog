#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h> // FOR TESTING

#define MIN_BUFFER 8

int calculate_ascii(char **str);

void get_name(char **name);

int name_editor(char **name);

int main(void) {
    char *current_name = (char *) malloc(MIN_BUFFER * sizeof(char));
    if (current_name == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    printf("Enter your name: \n");
    get_name(&current_name);
    printf("\n");

    for (;;) {
        int loop_flag = name_editor(&current_name);
        if (loop_flag == 0) {
            printf("Exiting name editor....");
            break;
        }
    }
    // printf("Allocated Memory: %zu\n", _msize(current_name)); // FOR TESTING

    free(current_name);
}

void get_name(char **name) {
    int current_name_length = MIN_BUFFER;
    int i = 0;

    for (;;) {
        int ch = getchar();

        if (i + 1 > current_name_length) {;
            current_name_length++;
            char *temp = (char *) realloc(*name, current_name_length * sizeof(char));

            if (temp == NULL) {
                fprintf(stderr, "Error reallocating memory\n");
                free(name);
                exit(1);
            }

            *name = temp;
        }
        if (ch == '\n') {
            (*name)[i] = '\0';
            break;
        }
        (*name)[i] = (char) ch;
        i++;
    }
}

int calculate_ascii(char **str) {
    int i = 0;
    int total = 0;
    while ((*str)[i]) {
        total += (int) (*str)[i];
        i++;
    }
    return total;
}

int name_editor(char **name) {
    int loop_flag = 1;
    printf("Options (Current name is %s):\n", *name);
    printf("  a. Get ASCII Value of name\n");
    printf("  b. Change Name\n");
    printf("  c. Exit\n");
    char option;
    printf("Option: ");
    scanf(" %c", &option);

    while (getchar() != '\n') {
    } // clear newline, bisa bikin fungsi get_name rusak karena '\n' nya bocor kesana

    switch (option) {
        case 'a':
            printf("Your name's ASCII value is %d\n", calculate_ascii(name));
            break;
        case 'b':
            printf("Enter your new name: ");
            get_name(name);
            break;
        case 'c':
            loop_flag = 0;
            break;
        default:
            printf("Invalid option, please try again\n\n");
    }
    printf("\n");
    return loop_flag;
}
