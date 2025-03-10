#include <stdio.h>
#include <stdlib.h>

typedef struct number_node {
    int number;
    struct number_node *next;
} number_node;

typedef struct queue {
    number_node *front;
    number_node *rear;
} queue;

void enqueue(queue *q, int number);

int dequeue(queue *q);

queue *create_queue();

void destroy_queue(queue *q);

void print_queue(queue *q);

int max_num(queue *q);

int min_num(queue *q);

int main() {
    int numbers[20] = {-15, 42, -7, 99, -3, 27, -86, 54, 12, -68, 30, 45, -9, 77, -22, 61, 34, -11, 80, -56};

    queue *q = create_queue();

    for (int i = 0; i < 20; i++) {
        enqueue(q, numbers[i]);
    }
    printf("Queue is: ");
    print_queue(q);
    printf("\n");

    int max = max_num(q);
    int min = min_num(q);
    float middle = (float) (max + min) / 2.0f;

    printf("Max, Min, Middle =  %d, %d, %.2f\n", max, min, middle);


    destroy_queue(q);
    return 0;
}

queue *create_queue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue *q, int number) {
    number_node *new_node = (number_node *) malloc(sizeof(number_node));
    new_node->number = number;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}


int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return 0;
    }

    number_node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    int number = temp->number;
    free(temp);
    return number;
}

void destroy_queue(queue *q) {
    if (q->front == NULL) {
        free(q);
        return;
    }

    number_node *current = q->front;
    while (current != NULL) {
        number_node *temp = current->next;
        free(current);
        current = temp;
    }

    free(q);
}

void print_queue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    }

    number_node *current = q->front;
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
}

int max_num(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return 0;
    }
    int largest = INT_MIN;
    number_node *current = q->front;
    while (current != NULL) {
        if (current->number > largest) {
            largest = current->number;
        }
        current = current->next;
    }
    return largest;
}

int min_num(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return 0;
    }
    int smallest = INT_MAX;
    number_node *current = q->front;
    while (current != NULL) {
        if (current->number < smallest) {
            smallest = current->number;
        }
        current = current->next;
    }
    return smallest;
}
