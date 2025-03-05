#include <stdio.h>
#include <stdlib.h>


//Struktur Node pada Singly Linked List
struct Node {
    int data;
    struct Node *next;
    struct Node *prev; //doubly LL
}; //setiap node punya data,pointer next, pointer prev

//Membuat Doubly Linked List dari Array
void Create(int A[], int n) {
    struct Node *t, *last; //pointer t dan last bertipe Node (ada data, ada pointer next)
    int i;
    // Alokasi untuk node pertama
    //first--> |10|NuLL|
    first = (struct Node *) malloc(sizeof(struct Node));
    //Node pertama dialokasikan dan diinisialisasi dengan nilai A[0].
    first->data = A[0];
    //Pointer first->next diset ke NULL
    first->prev = first->next = NULL; //Pointer  diset NULL sebagai penanda akhir dan awal list.
    //variabel last menunjuk ke node pertama
    last = first;

    // Alokasi untuk node berikutnya
    for (i = 1; i < n; i++) {
        //alokasi node t
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        //Node baru dihubungkan:
        //t->prev diset ke node terakhir (last).
        t->prev = last; //doubly LL
        //		/Pointer last->next diupdate agar menunjuk ke node baru.
        last->next = t; //yang membuat antar node terhubung
        //Variabel last diperbarui untuk menunjuk ke node terakhir yang baru saja dibuat.
        last = t;
    }
}

//Menyisipkan Node di Posisi Tertentu
void Insert(int pos, int x) {
    //Node baru t dibuat dan diinisialisasi dengan data x.
    Node *t = new Node; //dalam C++
    //Node *t
    //t = (Node *)malloc(sizeof(Node));//Alokasi node baru
    t->data = x; //doubly LL

    if (pos == 0) {
        // Penyisipan di awal
        t->prev = NULL;
        t->next = first;
        if (first != NULL) {
            first->prev = t;
        }
        first = t; //perbarui first agar menunjuk ke node baru.
    } else {
        // Penyisipan di posisi tertentu
        //Pointer p mulai dari first melakukan iterasi hingga mencapai node sebelum posisi penyisipan (pos-1).
        Node *p = first;
        for (int i = 0; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }
        if (p != NULL) {
            t->next = p->next; //t->next menunjuk ke node yang sebelumnya ditunjuk oleh p->next.
            t->prev = p; //t->prev menunjuk ke node p.
            if (p->next != NULL) {
                p->next->prev = t; //memastikan t terhubung ke setelah p
            } //Mengakses pointer prev dari node setelah p,agar diperbarui untuk menunjuk ke node baru
            p->next = t; //p->next diperbarui agar menunjuk ke node baru (t).
        }
    }
}


//Menghapus Node di Posisi Tertentu
void DeleteAtPos(int pos) {
    //Pointer p mulai dari first untuk traversal.
    //Pointer q diinisialisasi sebagai NULL untuk menyimpan node sebelumnya
    Node *p = first;

    //jika posisi adalah awal
    if (pos == 0 && first != NULL) {
        first = first->next; //first diperbarui menjadi node next-nya
        //khusus doubly
        if (first != NULL) {
            first->prev = NULL;
        }
        free(p); //hapus node pertama
    } else {
        //Lakukan loop hingga mencapai node sebelum posisi yang akan dihapus.
        for (int i = 0; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }
        if (p != NULL) {
            p->prev->next = p->next; //doubly
            if (p->next != NULL) {
                p->next->prev = p->prev;
            }
            free(p); //Hapus node yang direferensikan oleh p
        }
    }
}

int main() {
}
