# Tugas Pendahuluan - Introduction to C

```latex
Nama  : Kevin Imanuel Hutagaol
NPM   : 2306156763
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Sebutkan dan jelaskan minimal 10 tipe data dalam bahasa C! (10 poin)

---

#### Dalam bahasa C, terdapat beberapa jenis data type

- Primitive Types

  ---
  Type dasar yang besar dan batasannya tentu dan sudah didefinisikan menurut bahasa C sendiri (dalam header `<limits.h>` dan  `<float.h>`), data type juga dapat dibagi menjadi beberapa jenis:
  
  ---
  - **Integer Type:**
  
    Berupa data type yang dapat dinyatakan sebagai bilangan bulat:
    - `char` : menyimpan huruf/karakter ASCII (yang dapat dinyatakan sebagai angka 0 -127)
    - `int` : bilangan bulat dalam range `-2,147,483,648` hingga `2,147,483,647` (32-bit signed)

      `int` **memiliki beberapa variasi:**
    - `short int` : bilangan bulat dalam range `-32,768` hingga `32,767` (16-bit signed)
    - `unsigned short int` : bilangan bulat dalam range `0` hingga `65,535` (16-bit unsigned)
    - `unsigned int` : bilangan bulat dalam range `0` hingga `4,294,967,295` (32-bit unsigned)
    - `long int` : bilangan bulat dalam range `-2,147,483,648` hingga `2,147,483,647` (32-bit signed) (tergantung sistem, dapat juga merupakan 64-bit)
    - `unsigned long int` : bilangan bulat dalam range `0` hingga `4,294,967,295` (32-bit unsigned) (tergantung sistem, dapat juga merupakan 64-bit)
    - `long long int` : bilangan bulat dalam range `-9,223,372,036,854,775,808` hingga `9,223,372,036,854,775,807` (64-bit signed)
    - `unsigned long long int` : bilangan bulat dalam range `0` hingga `18,446,744,073,709,551,615` (64-bit unsigned)
  
    Contoh data type integer:

    ```c
    char huruf = 'a';
    long long int angka_besar = 1111111111111111111;
    int bilangan_negatif = -500; 
    ```

    ---

  - **Real Number Types:**

    Berupa data type yang dapat dinyatakan sebagai bilangan desimal:

    - `float` : bilangan desimal dengan akurasi paling kecil, memiliki nilai minimum `1e-37` dan nilai maksimum `1e37`
    - `double` : bilangan desimal yang akurasinya lebih besar dari `float`
    - `long double` : bilangan desimal yang akurasinya lebih besar dari `float`

    Contoh data type real:

    ```c
    float desimal = -1.2;
    double angka_besar = 111111111.1111;
    ```

- Custom/Derived Data Types

  ---
  Merupakan data type yang merupakan turunan dari primitive data type

  ---
  - **Enumeration**

    `enum` merupakan sejenis data type yang menyimpan nilai konstanta integer dengan memberikannya sebuah nama:

    ```c
    // mendefinisikan sebuah enum
    enum buah { apel, mangga, jeruk, semangka };
    // mendeklarasikan sebuah enum
    enum buah my_buah; 
    ```

    pada contoh berikut nilai `apel = 0`, `mangga = 1`, dan seterusnya, nilai angka ini dapat dinyatakan secara eksplisit

    ```c
    enum buah_lain { apel = -10, mangga, jeruk, semangka };
    ```

    disini nilai `apel = -10`, `mangga = -9`, `jeruk = -8`, dan seterusnya

    ---

  - **Union**

    `union` merupakan data type yang berguna untuk menyimpan beberapa variabel yang berbeda pada lokasi memori yang sama, yaitu variabel-variabel tersebut hanya dapat digunakan satu-persatu, tidak bersamaan seperti pada sebuah `struct`

    ```c
    // mendefinisikan sebuah union:
    union angka { 
      int i; 
      float f;
      double d;
    };
    // mendeklarasikan dan menginisialisasi sebuah union
    union angka my_angka = { .d = 1.47474 }; 
    ```

    setiap member dari sebuah `union` dapat diakses, jika sebuah member di berikan nilai, maka member lainnya akan di overwrite

    ```c
    my_angka.i = 2;
    my_angka.f = -2.45; // statement ini menghapus nilai `my_angka.i = 2`
    ```

    ---
  - **Structures**

    `struct` merupakan data type yang berisi variable dengan data type lainnya (dapat juga berupa `struct` lain)

    ```c
    // mendefinisi, mendeklarasi, dan menginisialisasi sebuah struct
    struct titik {
        int x, y; 
        float nilai;
    };

    struct titik titik_awal = {.x = 5, .y = 6, .nilai = 12.5};
    ```

    `struct` dapat mengandung `struct` didalamnya

    ```c
    struct garis {
        struct titik a, b; 
    };

    struct garis garis_pertama = { {.x = 1, .y = 2}, {.x = 5, .y = 6} };
    ```

    Elemen pada sebuah struct dapat diakses dengan operator dot:

    ```c
    garis_pertama.a.x = 10; 
    garis_pertama.a.y = 20; 
    ```

    ---
  - **Array**

    Sebuah array merupakan data type yang menyimpan sejumlah data type yang sama secara berurutan di dalam memori.

    Array memiliki panjang yang tetap yang ditentukan saat deklarasinya

    ```c
    // Mendeklarasikan array
    int my_array[10];
    ```

    Setiap elemen dalam sebuah array dapat diinisialisasi

    ```c
    int my_array_two[5] = { 0, 1, 2, 3, 4 };
    ```

    Elemen dalam sebuah array dapat diakses menurut indexnya, yang dimulai dari angka `0`

    ```c
    my_array_two[5] = 10;
    printf("%d", my_array_two[1]); // menprint nilai 1
    ```

    Array dapat menyatakan sebuah string, yaitu array dari `char` yang diakhiri dengan null character `\0`

    ```c
    char gray[] = {'g', 'r', 'a', 'y', '\0'};
    char salmon[] = "salmon"; // karakter \0 secara implisit dimasukkan
    ```

    ---
  - **Pointer**
  
    Sebuah pointer menyimpan memory address dari variabel atau konstatnta. Setiap data type baik primitif maupun derived dapat memiliki sebuah pointer yang menyimpan memory address sebuah instance dari type tersebut.

    Pointer dapat dideklarasikan dengan operator `*`

    ```c
    int *angka; // sebuah pointer yang menyimpan memory address sebuah int
    ```

    Pointer dapat diinisialisasikan dengan memberikan address sebuah variabel untuk disimpan dalam pointer tersebut.

    ```c
    int i, j;
    // menginisialisasi pi ke memory address dari i
    int *pi = &i; 
    // mengassign pi ke memory addres dari j, perhatikan kalo `*` tidak digunakan setelah deklarasi
    pi = &j;
    ```

    Pointer yang tidak diinisialisasikan akan menyimpan address yang menuju tempat tidak tentu sehingga menyebabkan undefined behavior dan dapat menyebabkan error.

    Pointer dapat menyimpan address sebuah struct:

    ```c
    struct buah { 
        int harga;
        float berat;
    };

    struct buah mangga = { 10000, 1.2 };
    // menginisialisasikan pointer pbuah ke memory address dari mangga
    struct buah *pbuah = &mangga; 
    ```

    Member dari sebuah struct dapat diakses dengan notasi `->`

    ```c
    pbuah->harga = 15000; 
    pbuah->berat = 2.0; 
    ```

### Referensi

- [1] The GNU C Reference Manual. [Online]. Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Data-Types [Accessed: Feb. 09, 2025]
- [2] B. W. Kernighan and D. M. Ritchie, "Types, Operators and Expressions", in *The C programming language*, 2nd ed. Englewood Cliffs, N.J: Prentice Hall, 1988.
- [3] Data Types in C, GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/data-types-in-c/ [Accessed: Feb. 09, 2025]

---

### 2. Jelaskan apa yang dimaksud dengan #include <math.h> dalam bahasa C! (10 poin)

`#include <math.h>` merupakan sebuah operator *preprocessor* yang mengarahkan compiler C untuk memasukan isi dari file `math.h` sebelum compile.

- Header file `math.h`

  Sebuah Header file (file yang berakhir dengan `.h`) merupakan file yang hanya deklarasi variabel dan fungsi, dimana fungsi-fungsi tersebut akan didefinisikan didalam Source file (berakhir dengan `.c`).

  Header file dapat diinclude kedalam source file lainnya, sehingga file tersebut dapat mengetahui fungsi - fungsi yang terdapat di dalam header file, tetapi tidak perlu mengetahui bagaimana implementasi fungsi tersebut.

- Operator **`preprocessor`**

  Preprocessor merupakan sebuah step pertama terpisah sebelum melakukan complie sebuah program C. Salah satu dari operator preprocessor yang paling digunakan adalah `#include`

  ```c
  #include "filename"

  #include <filename>
  ```
  
  Ketika sebuah file dinyatakan dalam `#include`, maka seluruh konten dari file tersebut akan diletakkan dimana terdapat `#include` tersebut, yang pada umumnya diletakkan di awal sebuah program. File yang akan di include dapat juga memiliki operator `#include` didalamnya.

  Penggunaan `#include` merupakan cara untuk mengabungkan sekumpulan deklarasi, definisi, dan lainnya kepada sebuah program.

### Referensi

- [4] The GNU C Reference Manual. [Online]. Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Program-Structure [Accessed: Feb. 09, 2025]
- [5] B. W. Kernighan and D. M. Ritchie, "The C Preprocessor", in *The C programming language*, 2nd ed. Englewood Cliffs, N.J: Prentice Hall, 1988.
- [6] C Preprocessors, GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/cc-preprocessors/ [Accessed: Feb. 09, 2025]

---

### 3. Jelaskan perbedaan antara for, while, dan do-while loop! (10 poin)

- While Loop

  ---

  Sebuah `while` loop merupakan statement looping yang memiliki test case di awal:

  ```c
  while (test_case) { 
    statement;
  };
  ```

  `while` loop pertama akan mengevaluasi test yang ada, jika test menghasilkan `true` maka statement akan dieksekusi, setelah itu akan terjadi looping dan test akan dievaluasi lagi, hal ini berulang terus menerus hingga test menghasilkan `false`.

  contoh `while` loop:

  ```c
  int increment = 0;
  while (increment < 100) { 
    printf("%d ", increment);
    increment++;
  };
  ```

- Do While Loop

  ---

  Sebuah `do while`, berbeda dengan `while`,  memiliki test case di akhir loop:

  ```c
  do {
    statement; 
  } while (test_case);
  ```

  statement pertama akan dieksekusi, setelah itu test akan dievaluasi, jika test menghasilkan `true`, maka akan terjadi looping dan statement dieksekusi kembali. 

  contoh `do while` loop:

  ```c
  int increment = 0;
  do { 
    printf("%d ", increment);
    increment++;
  } while (increment < 100);
  ```

- For Loop

  ---

  Sebuah `for` loop, merupakan sejenis loop yang melakukan inisialisasi variabel, test case, serta modifikasi variabel dalam satu statement:

  ```c
  for (inisialisasi; test_case; step) {
    statement; 
  };
  ```

  - pertama for loop akan menginisialisasi variabel yang ada,
  
  - setelah itu for loop akan mengevaluasi test case, jika test bernilai `true` maka statement akan dieksekusi,

  - setelah statement dieksekusi, statement step akan dieksekusi, dan setelah itu akan lanjut ke iterasi setelanjutnya dengan mengevaluasi test case.

  contoh `for` loop:

  ```c
  for (int i = 0; i < 100; i++) { 
    printf("%d ", i);
  };
  ```

### Referensi

- [7] The GNU C Reference Manual. [Online]. Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Statements [Accessed: Feb. 09, 2025]
- [8] B. W. Kernighan and D. M. Ritchie, "Control Flow", in *The C programming language*, 2nd ed. Englewood Cliffs, N.J: Prentice Hall, 1988.
- [9] C - Loops, GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/c-loops/ [Accessed: Feb. 09, 2025]

### 4. Jelaskan apa yang menyebabkan terjadinya infinite loop? Hal ini dapat terjadi pada jenis looping statement apa saja? (10 poin)

Infinite loop dapat terjadi apabila test case yang terdapat pada loop tidak pernah menghasilkan `false`, hal ini dapat terjadi baik secara intensional maupun tidak intensional: 

- Infinite loop di dalam `for` loop:
  
  Sebuah `for` loop yang secara sengaja dibuat infinite:

  ```c
  for (;;) { statement; };
  ```

  Dalam contoh diatas, tidak pernah terjadi test case sama sekali, sehingga for loop tidak akan pernah berhenti dan statement akan terus menerus dieksekusi.

  sebuah `for` loop yang test casenya tidak akan pernah tercapai

  ```c
  int count = 0;
  for (int i = 0; count < 100, i++) { statement yang tidak memodifikasi nilai `count` }; 
  ```
  
  Dalam contoh diatas, test case tidak akan pernah tercapai karena nilai `count` tidak pernah diubah di dalam loopnya.

- Infinite loop di dalam `do while` dan `while` loop:
  
  Sebuah `while` loop yang secara sengaja dibuat infinite:

  ```c
  while (true) { statement; }; 
  do { statement; } while (true);
  ```

  Dalam contoh diatas, test case selalu berupa `true` sehingga loop tidak pernah akan berhenti.

  sebuah `while` loop yang test casenya tidak akan pernah tercapai

  ```c
  int i = 0;
  while (i < 100) { 
    statement yang tidak memodifikasi nilai `i`;
  }
  ```
  
  Dalam contoh diatas, test case tidak akan pernah tercapai karena nilai `i` tidak pernah diubah di dalam loopnya.

- Break statement untuk keluar dari infinite loop:

  Sebuah `break` statement berguna untuk keluar dari loop, statement ini dapat digunakan bersamaan dengan infinite loop untuk menghasilkan control flow tertentu.

  ```c
  while (true) 
  { 
    statement; 
    if (other_test) { 
      break; 
    }
  }
  ```

### Referensi

- [10] The GNU C Reference Manual. [Online]. Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Statements [Accessed: Feb. 09, 2025]
- [11] B. W. Kernighan and D. M. Ritchie, "Control Flow", in *The C programming language*, 2nd ed. Englewood Cliffs, N.J: Prentice Hall, 1988.
- [12] C - Loops, GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/c-loops/ [Accessed: Feb. 09, 2025]

---

## Programming

### 1. Buatlah program yang menampilkan output berupa teks "Hello [Nama Anda]!" dalam bahasa C! Cantumkan kode program dan screenshot hasil outputnya! (20 poin)

---

```c
#include <stdio.h>

int main(void) { 
    printf("Hello Kevin Imanuel Hutagaol");
    return 0;
}
```

![Output Program](https://hackmd.io/_uploads/rk3eFlSYJx.png)

### 2. Himpunan A berisi bilangan 1 - 50 (inklusif) yang habis dibagi 3 dan 5. Dengan **WHILE** loop, buatlah program yang akan print semua elemen dari A, tetapi skip 5 bilangan pertama dari A! Cantumkan kode program dan screenshot hasil outputnya! (20 poin)

---

```c
#include <stdio.h>

int main(void) { 
    // membuat himpunan A
    int min_number = 1;
    int max_number = 50; 
    // jumlah bilangan dalam range 1 - 50 yang dapat dibagi 3 dan dapat dibagi 5 (23)
    int length_array = (int) 50 / 3 + (int) 50 / 5 - (int) 50 / (3*5); 
    int himpunan_a[length_array];
    int count = 0;
    for (int i = min_number; i <= max_number; i++) { 
        if (i % 3 == 0 || i % 5 == 0) { 
            himpunan_a[count] = i;
            count++;
        }
    }


    // memprint himpunan A
    int start_of_print = 5;
    int i = start_of_print; 
    while (i < sizeof(himpunan_a) / sizeof(int)) {
        printf("%d ", himpunan_a[i]);
        i++;
    }
    
    return 0;
}

```

![Output Program](https://hackmd.io/_uploads/HkrpbbSY1l.png)

### 3. Alien-Drawing? (20 poin)

> Hint: Gunakan for loop.

Buatlah program yang akan menampilkan output suatu shape dengan panjang yang ditentukan oleh user. Program akan menerima input panjang dari user, kemudian program akan menampilkan sebuah shape dengan panjang tersebut. Contoh output program adalah sebagai berikut:

Test Case 1:  
Input:

```bash
1
```

Output:

```bash
*
```

Test Case 2:  
Input:

```bash
2
```

Output:

```bash
 *
* *
 *
```

Test Case 3:  
Input:

```bash
3
```

Output:

```bash
  *
 * *
*  *
 * *
  *
```

Test Case 4:  
Input:

```bash
6
```

Output:

```bash
     *
    * *
   *  *
  *   *
 *    *
*     *
 *    *
  *   *
   *  *
    * *
     *
```

---

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) { 
    int length;
    printf("Enter length of drawing:");
    scanf("%d", &length);

    int height_of_pyramid = 2*length - 1;
    int width_of_pyramid = length + 1;
 
    for (int i = 0; i < height_of_pyramid ; i++) { 
        for (int j = abs(width_of_pyramid - i - 2); j > 0; j--) { 
            printf(" ");
        }
        // ujung ujung jadi eksepsi:
        if (i == 0 || i == height_of_pyramid - 1) { 
            printf("*\n");
            continue;
        } 
        printf("*");
        for (int j = width_of_pyramid - 2 - abs(width_of_pyramid - 2 - i) ; j > 0; j--) { 
            printf(" ");
        }
        printf("*\n");
    }


    return 0;
}
```

![Output Program](https://hackmd.io/_uploads/BknetxBKyx.png)
