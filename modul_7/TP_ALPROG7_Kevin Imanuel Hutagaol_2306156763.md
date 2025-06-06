# Tugas Pendahuluan 7 - Sorting

```txt
Nama  : Kevin Imanuel Hutagaol 
NPM   : 2306156763
```

> Catatan: Soal Programming tidak perlu mencantumkan referensi, hanya soal Teori saja yang memerlukan referensi minimal

## Teori

### 1. Pilih dua dari algoritma sorting berikut: Bubble Sort, Selection Sort, Insertion Sort, dan jelaskan cara kerjanya! Juga, jelaskan perbedaan di antara mereka! (15 poin)

### Bubble Sort:

--- 

Bubble sort mengiterasikan dua buah elemen berurutan pada array dan membaliknya jika urutannya tidak benar.

- Bubble sort mengcompare setiap elemen dengan semua elemen setelahnya, sehingga dibutuhkan double for loop.

- Jika semua elemen telah dicompare dan di tukar, maka array akan terurut.

**Time complexity:**

$$ \begin{align}
\text{Worst Case} &: O(n^2) \\
\text{Best Case} &: O(n) \\
\text{Average Case} &: O(n^2) \\
\end{align}
$$

![bubble-sort](https://hackmd.io/_uploads/BJa43W9C1g.png)

### Selection Sort:

Selection sort merupakan algoritma yang memilih elemen terkecil dari array dan meletakannya di awal array:

- Elemen pertama merupakan minimum
- Bandingkan minimum dengan elemen setelahnya, jika lebih kecil, maka elemen tersebut menjadi minimum baru.
- Lanjutkan perbandingan elemen minimum dengan elemen setelahnya.
- Setelah semua nilai telah di cek, pindah nilai minium ke awal array
- Lakukan hingga semua elemen telah tersortir, iterasi selanjutnya tidak menghitung elemen yang sebelumnya sudah
  diurutkan

![Selection Sort](https://hackmd.io/_uploads/SJiSAb90Jg.png)

**Time complexity:**

$$ \begin{align}
\text{Worst Case} &: O(n^2) \\
\text{Best Case} &: O(n^2) \\
\text{Average Case} &: O(n^2) \\
\end{align}
$$

#### Referensi

- [1] “Bubble Sort (With Code in Python/C++/Java/C).”  [Online].
  Available: https://www.programiz.com/dsa/bubble-sort [Accessed: Apr. 14, 2025]
- [2] “Selection Sort (With Code in Python/C++/Java/C).” [Online].
  Available: https://www.programiz.com/dsa/selection-sort [Accessed: Apr. 14, 2025]
- [3] A. M. Tenenbaum, Y. Langsam, and M. Augenstein, "Sorting" in _Data structures using C_. Englewood Cliffs, N.J:
  Prentice Hall, 1990.

---

### 2. Pilih salah satu dari algoritma sorting berikut: Quick Sort, Merge Sort, dan jelaskan cara kerjanya! Juga, jelaskan perbedaan algoritma ini dengan algoritma sorting pada soal nomor 1! (12 poin)

### Quick Sort:

- Algoritmaa quick sort merupakan alogoritma yang mengunakan metode _divide and conquer_ secara rekursif untuk melakukan
  sorting.

- Algoritma ini pertama memilih sebuah _pivot_ dengan tujuan untuk membagi dua array. Pivot akan diletakan sedemikian
  rupa
  agar semua nilai disebelah kiri pivot akan bernilai lebih kecil dari pivot, dan semua nilai yang disebelah kanan pivot
  bernilai lebih besar dari pivot.

- Proses ini akan dilakukan secara recursif untuk tiap bagian kiri dan kanan pivot, hingga tidak dapat dibagi lagi (sisa
  hanya pivotnya). Setelah hal ini terjadi maka array sudah akan terurut.

Sistem divide and conquer dari quick sort:
![quicksort](https://hackmd.io/_uploads/ryRGJ-90Jx.png)

**Time complexity:**

#### Pembagian array dilakukan seperti berikut:

- Pivot akan dicompare dengan elemen pertama di array. Jika elemen tersebut lebih besar dari pivot, maka akan di set
  sebagai temp.

- Pivot lalu akan dicompare dengan elemen setelahnya di array. Jika elemen tersebut lebih kecil dari pivot, maka akan di
  swap dengan temp.

- Proses ini dilakukan hingga mencapai pivot, dimana pivot akan ditukar dengan temp variabel tersebut.

$$ \begin{align}
\text{Worst Case} &: O(n^2) \\
\text{Best Case} &: O(n\log(n)) \\
\text{Average Case} &: O(n\log(n)) \\
\end{align}
$$

#### Referensi

- [4] “QuickSort (With Code in Python/C++/Java/C).” [Online].
  Available: https://www.programiz.com/dsa/quick-sort [Accessed: Apr. 14, 2025]
- [5] A. M. Tenenbaum, Y. Langsam, and M. Augenstein, "Sorting" in _Data structures using C_. Englewood Cliffs, N.J:
  Prentice Hall, 1990.

---

### 3. Jelaskan secara singkat algoritma sorting selain yang disebutkan pada pertanyaan sebelumnya! (10 poin)

Radix sort merupakan algoritma yang mengelompokan elemen dari digit yang berada di posisi yang sama, lalu mengurutkan
elemen-elemen tersebut.

- Tentukan nilai terbesar dari array, dan ditentukan jumlah digit dari nilai max tersebut (N).
- Dimulai dari digit terbesar (N), akan digunakan algoritma sorting stable lainnya untuk mengurutkan elemen.
- Setelah itu diurutkan elemen di digit sebelumnya, hingga ke digit satuan.

#### Referensi

- [6] “Radix Sort (With Code in Python, C++, Java and C).”  [Online].
  Available: https://www.programiz.com/dsa/radix-sort [Accessed: Apr. 14, 2025]
- [7] A. M. Tenenbaum, Y. Langsam, and M. Augenstein, "Sorting" in _Data structures using C_. Englewood Cliffs, N.J:
  Prentice Hall, 1990.

---

### 4. Jelaskan cara mengurutkan array angka dalam urutan naik dan turun dalam C (12 poin)

Algoritma sorting akan selalu bergantung pada komparasi nilai untuk menentukan elemen mana yang berada di depan atau
dibelakang, dalam sorting array angka, fungsi ini sekedar operator ($>$) dan ($<$). Jika pada algoritma sorting yang
akan mensort secara naik menggunakan $>$ sebagai comparasinya, maka $<$ akan menandakan sort turun. 

```c++
void bubble_sort_ascending(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
    // Komparasi antara nilai yang menghasilkan ascending
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void bubble_sort_descending(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
    // Komparasi antara nilai yang menghasilkan descending
      if (array[i] < array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
```

#### Referensi

- [8] “Bubble Sort (With Code in Python/C++/Java/C).”  [Online].
  Available: https://www.programiz.com/dsa/bubble-sort [Accessed: Apr. 14, 2025]
- [9] A. M. Tenenbaum, Y. Langsam, and M. Augenstein, "Sorting" in _Data structures using C_. Englewood Cliffs, N.J:
  Prentice Hall, 1990.

---

### 5. Jelaskan cara mengurutkan array struct berdasarkan field tertentu (bisa berupa integer atau string) (11 poin)

Algoritma sorting pada dasarnya bergantung pada komparasi antara dua nilai, yang diperlukan untuk menentukan nilai mana
yang diawal dan diakhir.

Sebuah struct tidak dapat dikomparasikan secara langsung seperti int / string, dapat dibuat sebuah helper function yang
fungsinya untuk menentukan struct mana yang akan memiliki urutan lebih dahulu. Sebagai contoh struct `PlayerRank` dapat
dicompare melalui helper function berikut

```c++
typedef struct PlayerRank {
    char rank_name[100];
    int value;
} PlayerRank;

int get_rank_value(const char *rank) {
    if (strcmp(rank, "bronze") == 0) return 0;
    if (strcmp(rank, "silver") == 0) return 1;
    if (strcmp(rank, "gold") == 0) return 2;
    if (strcmp(rank, "diamond") == 0) return 3;
    return -1;
}

int compare_player_rank(const PlayerRank *rank1, const PlayerRank *rank2) {
    // ascending
    if (get_rank_value(rank1->rank_name) > get_rank_value(rank2->rank_name)) return 1;
    if (get_rank_value(rank1->rank_name) < get_rank_value(rank2->rank_name)) return -1;

    // descending
    if (rank1->value > rank2->value) return -1;
    if (rank1->value < rank2->value) return 1;

    return 0;
}
```

fungsi `compare_player_rank` tersebut mengkomparasikan 2 buah instance dari PlayerRank dan menentukan yang mana yang
nilainya lebih tinggi (dilihat dari return valuenya -1, 0, atau 1).

Fungsi dapat menggantikan komparasi yang ada di dalam sort function sehingga fungsi dapat mengurutkan array of structs.

```c++
void bubble_sort(PlayerRank array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      // helper function digunakan disini
      if (compare_player_rank(&array[i], &array[i+1]) > 0) { 
        PlayerRank temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
```

Dapat juga digunakan function signature yang menerima sebuah callback function dalam bentuk function pointer, sehingga
kita tidak perlu mendefinisikan function baru untuk setiap pengubahan ketentuan pengurutan. Dengan metode ini diperlukan
juga perubahan signatur fungsi menjadi void pointer yang menandakan fungsi sorting kita tidak perlu mengetahui tipe data
yang akan di sort, hanya mengetahui besar dari struct (diberikan kepada fungsi).

```c++
void bubble_sort_generic(void *array, size_t member_size, int array_size, int (*compare)(const void *, const void *)) {
    for (int step = 0; step < array_size - 1; ++step) {
        for (int i = 0; i < array_size - step - 1; ++i) {
            void *arr1 = &array[i * member_size];
            void *arr2 = &array[(i + 1) * member_size];
            // fungsi compare berasal dari luar function ini (parameter)
            if (compare(arr1, arr2) > 0) {
                // memcpy untuk swap karena menggunakan void pointer
                char temp[member_size];
                memcpy(temp, arr2, member_size);
                memcpy(arr2, arr1, member_size);
                memcpy(arr1, temp, member_size);
            }
        }
    }
}

// mengcall fungsi :

PlayerRank players[] = {
    // snip
};
int member_size = sizeof(players[0]);
int array_size =  sizeof(players) / sizeof(players[0]);

bubble_sort_generic(players, member_size, array_size, compare_player_rank);
```

#### Referensi

- [10] “Bubble Sort (With Code in Python/C++/Java/C).”  [Online].
  Available: https://www.programiz.com/dsa/bubble-sort [Accessed: Apr. 14, 2025]
- [11] A. M. Tenenbaum, Y. Langsam, and M. Augenstein, "Sorting" in _Data structures using C_. Englewood Cliffs, N.J:
  Prentice Hall, 1990.

---

## Pemrograman (40 poin)

> Masukkan screenshot layar output kode Anda di tempat yang disediakan.

### Mengurutkan Struct dengan Urutan String Custom

Sebuah objek berisi string dan integer. Anda perlu mengurutkan objek berdasarkan string dalam urutan naik. Jika string
sama, maka urutkan berdasarkan integer dalam urutan turun.

Sebagai contoh, array objek adalah:

```c
struct Object {
    char string[100];
    int number;
};

---

struct Object objects[] = {
    {"one", 4},
    {"two", 3},
    {"one", 2},
    {"three", 1},
    {"two", 5},
    {"three", 6}
    {"four", 1}
};
```

> Jika kita mengurutkan string secara alfabetis, kita mendapatkan: `four, one, three, two`. Kita ingin mengurutkan
> string `one, two, three, four`, jadi kode Anda perlu mengurutkan objek berdasarkan urutan string custom.

Output yang diharapkan adalah:

```c
one 4
one 2
two 5
two 3
three 6
three 1
four 1
```

> **Catatan:** ubah `object` ke nama lain yang menurut Anda lebih sesuai, juga ubah string dan integer ke nama yang
> tepat, dan ubah urutan string custom agar sesuai dengan kasus spesifik Anda.
> Sebagai contoh `one, two, three, four` dapat diubah menjadi `apple, banana, cherry, date` dan Objects dapat diubah
> menjadi `Fruits`, dll. Jangan lupa untuk mengubah nama struct dan nama variabel.

---

### Jawaban Anda

```c++
#include <stdio.h>
#include <string.h>

typedef struct PlayerRank {
    char rank_name[100];
    int value;
} PlayerRank;

void display_player_ranks(PlayerRank *playerRank, size_t array_size);

int get_rank_value(const char *rank);

int compare_player_rank(const PlayerRank *rank1, const PlayerRank *rank2);

void swap(void *x, void *y, size_t size);

void quick_sort(void *arr, size_t member_size, int array_size, int (*compare)(const void *, const void *));

void quick_sort_internal(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *));

int partition(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *));

int main() {
    PlayerRank players[] = {
        {"bronze", 2},
        {"diamond", 2},
        {"bronze", 1},
        {"gold", 2},
        {"gold", 3},
        {"silver", 1}
    };

    int member_size = sizeof(players[0]);
    int array_size =  sizeof(players) / sizeof(players[0]);

    display_player_ranks(players, array_size);

    quick_sort(players, member_size, array_size, compare_player_rank);

    printf("\nSorted Ranks:\n");

    display_player_ranks(players, array_size);
}

void display_player_ranks(PlayerRank *playerRank, size_t array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d. Rank: %s %d\n", i + 1, playerRank[i].rank_name, playerRank[i].value);
    }
}

int get_rank_value(const char *rank) {
    if (strcmp(rank, "bronze") == 0) return 0;
    if (strcmp(rank, "silver") == 0) return 1;
    if (strcmp(rank, "gold") == 0) return 2;
    if (strcmp(rank, "diamond") == 0) return 3;
    return -1;
}

int compare_player_rank(const PlayerRank *rank1, const PlayerRank *rank2) {
    // ascending
    if (get_rank_value(rank1->rank_name) > get_rank_value(rank2->rank_name)) return 1;
    if (get_rank_value(rank1->rank_name) < get_rank_value(rank2->rank_name)) return -1;

    // descending
    if (rank1->value > rank2->value) return -1;
    if (rank1->value < rank2->value) return 1;

    return 0;
}

void swap(void *x, void *y, size_t size) {
    char temp[size];
    memcpy(temp, y, size);
    memcpy(y, x, size);
    memcpy(x, temp, size);
}

void quick_sort(void *arr, size_t member_size, int array_size, int (*compare)(const void *, const void *)) {
    quick_sort_internal(arr, member_size, 0, array_size - 1, compare);
}

void quick_sort_internal(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *)) {
    if (low < high) {
        int pivot_index = partition(arr, member_size, low, high, compare);

        quick_sort_internal(arr, member_size, low, pivot_index - 1, compare);
        quick_sort_internal(arr, member_size, pivot_index + 1, high, compare);
    }
}

int partition(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *)) {
    void *pivot = arr + high * member_size;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr + (j * member_size), pivot) < 0) {
            i++;
            swap(arr + i * member_size, arr + j * member_size, member_size);
        }
    }

    swap(arr + (i + 1) * member_size, arr + high * member_size, member_size);

    return i + 1;
}

```

![Output Program](https://hackmd.io/_uploads/SJaVNFtRyx.png)
