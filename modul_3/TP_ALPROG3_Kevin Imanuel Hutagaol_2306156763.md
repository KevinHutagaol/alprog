# Tugas Pendahuluan Modul 3 - Pointer

```latex
Nama  : Kevin Imanuel Hutagaol
NPM   : 2306156763
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 1.

## Teori

### 1. Apa itu tipe data pointer? Bagaimana cara kita mendeklarasikannya, dan bagaimana cara kita mengambil nilai dari sebuah variabel yang alamatnya ditunjuk oleh pointer? (15 poin)

---

**Pointer**

Sebuah pointer menyimpan memory address dari variabel atau konstatnta. Setiap data type baik primitif maupun derived
dapat memiliki sebuah pointer yang menyimpan memory address sebuah instance dari type tersebut.

- Pointer dapat dideklarasikan dengan operator `*`

  ```c++
  int *angka; // sebuah pointer yang menyimpan memory address sebuah int
  ```

- Pointer dapat diinisialisasikan dengan memberikan address sebuah variabel untuk disimpan dalam pointer tersebut.

  ```c++
  int i, j;
  // menginisialisasi pi ke memory address dari i
  int *pi = &i; 
  // mengassign pi ke memory addres dari j, perhatikan kalo `*` tidak digunakan setelah deklarasi
  pi = &j;
  ```

  Pointer yang tidak diinisialisasikan akan menyimpan address yang menuju tempat tidak tentu sehingga menyebabkan
  undefined behavior dan dapat menyebabkan error.


- Nilai yang ditunjuk oleh pointer dapat kita akses dengan menggunakan indirection operator, (*), pada sebuah variabel
  pointer

  ```c++
  printf("%d", *pi); 
  // pi merupakan pointer ke i, sehingga *pi adalah nilai i itu sendiri 
  
  *pi = (*pi)*2;
  // Nilai i akan dikali dua secara reference, melalui pointer pi 
  ```

- Pointer dapat menyimpan address sebuah struct:

  ```c++
  struct buah { 
      int harga;
      float berat;
  };
  
  struct buah mangga = { 10000, 1.2 };
  // menginisialisasikan pointer pbuah ke memory address dari mangga
  struct buah *pbuah = &mangga; 
  ```

- Member dari sebuah struct dapat diakses dengan notasi `->`

  ```c++
  pbuah->harga = 15000; 
  pbuah->berat = 2.0; 
  ```

### Referensi:

- [1] "Data Types" The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Data-Types [Accessed: Feb. 22, 2025]
- [2] B. W. Kernighan and D. M. Ritchie, "Types, Operators and Expressions", in *The C programming language*, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.
- [3] "Data Types in C" GeeksforGeeks.  [Online].
  Available: https://www.geeksforgeeks.org/data-types-in-c/ [Accessed: Feb. 22, 2025]

---

### 2. Dalam C, kita bisa menjalankan fungsi by reference dan by value. Jelaskan perbedaannya! (10 poin)

pass-by-value dan pass-by-reference merupakan dua cara yang berbeda untuk memberikan sebuah parameter kepada fungsi:

- Pass-by-value:

  Nilai yang diberikan kepada parameter fungsi merupakan sebuah copy dari nilai yang diberikan:

  ```c++
  #include <stdio.h>
  
  int calculate(int num) {
    // nilai num tidak berubah
    int result = 2 * num;
    // return nilai baru yang dihitung dari num
    return result;
  }
  
  int main() {
    int num1 = 5;
    // pass by value
    int num2 = calculate(num1);
    printf("%d", num2);
  }
  ```

  Contoh diatas merupakan metode pass-by-value, nilai `num1` yang diberikan kepada fungsi tidak berubah, melainkan
  terdapat nilai baru `num2` yang akan di assign kepada return value dari fungsi `calculate`

  ---

- Pass-by-reference:

  Merupakan metode dimana variabel yang diberikan akan dimanipulasi secara langsung, hal ini dapat dilakukan dengan
  pointers dalam `c`.

  Dengan memberikan alamat memori dari value kepada parameter fungsi, fungsi tersebut dapat memodifikasi value secara
  langsung

  ```c++
  #include <stdio.h>
  
  void calculate(int *num) {
    // nilai num akan berubah secara langsung
    *num = 2 * (*num);
  }
  
  int main() {
    int num1 = 5;
    // pass by refrence
    calculate(&num1);
    printf("%d", num1);
  } 

  ```

    - Fungsi sekarang me*return* `void`, karena nilai dimanipulasi secara langsung
    - Contoh diatas merupakan metode pass-by-referece, fungsi calculate sekarang memiliki parameter yaitu `int *num`,
      yang
      artinya num merupkanan sebuah `pointer` yang menunjuk ke alamat sebuah `int`
    - Pparameter fungsi yang diberikan merupakan `&num1` yang artinya alamat memori kepada variabel `num1`
    - Didalam fungsi, nilai `*num` menandakan sebuah dereference yang berarti melihat nilai dari value yang terdapat
      pada pointer `num`. Memodifikasi nilai ini akan memodifikasi nilai `num1`, yaitu address yang diberikan kepada
      parameter `num`

> Perlu diperhatikan kalau pass-by-reference merupakan satu satunya cara untuk memberikan sebuah array kedalam
> sebuah fungsi.
>
> Hal ini dikarenakan fungsi yang menerima sebuah array sebagai parameternya akan secara langsung
> mendekomposisi array tersebut menjadi pointer kepada elemen pertamanya

[your answer here]

### Referensi:

- [4] “Program Structure and Scope” The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Program-Structure-and-Scope [Accessed: Feb. 22, 2025]
- [5] B. W. Kernighan and D. M. Ritchie, "Pointers and Function Arguments" in _The C programming language_, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.
- [6] “Pass By Reference In C,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/pass-by-reference-in-c/ [Accessed: Feb. 22, 2025]

---

### 3. Salah satu metode paling umum membuat array dengan size fleksibel/dinamis adalah dengan malloc/calloc. Apakah command-command tersebut? Bagaimana cara pakainya? (15 poin)

`(Note: Setelah selesai memakai malloc/calloc, memori harus dibebaskan (menggunakan free()). Tidak perlu dijelaskan di jawaban, namun penting untuk diingat`

Dalam C, panjang sebuah data structure adalah konstan, hal ini menjadi masalah ketika ingin menggunakan data yang
dinamis dimana ukurannya dapat tak tentu. Sehingga dibutuhkan fungsi yang dapat mengalokasikan memori kesebuah data
structure secara dinamis.

`malloc, calloc, serta realloc` merupakan fungsi yang terdapat di `<stdlib.h>`, ketiga fungsi tersebut berguna dalam
mengalokasikan memori secara dinamis:

- `malloc` mengalokasi sebuah block memori tanpa menginisialisasinya
- `calloc` mengalokasi sebuah block memori serta menginisialisasinya
- `realloc` merubah ukuran dari block memori yang sebelumnya telah dialokasikan

Ketiga fungsi tersebut akan menghasilkan void pointer `(void*)`, hal ini karena program tidak mengetahui data type apa
yang diasosiasikan kepada alokasi tersebut, sehinga dibutuhkan casting, baik secara implisit maupun eksplisit

```c++
void *malloc(size_t size);

void *calloc(size_t nmemb, size_t size);

void *realloc(void *ptr, size_t size);
```

contoh penggunaan malloc:

```c++
int n = NILAI_DINAMIS;

int *a;
a = (int*) malloc(n * sizeof(int));
```

Pada contoh berikut, variabel `a` merupakan pointer ke `int`, implementasi disini merupakan untuk sebuah array dari int,
dimana `a` merupakan pointer ke nilai pertama di array tersebut. Array tersebut berukuran dinamis, sehingga dialokasikan
memori sebesar `n` (jumlah elemen di array) * `sizeof(int)` besar memori yang digunakan sebuah `int`

Memori yang dialokasikan akan disimpan di lokasi memori heap, jika terlalu banyak memori dialokasiakn, maka heap dapat
penuh, sehingga menyebabkan program yang inefisien atau sifat yang undefined.

Sebuah pointer juga dapat terlewat maupun keluar dari scope, sehingga memori yang telah dialokasikan tidak dapat diakses
kembali. Hal ini disebut sebagai *garbage*, dan sebuah program yang meninggalkan *garbage* disebut memiliki *memory
leak*

Karena hal tersebut, penting untuk melepas alokasi memori yang tidak akan digunakan lagi, hal ini dapat digunakan dengan
fungsi `free`

```c++
int n = NILAI_DINAMIS;

int *a;
a = (int*) malloc(n * sizeof(int));


// bagian program lainnya

free(a);
```

### Referensi:

- [7] K. N. King, "Advanced Uses of Pointers" in _C programming: a modern approach, Second edition_. New York London:
  W.W. Norton & Company, 2008.
- [8] “Arrays” The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Arrays [Accessed: Feb. 22, 2025]
- [9] “Dynamic Memory Allocation in C using malloc(), calloc(), free() and realloc(),” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
  [Accessed: Feb. 22, 2025.]

### 4. Bagaimana cara untuk memberikan sebuah array / matrix sebagai argumen dalam fungsi (by reference / pointer)?  (10 poin)

Saat sebuah array diberikan ke sebuah function, maka array tersebut akan selalu berubah menjadi sebuah pointer ke elemen
pertamanya.

```c++
int max(int *a, int n) {
    int i, max;
    max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max_val = max(arr, 10);
}
```

Pada contoh diatas, array `arr` diberikan kepada sebagai parameter `a` disebuah fungsi `max`, fungsi tersebut
menginginkan sebuah int pointer (`int *`).

Nilai `arr` akan secara langsung diubah menjadi sebuah pointer yang menyimpan memori elemen pertamanya.

Perlu diingat kalau sebuah pointer tidak mengandung infomasi lain tentang array tersebut. Kita perlu memberikan ukuran
dari array jika diinginkan untuk mengiterasi melalui seluruh elemen array tersebut. Hal ini diimplementasikan dalam
fungsi `max` yang meminta parameter kedua berupa sebuah `int` yang merupakan jumlah elemen dalam array yang dipoint `a`

### Referensi:

- [10] K. N. King, "Pointers and Arrays" in _C programming: a modern approach, Second edition_. New York London:
  W.W. Norton & Company, 2008.
- [11] “Arrays” The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Arrays [Accessed: Feb. 22, 2025]
- [12] B. W. Kernighan and D. M. Ritchie, "Pointers and Function Arguments" in _The C programming language_, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.

---

## Programming

### 5. Buatlah sebuah program yang terdiri atas 2 part. Pertama, program akan meminta nama awal user, lalu memberi user 3 pilihan.

#### a. Hitung Value ASCII Nama (20 poin)

`Note: Bisa langsung memakai typecast`

`Note2: Penghitungan wajib menggunakan function yang menerima array nama, dan pakai call by reference`

#### b. Ganti Nama (30 poin)

`Note: Untuk memudahkan soal ini, gunakan malloc untuk mengganti size array nama (jika panjang berbeda).`

`Gunakan 1 array tetap untuk nama user`

(dan c. Exit program)

Contoh:

```
Masukkan nama Anda:

Budiwir

Opsi (Nama: Budiwir):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

a

Value nama Anda adalah 468

Opsi (Nama: Budiwir):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

b

Masukkan nama baru:

Budi

Opsi (Nama: Budi):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

a

Value nama Anda adalah 250

Opsi (Nama: Budi):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

b

Masukkan nama baru:

goronggorong

Opsi (Nama: goronggorong):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

c

Program Selesai!
```

Penjelasan:
a. ASCII

- Budiwir = B u d i w i r (Cek ASCII table)
  ![image](https://hackmd.io/_uploads/HyWhBEIq1e.png)
- Budiwir = 42 + 75 + 64 + 69 + 77 + 69 + 72
- Budiwir = 468
- Budi = 42 + 75 + 64 + 69
- Budi = 250

**Note: C bisa mengubah char ke integer secara otomatis, jadi tidak perlu membuat fungsi khusus untuk menghitung nilai
ASCII, cukup typecasting saja dari char ke int.**

b. Ganti Nama
Untuk bagian ini, array diharuskan **sama** untuk nama (tidak membuat array baru tiap kali nama diubah).
**Note: Malloc/Calloc bisa digunakan untuk langsung mengubah size array, sehingga dapat memudahkan perubahan nama**.

Kode:

```c++
#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h> // FOR TESTING

#define MIN_BUFFER 8

int calculate_ascii(char **str);

void get_name(char **name);

int name_editor(char **name);

int main(void) {
    char *current_name = (char *) malloc(MIN_BUFFER * sizeof(char));
    if (current_name == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    printf("Enter your name: \n");
    get_name(&current_name);
    printf("\n");

    for (;;) {
        int loop_flag = name_editor(&current_name);
        if (loop_flag == 0) {
            printf("Exiting name editor....");
            break;
        }
    }
    // printf("Allocated Memory: %zu\n", _msize(current_name)); // FOR TESTING

    free(current_name);
}

void get_name(char **name) {
    int current_name_length = MIN_BUFFER;
    int i = 0;

    for (;;) {
        int ch = getchar();

        if (i + 1 > current_name_length) {
            current_name_length++;
            char *temp = (char *) realloc(*name, current_name_length * sizeof(char));

            if (temp == NULL) {
                fprintf(stderr, "Error reallocating memory\n");
                free(name);
                exit(1);
            }

            *name = temp;
        }
        if (ch == '\n') {
            (*name)[i] = '\0';
            break;
        }
        (*name)[i] = (char) ch;
        i++;
    }
}

int calculate_ascii(char **str) {
    int i = 0;
    int total = 0;
    while ((*str)[i]) {
        total += (int) (*str)[i];
        i++;
    }
    return total;
}

int name_editor(char **name) {
    int loop_flag = 1;
    printf("Options (Current name is %s):\n", *name);
    printf("  a. Get ASCII Value of name\n");
    printf("  b. Change Name\n");
    printf("  c. Exit\n");
    char option;
    printf("Option: ");
    scanf(" %c", &option);

    while (getchar() != '\n') {
    } // clear newline, bisa bikin fungsi get_name rusak karena '\n' nya bocor kesana

    switch (option) {
        case 'a':
            printf("Your name's ASCII value is %d\n", calculate_ascii(name));
            break;
        case 'b':
            printf("Enter your new name: ");
            get_name(name);
            break;
        case 'c':
            loop_flag = 0;
            break;
        default:
            printf("Invalid option, please try again\n\n");
    }
    printf("\n");
    return loop_flag;
}

```

SS Output Program Kalian :

![Output Program](https://hackmd.io/_uploads/Sy2WUHv5Je.png)

