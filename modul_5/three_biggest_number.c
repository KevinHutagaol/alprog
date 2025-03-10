#include <stdio.h>
#include <stdlib.h>

typedef struct number_node {
    int number;
    struct number_node *next;
} number_node;

void add_node(number_node **head, int number);

void add_tail(number_node **head, int number);

void free_list(number_node *head);

void trim_list(number_node **head, int n);

void print_list(number_node *head);

void insert_before(number_node **head, number_node *current, int number);

void find_n_biggest_number(number_node *head, int n, number_node **head_big_num);


int main() {
    const int number[10] = {1, -2, 33, 4, 15, 6, 27, 68, 9, 20};

    number_node *list = NULL;
    for (int i = 0; i < 10; i++) {
        add_node(&list, number[i]);
    }

    number_node *biggest_numbers = NULL;
    find_n_biggest_number(list, 3, &biggest_numbers);
    printf("List is: ");
    print_list(list);
    printf("\n");
    printf("The %d biggest numbers are: ", 3);

    print_list(biggest_numbers);

    free_list(list);
    free_list(biggest_numbers);

    return 0;
}

void add_node(number_node **head, const int number) {
    number_node *new_node = (number_node *) malloc(sizeof(number_node));
    new_node->number = number;
    new_node->next = *head;
    *head = new_node;
}

void add_tail(number_node **head, const int number) {
    number_node *new_node = (number_node *) malloc(sizeof(number_node));
    new_node->number = number;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    number_node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void free_list(number_node *head) {
    number_node *current = head;
    while (current != NULL) {
        number_node *temp = current->next;
        free(current);
        current = temp;
    }
}

void trim_list(number_node **head, int n) {
    if (head == NULL) {
        return;
    }

    if (n < 1) {
        free_list(*head);
        *head = NULL;
        return;
    }

    number_node *current = *head;
    int count = 1; // head counts as 1 element

    while (current != NULL && count < n) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        number_node *temp = current->next;
        current->next = NULL;

        free_list(temp);
    }
}


void print_list(number_node *head) {
    number_node *current = head;
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
}

void insert_before(number_node **head, number_node *current, const int number) {
    number_node *new_node = (number_node *) malloc(sizeof(number_node));
    new_node->number = number;

    if (*head == current) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // traversing to find element
    number_node *prev = *head;
    while (prev != NULL && prev->next != current) {
        prev = prev->next;
    }

    if (prev == NULL) {
        fprintf(stderr, "Node not found");
        return;
    }

    prev->next = new_node;
    new_node->next = current;
}

void find_n_biggest_number(number_node *head, int n, number_node **head_big_num) {
    if (head == NULL) {
        return;
    }

    add_node(head_big_num, head->number);
    number_node *current = head->next;

    // wierd implementation of insertion sort
    while (current != NULL) {
        number_node *cur_big_num_node = *head_big_num;
        while (cur_big_num_node != NULL) {
            if (current->number > cur_big_num_node->number) {
                insert_before(head_big_num, cur_big_num_node, current->number);
                break;
            }
            cur_big_num_node = cur_big_num_node->next;
        }
        // if num is smallest, add to tail (end)
        if (cur_big_num_node == NULL) {
            add_tail(head_big_num, current->number);
        }

        current = current->next;
    }
    trim_list(head_big_num, n);
}
