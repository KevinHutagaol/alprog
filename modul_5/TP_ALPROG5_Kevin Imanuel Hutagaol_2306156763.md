# Tugas Pendahuluan - Linked List, Stack, Queue

```
Nama  : Kevin Imanuel Hutagaol 
NPM   : 2306156763
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Jelaskan apa itu Linked List, jenis-jenis Linked List, dan keuntungan menggunakan Linked List! (15 poin)

---

Linked List adalah struktur data dinamis yang digunakan untuk menyimpan sekumpulan elemen, yang biasa disebut node.
Setiap node biasanya terdiri dari dua bagian:

- Data: Menyimpan informasi atau nilai.
- Pointer/Reference: Menunjuk ke node berikutnya dalam list.

```c++
typedef struct node {
    int data;
    struct node* next;
} node;

```

Dengan adanya pointer ke node selanjutnya, ukuran linked list dapat diubah secara dinamis dengan menghubungkan atau
memutus pointer tersebut

**Jenis Linked List**

- Singly Linked List:

  Setiap node memiliki satu pointer yang menunjuk ke node berikutnya
  ```c++
  typedef struct node {
    int data;
    struct node* next;
  } node;
  ```
  Singly Linked List memiliki implementasi lebih sederhana, tetapi tidak bisa melakukan pergerakan mundur pada list


- Doubly Linked List:

  Setiap node memiliki dua pointer, satu menunjuk ke node berikutnya, dan satu ke node sebelumnya
  ```c++
  typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
  } node;
  ```
  Doubly Linked List memiliki implementasi lebih rumit serta memerlukan lebih banyak memori, tetapi memudahkan
  pergerakan mundur pada list


- Circular Linked List:

  Bentuk dari linked list di mana node terakhir menunjuk kembali ke node pertama, sehingga membentuk lingkaran.

  Circular linked list memudahkan jika implementasi memerlukan sistem yang melingkar

**Kelebihan linked list**

- Ukuran dinamis, dapat mengubah ukuran list dengan memodifikasi pointer yang terdapat
- Penambahan dan Pengurangan elemen dilakukan hanya dengan modifikasi nilai pointer
- Alokasi tidak perlu berurutan seperti array, karena block alokasi saling dihubungkan dengan pointer
- Dapat diimplementasikan menjadi data structure seperti Stack, Queue, dan lainnya.

### Referensi:

- [1] K. N. King, "Linked Lists" in _C programming: a modern approach, Second edition_. New York London:
  W.W. Norton & Company, 2008.
- [2] “Linked List in C,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/linked-list-in-c/ [Accessed: Mar. 09, 2025.]

---

### 2. Jelaskan apa itu Stack, contoh kode Stack, dan keuntungan menggunakan Stack! (15 poin)

Stack merupakan sejenis data structure yang memiliki sistem Last-in-first-out (LIFO) <br>
Elemen yang paling terakhir (terbaru) dimasukan kedalam stack merupakan elemen yang pertama dikeluarkan

**Keuntungan stack**

- Berguna dalam operasi yang sementara, seperti menyimpan state atau history.
- Operasi push dan pop memiliki time complexity O(1) sehingga cepat
- Mudah diimplementasikan dengan data structure seperti linked list

```c++
// struct yang mengimplementasikan stack dengan linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// push yaitu memasukan data kedalam stack
void push(node **head, int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// pop yaitu mengeluarkan data dari stack 
char pop(node **head) {
    if (*head == NULL) {
        printf("Empty stack\n");
        return -1;
    }
    node *temp = *head;
    *head = (*head)->next;
    int data = temp->data;
    free(temp);
    return data;
}
```

### Referensi:

- [3] K. N. King, "Abstract Data Types" in _C programming: a modern approach, Second edition_. New York London:
  W.W. Norton & Company, 2008.
- [4] “Stack Using Linked List in C,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/stack-using-linked-list-in-c/ [Accessed: Mar. 09, 2025.]

---

### 3. Jelaskan apa itu Queue, jenis-jenis Queue, dan keuntungan menggunakan Queue! (15 poin)

Stack merupakan sejenis data structure yang memiliki sistem First-in-first-out (FIFO) <br>
Elemen pertama yang dimasukan ke queue merupakan elemen yang pertama dikeluarkan, seperti sebuah baris

**Keuntungan Queue**

- Berguna dalam mengelola hal yang bersifat berurutan, seperti list dari task
- Mudah diimplementasikan dalam linked list

```c++
// Node queue menggunakan linked list
typedef struct node {
    int number;
    struct node *next;
} node;

// struct queue berisi elemen pertama dan terakhirnya
typedef struct queue {
    node *front;
    node *rear;
} queue;

// inisialisasi queue
queue *create_queue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

// memasukan elemen ke queue
void enqueue(queue *q, int number) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->number = number;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

// mengeluarkan elemen dar queue
int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return 0;
    }

    node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    int number = temp->number;
    free(temp);
    return number;
}
```

### Referensi:

- [5] K. N. King, "Abstract Data Types" in _C programming: a modern approach, Second edition_. New York London:
  W.W. Norton & Company, 2008.
- [6] “Queue - Linked List Implementation,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/queue-linked-list-implementation/ [Accessed: Mar. 09, 2025.]

---

## Programming

### 1. Buatlah program yang dapat mencari 3 angka terbesar menggunakan Linked List! Masukkan dulu angka-angka pada Linked List agar terisi, kemudian implementasikan fungsi untuk mencari 3 angka terbesar. Cantumkan kode program dan screenshot hasil outputnya! (10 poin)

> Untuk mengisi linked list, bebas cara untuk memasukkan angka atau langsung dihardcode juga boleh.

---

```c++
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

```

![Output Program](https://hackmd.io/_uploads/H12gRZsoyg.png)

### 2. Buatlah program yang dapat mencari hasil dari (angka_terbesar + angka_terkecil) / 2 menggunakan Queue! Masukkan dulu angka-angka pada Queue agar terisi, kemudian implementasikan fungsi mencari angka_terbesar dan fungsi lain untuk mencari angka_terkecil. Setelah itu, baru output hasil yang sesuai soal. Cantumkan kode program dan screenshot hasil outputnya! (10 poin)

> Untuk mengisi queue, bebas cara untuk memasukkan angka atau langsung dihardcode juga boleh.

---

```c++
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
    printf("Hello World\n");

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

    printf("Max ; Min ; Middle: %d ; %d ; %.2f\n", max, min, middle);


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

```

![Output Program](https://hackmd.io/_uploads/SymbK1ojyx.png)

### 3. Well-Balanced Numbers (35 poin)

Buatlah program di bawah ini menggunakan Stack. Sebuah sekuens angka disebut *balanced* jika suatu angka 1 diikuti oleh
angka 9, angka 2 diikuti oleh angka 8, angka 3 diikuti oleh angka 7, angka 4 diikuti oleh angka 6, dan angka 5 diikuti
oleh angka 5. **Angka yang mengikuti** harus menutup angka yang diikuti secara berurutan, misal harus "28" dan tidak
bisa "278". "278" tidak dianggap *balanced* karena angka 7 tidak menutup angka 2.

Diberikan sebuah string n, tentukan apakah string tersebut *balanced* atau tidak. Jika *balanced*, kembalikan `true`,
jika tidak, kembalikan `false`. Berikut testcase yang sesuai: **(tidak ada angka 0 pada input)**

#### Example

```plaintext
Input: n = "19192846"
Output: true
Explanation: All the numbers are well-balanced.

Input: n = "123789"
Output: true
Explanation: All the numbers are well-balanced.

Input: n = "146"
Output: false
Explanation: The numbers above are not well-balanced because it doesn't end with 9 to close the 1.

Input: n = "251598"
Output: false
Explanation: The numbers above are not well-balanced because it is closed with 5 first before 9.
```

---

```c++
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

```

![Output Program](https://hackmd.io/_uploads/Sy7WtJssyl.png)