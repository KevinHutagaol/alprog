# Tugas Pendahuluan Modul 2 - Array and Function

```latex
Nama  : Kevin Imanuel Hutagaol
NPM   : 2306156763
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Jelaskan apa itu array dan keuntungan menggunakan array dibandingkan dengan variabel biasa! (10 poin)

---
Sebuah array merupakan data type yang menyimpan sejumlah data type yang sama secara berurutan di dalam memori.

Array memiliki panjang yang tetap yang ditentukan saat deklarasinya

```c++
// Mendeklarasikan array
int my_array[10];
```

Setiap elemen dalam sebuah array dapat diinisialisasi

```c++
int my_array_two[5] = { 0, 1, 2, 3, 4 };
```

Elemen dalam sebuah array dapat diakses menurut indexnya, yang dimulai dari angka `0`

```c++
my_array_two[5] = 10;
printf("%d", my_array_two[1]); // menprint nilai 1
```

Array memiliki beberapa keuntungan dibanding variabel biasa seperti:

- Pengelolaan Data yang Efisien:

  Array menyimpan banyak data dalam satu data structure, sehingga menghindari perlunya mendeklarasi variabel berulang
  kali


- Akses Elemen Secara Indeks:

  Pengaksesan data dalam Array dapat dilakukan dengan mudah melalui indeksnya.


- Penggunaan Memori yang berurutan:

  Elemen array disimpan secara berurutan dalam memori, sehingga elemenya dapat tersimpan secara efisien, serta
  memudahkan akses melalui memori


- Kemudahan dalam Operasi Loop:

  Array mendukung operasi pengolahan data menggunakan loop (for atau while),
  sehingga memudahkan pengolahan data dalam jumlah besar.

### Referensi:

- [1] “Arrays” The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Arrays [Accessed: Feb. 16, 2025]
- [2] B. W. Kernighan and D. M. Ritchie, "Pointers and Arrays" in _The C programming language_, 2nd ed. Englewood
  Cliffs, N.J: Prentice Hall, 1988.
- [3] “C Arrays,” GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/c-arrays/ [Accessed: Feb. 17, 2025]

---

### 2. Jelaskan apa yang dimaksud dengan array 1D dan 2D serta jelaskan perbedaan keduanya! (10 poin)

Array 1D merupakan array yang berisi elemen elemen yang disusun secara linear, contoh array 1D seperti vektor, deret
bilangan, list nama, dan lainnya

```c++
int array_1D[4] = {0, 1, 2, 3};
```

Array 2D, berbeda dengan array 1D, memiliki elemen yang dapat diakses di dua dimensi, biasanya disebut kolom dan baris.
Contoh array 2D seperti matriks, tabel, map, dan lainya

Array 2D dibentuk oleh sebuah array 1D yang didalamnya berisi array 1D, sehingga membentuk penyusunan elemen dalam dua
dimensi.

```c++
int array_2D[2][4] = { {0, 1, 2, 3}, {1, 2, 3, 4} };
```

### Referensi:

- [4] “Multidimensional Arrays” The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Multidimensional-Arrays [Accessed: Feb. 16, 2025]
- [5] B. W. Kernighan and D. M. Ritchie, "Pointers and Arrays" in _The C programming language_, 2nd ed. Englewood
- [6] “C Arrays,” GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/c-arrays/ [Accessed: Feb. 17, 2025]
  Cliffs, N.J: Prentice Hall, 1988.

---

### 3. Jelaskan apa itu function dan bagaimana cara penggunaannya! (10 poin)

Fungsi merupakan suatu cara untuk memisahkan bagian bagian dari sebuah program menjadi proses-proses yang lebih kecil.
Setiap program dalam `c` memiliki satu fungsi yaitu fungsi `main`, dimana eksekusi program pertama dimulai,

- **Function Declaration**

  Penggunaan fungsi pertama dilakukan dengan mendeklarasikan sebuah fungsi:

    ```c++
    // notasi pendeklarasian fungsi
    return_type function_name (parameters); 
    
    // contoh deklarasi fungsi
    int multiply(int x, int y);
    ```

  Dalam contoh diatas, dideklarasikan sebuah fungsi yang dinamakan `multiply`, fungsi ini akan 'mengembalikan' nilai
  berupa sebuah `int`, dan fungsi ini meminta dua buah parameter yaitu: `x`, sebuah `int`; serta `y`, sebuah `int`


- **Function Definition**

  Fungsi harus didefinisikan untuk mengetahui logika yang terdapat didalam fungsi tersebut, definisi fungsi mengandung
  informasi terkait return type, nama fungsi, nama dan type dari parameternya, serta `body` dari function tersebut, yang
  terdapat diantara kurung kurawal { ... }

    ```c++
    // notasi pendefinisian fungsi
    return_type function_name (parameters) {
        // body_of_function
    }
    
    // contoh pendefinisian dari fungsi multiply
    int multiply(int x, int y) {
        return x * y;
    }
    ```
  Didalam definisi fungsi terdapat sebuah `return` yaitu nilai yang akan diberikan oleh fungsi setelah fungsi tersebut
  di `call`, jika fungsi tidak mengembalikan apapun maka return type fungsi tersebut adalah `void`


- **Calling a Function**

  Sebuah fungsi dapat 'dipanggil' dengan menggunakan namanya serta memberikan parameter yang dibutuhkan (jika ada).

    ```c++
    multiply(2, 3);
    ```
  Dalam contoh diatas, fungsi `multiply` telah dipanggil, dengan memberikan parameter x sebagai 2 dan parameter y
  sebagai 3.

  Fungsi dapat membentuk sebuah expresi:

  ```c++
  int answer = multiply(2, 3);
  ```

  Dalam contoh diatas, nilai `return` fungsi multiply yang merupakan sebuah akan di assign ke variabel `answer`

### Referensi:

- [7] “Functions” The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Functions [Accessed: Feb. 16, 2025]
- [8] B. W. Kernighan and D. M. Ritchie, "Functions and Program Structure" in _The C programming language_, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.
- [9] “C Functions,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/c-functions/ [Accessed: Feb. 17, 2025]

### 4. Jelaskan perbedaan antara pass-by-value dan pass-by-reference! serta jelaskan juga apa yang dimaksud dengan scope variabel dalam function (10 poin)

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

- Scope variabel dalam function:

  Scope dari sebuah variabel menandakan bagian mana dari program yang dapat mengakses variabel tersebut.

    - Scope global (eksternal):

      Sebuah variabel yang di deklarasi secara global (diluar fungsi apapun) memiliki scope yaitu semua kode yang berada
      setelah deklarasi variabel tersebut:

      ```c++
      void push(int num) { . . . }
      
      int target = 1;
      
      int main() { . . . }
      
      int pop() { . . . }
      ```

      Dalam contoh diatas nilai `target` dapat diakses oleh fungsi `main` serta fungsi `pop`, tetapi tidak oleh fungsi
      `push`, hal ini dikarenakan variabel `target` berada diluar scope fungsi tersebut yang dideklarasikan sebelum
      nilai `target`

    - Scope dalam fungsi (lokal):

      Variabel yang dideklarasikan secara lokal (didalam fungsi atau block) hanya dapat diakses oleh kode yang berada
      setelah variabel tersebut dideklarasikan, dan berada didalam block yang sama

      ```c++
      void push(int num);
      
      int main() {
        int val = 1; 
      }
      
      void push(int num) { . . . }
      ```

      Dalam contoh diatas, nilai `val` tidak dapat diakses oleh fungsi `push`, hal ini dikarenakan nilai `val`
      dideklarasikan didalam fungsi `main`, sehingga scopenya terbatas didalam fungsi tersebut.

### Referensi:

- [10] “Program Structure and Scope” The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Program-Structure-and-Scope [Accessed: Feb. 16, 2025]
- [11] B. W. Kernighan and D. M. Ritchie, "Functions and Program Structure" in _The C programming language_, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.
- [12] “Scope rules in C,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/scope-rules-in-c/ [Accessed: Feb. 17, 2025]

---

## Programming

### 1. Buatlah program yang akan melakukan perkalian pada 2 buah matrix yang diinput oleh user. Gunakan juga function minimal 2 untuk mempermudah perhitungan matrix. (30 poin)

---

#### Contoh output yg benar:

```
Input matrix 1 :
3 4
2 1

Input matrix 2 :
2 3
4 7

Hasil perkalian :
22 37
8 13
```

Code Kalian :

```c++
#include <stdio.h>
#include <stdlib.h>

int **multiply_matrix(size_t row1, size_t col1, int **matrix1, size_t row2, size_t col2, int **matrix2);

void print_matrix(size_t row, size_t col, int **matrix);

int **scan_matrix(size_t *rows, size_t *cols);

int main(void) {
    size_t rows1, cols1;
    int **matrix1 = scan_matrix(&rows1, &cols1);

    size_t rows2, cols2;
    int **matrix2 = scan_matrix(&rows2, &cols2);

    size_t rows_result = rows1;
    int **matrix_result = multiply_matrix(rows1, cols1, matrix1, rows2, cols2, matrix2);


    printf("Result:\n");
    print_matrix(rows1, cols2, matrix_result);

    for (size_t i = 0; i < rows1; ++i) {
        free(matrix1[i]);
    }
    free(matrix1);
    for (size_t i = 0; i < rows2; ++i) {
        free(matrix2[i]);
    }
    free(matrix2);
    for (size_t i = 0; i < rows_result; ++i) {
        free(matrix_result[i]);
    }
    free(matrix_result);

    return 0;
}

int **multiply_matrix(size_t row1, size_t col1, int **matrix1, size_t row2, size_t col2, int **matrix2) {
    if (col1 != row2) {
        fprintf(stderr, "Error: Invalid matrix dimensions, matrix 1 column: %zu, matrix 2 row: %zu\n", col1, row2);
        return NULL;
    }

    int **out_matrix = malloc(row1 * sizeof(int *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row1; i++) {
        out_matrix[i] = malloc(col2 * sizeof(int));
        if (out_matrix[i] == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for matrix row %zu\n", i);
            for (size_t j = 0; j < i; j++) {
                free(out_matrix[j]);
            }
            free(out_matrix);
            return NULL;
        }
    }

    for (size_t i = 0; i < row1; i++) {
        for (size_t j = 0; j < col2; j++) {
            int temp = 0;
            for (size_t k = 0; k < col1; k++) {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            out_matrix[i][j] = temp;
        }
    }

    return out_matrix;
}

void print_matrix(size_t row, size_t col, int **matrix) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **scan_matrix(size_t *rows, size_t *cols) {
    size_t row_temp, col_temp;
    printf("Enter dimensions of matrix (ex: 2, 3):  ");
    if (scanf("%zu, %zu", &row_temp, &col_temp) != 2) {
        fprintf(stderr, "Error: Invalid matrix dimensions reading from stdin\n");
        return NULL;
    }

    int **out_matrix = malloc(row_temp * sizeof(int *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row_temp; i++) {
        out_matrix[i] = malloc(col_temp * sizeof(int));
        if (out_matrix[i] == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for matrix row %zu\n", i);
            for (size_t j = 0; j < i; j++) {
                free(out_matrix[j]);
            }
            free(out_matrix);
            return NULL;
        }
    }
    printf("Enter Matrix\n");

    for (int i = 0; i < row_temp; i++) {
        for (int j = 0; j < col_temp; j++) {
            scanf(" %d", &out_matrix[i][j]);
        }
    }

    *rows = row_temp;
    *cols = col_temp;

    return out_matrix;
}
```

SS Output Program Kalian :
![Output Program](https://hackmd.io/_uploads/B1pV-K1qye.png)

### 2. Buatlah sebuah program yang mengenkripsi isi dari array berikut dengan melakukan shifting sebanyak 1 kali. (30 poin)

Contoh shifting ```a --> b```, ```b --> c```, dst.

```
char hero[5][10] = {"gusion", "fanny", "yin", "johnson", "nana"};
```

#### Contoh output yg benar:

```
Hero 1: hvtjpo
Hero 2: gbooz
Hero 3: zjo
Hero 4: kpiotpo
Hero 5: obob
```

---

Code Kalian :

```c++
#include <stdio.h>

void shift_ascii(char *s);

int main(void) {
    char hero[5][10] = {"gusion", "fanny", "yin", "johnson", "nana"};

    for (int i = 0; i < sizeof(hero) / sizeof(hero[0]); i++) {
        shift_ascii(hero[i]);
        printf("Hero %d: %s \n", i, hero[i]);
    }
}

void shift_ascii(char *s) {
    for (; *s; s++) {
        // kalo dia 'z' di shift jadi 'a'
        if (*s == 'z') {
            *s = 'a';
            continue;
        }
        // kalo dia 'Z' di shift jadi 'A'
        if (*s == 'Z') {
            *s = 'A';
            continue;
        }
        // kalo dia '9' di shift jadi '0'
        if (*s == '9') {
            *s = '0';
            continue;
        }
        // shift biasa
        (*s)++;
    }
}

```

SS Output Program Kalian :

![Output Program](https://hackmd.io/_uploads/BJTEZFyqyl.png)

