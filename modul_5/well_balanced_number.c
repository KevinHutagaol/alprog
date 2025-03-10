#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct char_node {
    char data;
    struct char_node *next;
} char_node;

void push(char_node **head, char data);

char pop(char_node **head);

char peek(char_node **head);

void print_stack(char_node *head);

int is_number_well_balanced(char_node *head);

int main() {
    char buffer[256];
    printf("Input: ");
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;

    char_node *stack = NULL;
    // Isi stacknya kebalik biar urutan sama
    for (int i = 0; i < strlen(buffer); i++) {
        push(&stack, buffer[strlen(buffer) - i - 1]);
    }

    // print_stack(stack);
    int is_well_balanced = is_number_well_balanced(stack);
    if (is_well_balanced) {
        printf("Number is well balanced\n");
    }
    return 0;
}

void push(char_node **head, char data) {
    char_node *new_node = (char_node *) malloc(sizeof(char_node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

char pop(char_node **head) {
    if (*head == NULL) {
        printf("Empty stack\n");
        return -1;
    }
    char_node *temp = *head;
    *head = (*head)->next;
    char data = temp->data;
    free(temp);
    return data;
}

char peek(char_node **head) {
    if (*head == NULL) {
        printf("Empty stack\n");
        return -1;
    }
    return (*head)->data;
}

void print_stack(char_node *head) {
    char_node *current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
}

char matching_char(char opening_char) {
    switch (opening_char) {
        case '1': return '9';
        case '2': return '8';
        case '3': return '7';
        case '4': return '6';
        case '5': return '5';
        default: return '\0';
    }
}

int is_number_well_balanced(char_node *head) {
    char_node *temp = NULL;
    char_node *current = head;

    while (current != NULL) {
        char current_char = current->data;
        current = current->next;

        // check if it is an opening char
        // if it is, push to temp stack
        if (current_char == '1' || current_char == '2' || current_char == '3' || current_char == '4') {
            push(&temp, current_char);
            continue;
        }
        // if it is a closing char,
        // compare to top element of temp stack
        if (current_char == '9' || current_char == '8' || current_char == '7' || current_char == '6') {
            // a char is closed before opening
            if (temp == NULL) {
                printf("Output: false\n");
                printf("Not well balanced. Expected opening number but got %c", current_char);
                return 0;
            }
            // closing char do not match the opening one
            char opening_char = peek(&temp);
            char expected_char = matching_char(opening_char);

            if (expected_char == current_char) {
                pop(&temp);
            } else {
                printf("Output: false\n");
                printf("Not well balanced. Mismatch: expected %c, but received %c when closing %c\n", expected_char,
                       current_char, opening_char);
                return 0;
            }
            continue;
        }
        // special case because '5' is both an opening and closing char
        if (current_char == '5') {
            if (temp != NULL && peek(&temp) == '5') {
                pop(&temp);
            } else {
                push(&temp, current_char);
            }
        }
    }
    if (temp != NULL) {
        printf("Output: false\n");
        printf("Not well balanced. Unclosed opening numbers: ");
        print_stack(temp);
        printf("\n");
        return 0;
    }

    printf("Output: true\n");
    return 1;
}
