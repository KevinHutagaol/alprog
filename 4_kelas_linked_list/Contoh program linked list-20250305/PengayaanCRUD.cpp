// File: main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Node
typedef struct User {
    int id;
    char name[50];
    struct User *next;
} User;

// Fungsi untuk menambah pengguna (addUser)
void addUser(User **head, int id, char *name) {
    User *newUser = (User *) malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);
    newUser->next = *head;
    *head = newUser;
}

// Fungsi untuk menyisipkan pengguna (insertUser)
void insertUser(User **head, int position, int id, char *name) {
    User *newUser = (User *) malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);

    if (position == 0) {
        newUser->next = *head;
        *head = newUser;
        return;
    }

    User *temp = *head;
    for (int i = 0; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    if (temp) {
        newUser->next = temp->next;
        temp->next = newUser;
    }
}

// Fungsi untuk mengedit pengguna (editUser)
void editUser(User *head, int id, char *newName) {
    while (head && head->id != id) {
        head = head->next;
    }
    if (head) {
        strcpy(head->name, newName);
    }
}

// Fungsi untuk menghapus pengguna (deleteUser)
void deleteUser(User **head, int id) {
    User *temp = *head, *prev = NULL;
    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp) {
        if (prev) {
            prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        free(temp);
    }
}

// Fungsi untuk menampilkan daftar pengguna
void displayUsers(User *head) {
    printf("Current Users:\n");
    while (head) {
        printf("ID: %d, Name: %s\n", head->id, head->name);
        head = head->next;
    }
}

int main() {
    User *head = NULL;

    // Tambah beberapa pengguna
    addUser(&head, 1, "Alice");
    addUser(&head, 2, "Bob");
    addUser(&head, 3, "Charlie");

    // Tampilkan daftar pengguna
    displayUsers(head);
    // Sisipkan pengguna di posisi tertentu
    insertUser(&head, 1, 4, "Diana");
    printf("\nSetelah Penyisipan:\n");
    displayUsers(head);

    // Edit pengguna dengan ID tertentu
    editUser(head, 2, "Robert");
    printf("\nSetelah Pengeditan:\n");
    displayUsers(head);
    // Hapus pengguna dengan ID tertentu
    deleteUser(&head, 3);
    printf("\nSetelah Penghapusan:\n");
    displayUsers(head);

    return 0;
}
