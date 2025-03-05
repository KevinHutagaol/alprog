#include <stdio.h>
#include <stdlib.h>

//Struktur Node pada Singly Linked List
struct Node {
    int data;
    struct Node *next;
}; //Setiap node punya data dan pointer yang menunjuk ke node berikutnya.

//Membuat Singly Linked List dari Array
void Create(int A[], int n) {
    struct Node *t, *last; //pointer t dan last bertipe Node (ada data, ada pointer next)
    int i;
    // Alokasi untuk node pertama
    //first--> |10|NuLL|
    first = (struct Node *) malloc(sizeof(struct Node));
    //Node pertama dialokasikan dan diinisialisasi dengan nilai A[0].
    first->data = A[0];
    //Pointer first->next diset ke NULL
    first->next = NULL; //Pointer di node terakhir diset NULL sebagai penanda akhir list.
    //variabel last menunjuk ke node pertama
    last = first;

    // Alokasi untuk node berikutnya
    for (i = 1; i < n; i++) {
        //alokasi node t
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        //		/Pointer last->next diupdate agar menunjuk ke node baru.
        last->next = t; //yang membuat antar node terhubung
        //Variabel last diperbarui untuk menunjuk ke node terakhir yang baru saja dibuat.
        last = t;
    }
}

//Menampilkan isi Node dari Linked List
void Display(struct Node *p) {
    //menerima pointer p yang menunjuk ke node pertama (head).
    while (p != NULL) {
        //Selama p tidak NULL,
        printf("%d ", p->data); // nilai p->data dicetak.
        p = p->next; //Pointer p diperbarui untuk berpindah ke node berikutnya.
    }
}

//Menyisipkan Node di Posisi Tertentu
void Insert(int pos, int x) {
    Node *t, *p;
    if (pos == 0) {
        t = (Node *) malloc(sizeof(Node)); //Alokasi node baru
        t->data = x; //inisialisasikan data-nya dengan x.
        t->next = first; //Set t->next ke node pertama (sebelumnya ditunjuk oleh first).
        //line di atas yang menghubungkan node t dengan node first yang lama
        first = t; //perbarui first agar menunjuk ke node baru.
    } else if (pos > 0) {
        //Inisialisasi pointer p ke first dan traversal hingga mencapai node pada posisi pos-1.
        p = first;
        for (int i = 0; i < pos - 1 && p; i++) {
            p = p->next;
        }
        //Alokasikan node baru dan inisialisasi dengan data x.
        t = (Node *) malloc(sizeof(Node));
        t->data = x;
        //Set t->next agar disambung ke tujuan p->next
        t->next = p->next;
        //p->next (yang lama) disambung ke node baru t
        p->next = t;
    }
}

//Menghapus Node di Posisi Tertentu
void DeleteAtPos(int pos) {
    //Pointer p mulai dari first untuk traversal.
    //Pointer q diinisialisasi sebagai NULL untuk menyimpan node sebelumnya
    Node *p = first, *q = NULL;
    if (pos == 0 && first) {
        first = first->next; //first diperbarui menjadi node next-nya
        free(p); //hapus node pertama
    } else {
        //Lakukan loop hingga mencapai node sebelum posisi yang akan dihapus.
        for (int i = 0; i < pos - 1 && p; i++) {
            q = p;
            p = p->next;
        }
        if (p) {
            q->next = p->next; //Perbarui q->next dengan p->next untuk melewati node yang dihapus.
            free(p); //Hapus node yang direferensikan oleh p
        }
    }
}

int main() {
}
