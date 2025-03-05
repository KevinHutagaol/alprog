#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_SIZE 256

typedef struct {
    char name[MAX_STR_SIZE];
    char address[MAX_STR_SIZE];
    char telephone[MAX_STR_SIZE];
    float money_borrowed;
    float interest_rate;
    float money_owned;
} Borrower;

void add_borrower_data(Borrower **borrower_arr, int borrower_index);

void print_borrower_data(Borrower **borrower_arr, int num_borrowers);

int borrower_editor(Borrower **borrower_arr, int num_borrowers);

int main() {
    int num_borrowers;
    printf("Enter Number of borrowers: ");
    scanf("%d", &num_borrowers);
    while (getchar() != '\n') {
    }

    Borrower *borrower_arr = (Borrower *) malloc(num_borrowers * sizeof(Borrower));
    if (borrower_arr == NULL) {
        printf("Memory allocation error\n");
        return -1;
    }

    for (int i = 0; i < num_borrowers; i++) {
        add_borrower_data(&borrower_arr, i);
    }

    for (;;) {
        int loop_flag = borrower_editor(&borrower_arr, num_borrowers);
        if (loop_flag == 0) {
            break;
        }
    }

    free(borrower_arr);
    return 0;
}

void add_borrower_data(Borrower **borrower_arr, int borrower_index) {
    char buffer[MAX_STR_SIZE];
    printf("Enter Borrower %d data:\n", borrower_index);

    printf("  Borrower name %d:  ", borrower_index);
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*borrower_arr)[borrower_index].name, buffer);


    printf("  Borrower address %d: ", borrower_index);
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*borrower_arr)[borrower_index].address, buffer);

    printf("  Borrower phone %d: ", borrower_index);
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*borrower_arr)[borrower_index].telephone, buffer);

    printf("  Money Borrowed %d: ", borrower_index);
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    (*borrower_arr)[borrower_index].money_borrowed = strtof(buffer, NULL);

    printf("  Interest rate %d: ", borrower_index);
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    (*borrower_arr)[borrower_index].interest_rate = strtof(buffer, NULL);

    (*borrower_arr)[borrower_index].money_owned =
            (*borrower_arr)[borrower_index].money_borrowed * (1.0f + (*borrower_arr)[borrower_index].interest_rate);
}

void print_borrower_data(Borrower **borrower_arr, int num_borrowers) {
    printf("Data of borrowers:\n");
    printf("----------------\n");
    if (num_borrowers == 0) {
        printf("You do not have any borrowers\n\n");
        return;
    }
    for (int i = 0; i < num_borrowers; i++) {
        printf("Borrower %d\n", i);
        printf("Name - Address: %s - %s\n", (*borrower_arr)[i].name, (*borrower_arr)[i].address);
        printf("Telp: %s\n", (*borrower_arr)[i].telephone);
        printf("Borrowed Money - Interest rate: %.2f - %.2f%%\n", (*borrower_arr)[i].money_borrowed,
               (*borrower_arr)[i].interest_rate * 100.0);
        printf("Money Owned: %f\n", (*borrower_arr)[i].money_owned);
        printf("\n");
    }
}

int borrower_editor(Borrower **borrower_arr, int num_borrowers) {
    printf("----------------\n");
    printf("Borrower Database\n");
    printf("----------------\n");
    printf("  a. Count all owend money\n");
    printf("  b. Add 500k to all owend money\n");
    printf("  c. Subtract 500k to all owend money\n");
    printf("  d. Exit Editor\n");

    int choice = 0;
    printf("Enter option: ");
    scanf(" %c", &choice);

    while (getchar() != '\n') {
    }

    switch (choice) {
        case 'a':
            float total = 0;
            for (int i = 0; i < num_borrowers; i++) {
                total += (*borrower_arr)[i].money_owned;
            }
            printf("Total money owend to you: %.2f\n", total);
            print_borrower_data(borrower_arr, num_borrowers);
            break;
        case 'b':
            printf("Adding 500.000 to all borrowers\n");
            for (int i = 0; i < num_borrowers; i++) {
                (*borrower_arr)[i].money_owned += 500000.0f;
            }
            print_borrower_data(borrower_arr, num_borrowers);
            break;
        case 'c':
            printf("Subtracting 500.000 to all borrowers\n");
            for (int i = 0; i < num_borrowers; i++) {
                (*borrower_arr)[i].money_owned -= 500000.0f;
            }
            print_borrower_data(borrower_arr, num_borrowers);
            break;
        case 'd':
            printf("Exiting editor........\n\n");
            return 0;
        default:
            printf("Invalid Choice, try again\n\n");
    }

    return 1;
}
