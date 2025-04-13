#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *history;
    struct node *next;
} node;

void add_node(node **head, char* history);
void print_list(node *head);
void free_list(node *head);
void delete_tail(node **head);
void delete_head(node **head);

int editor(node **head);

int main() {
    node *history_list = NULL;

    for (;;) {
        int loop_flag = editor(&history_list);
        if (loop_flag == 0) {
            break;
        }
    }

    free_list(history_list);
    return 0;
}

void add_node(node **head, char* history) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->history = malloc(strlen(history) + 1);
    strcpy(new_node->history, history);
    new_node->next = *head;
    *head = new_node;
}

void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *temp = current->next;
        free(current->history);
        free(current);
        current = temp;
    }
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("  %s\n", current->history);
        current = current->next;
    }
}

void delete_tail(node **head) {
    if (*head == NULL) {
        printf("List is empty!\n\n");
        return;
    }
    node* second_last = *head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

void delete_head(node **head) {
    if (*head == NULL) {
        printf("List is empty!\n\n");
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


int editor(node **head) {
    printf("History Editor\n");
    printf("  1. Add history\n");
    printf("  2. Delete first history\n");
    printf("  3. Delete last history\n");
    printf("  4. Print all history\n");
    printf("  5. Exit\n");

    int choice = 0;
    printf("Enter your choice: ");
    scanf(" %d", &choice);

    while (getchar() != '\n') {
    }
    switch (choice) {
        case 1:
            char buffer[200];
            printf("Enter New History: ");
            fgets(buffer, 200, stdin);
            buffer[strcspn(buffer, "\r\n")] = 0;
            add_node(head, buffer);
            printf("Succesfully added new history\n\n");
            break;
        case 2:
            printf("Deleting first history entry....\n\n");
            delete_head(head);
            break;
        case 3:
            printf("Deleting last history entry....\n\n");
            delete_tail(head);
            break;
        case 4:
            printf("History:\n");
            print_list(*head);
            printf("\n");
            break;
        case 5:
            printf("Exiting editor........\n\n");
            return 0;
        default:
            printf("Invalid Choice, try again\n\n");
    }
    return 1;
}
