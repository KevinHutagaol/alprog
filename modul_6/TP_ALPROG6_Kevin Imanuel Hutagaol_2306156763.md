# Tugas Pendahuluan Modul 6 - Searching

```
Nama  : Kevin Imanuel Hutagaol
NPM   : 2306156763
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Jelaskan apa itu searching, jenis-jenisnya, cara kerjanya, dan pengaplikasiannya! <span style="color:red;">(30 Poin)</span>

---

Algoritma Searching merupakan metode untuk menemukan elemen didalam sebuah data structure (seperti array). Terdapat dua
jenis algoritma sorting, linear search dan binary search

#### Linear search

Elemen pada array akan diuji satu persatu terhadap target, dimulai dari indeks 0, hingga elemen ditemukan atau array
semua telah di uji

  ```c++
  int search(int *arr, int N, int x) {
    for (int i = 0; i < N; i++) {
      if (arr[i] == x) return i;
    }
    return -1;
  }
  ```

- Illustrasi Linear Search untuk mencari angka 98

  ![image](https://hackmd.io/_uploads/SJcgbXXn1x.png)

- Kelebihan linear search:
    - Implementasi sederhana
    - Dapat melakukan searching pada data tidak berurut
- Kekurangan linear search:
    - Time complexity O(N), sehingga tidak efisien untuk data yang besar

### Binary search

Elemen pada array akan dibagi dua setiap iterasi, dan pada iterasi berikutnya memilih bagian dari array yang mengandung
solusi menurut peraturan iterasi:

- Binary search pertama menentukan nilai low = elemen pertama array, dan high = elemen terakhir array

- Untuk setiap iterasi, ditentukan nilai array pada index mid, yang berada ditengah low dan high

  - Jika nilai di mid sama dengan target, maka elemen telah ditemukan

  - Jika nilai mid > target, maka solusi berada di sebelah kanan, sehingga geser pencarian dengan mengassign
    `low = mid + 1`

  - Jika nilai mid < target, maka solusi berada di sebelah kiri, sehingga geser pencarian dengan mengassign
    `high = mid - 1`


- Karena proses pembagian, array yang diberikan harus terurut (sorted)

```c++
int binarySearch(const int *arr, const int size, const int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
```

- Kelebihan linear search:
  - Jumlah iterasi jauh lebih sedikit dibandingkan linear search
  - Time complexity O(log N), sehingga efisien untuk data besar
- Kekurangan linear search:
  - Hanya dapat melakukan searching di array yang sudah sorted
  - Implementasi lebih kompleks dibanding linear search 


### Referensi:

- [1] “Binary Search Algorithm - Iterative and Recursive Implementation,” GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/binary-search/ [Accessed: Mar. 15, 2025.]
- [2] “Linear Search Algorithm,” GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/linear-search/ [Accessed: Mar. 15, 2025.]

---

### 2. Terdapat sebuah data nilai ujian kalkulus yang telah terurut sebagai berikut:

`77 78 83 83 90 98 100`

### Anda diminta untuk membuat program yang akan mencari ada di index ke berapa mahasiswa yang mendapatkan nilai 98. Buatlah dan jelaskan ilustrasi untuk menggambarkan skenario tersebut menggunakan algoritma selain linear search! <span style="color:red;">(30 Poin)</span>

### Illustrasi untuk binary search:

![image](https://hackmd.io/_uploads/rkl73gQ2yg.png)

### Penjelasan:

Array sudah sorted, sehingga dapat dilakukan binary search:

Pertama diset awal $L = 0$ dan $R = N_{array} - 1 = 6$,

Untuk setiap iterasi, dihitung nilai tengan yaitu, iterasi selesai saat ditemukan nilai $M = 98$, atau $L < R$

$$ M = L + \frac{R-L}{2}$$

Iterasi selesai saat ditemukan nilai $M = 98$, atau $L > R$ (target tidak ditemukan)

- Pada iterasi $i = 0$:

  $$L = 0, \quad M = 3, \quad R = 6$$

  dengan $\text{array}[M] = 83$, diperoleh $\text{array}[M] = 83 < 98$, sehingga iterasi ke arah kanan:

  $$L_{\mathrm{new}} = M + 1 = 4$$

- Pada iterasi $i = 1$:

  $$L = 4, \quad M = 5, \quad R = 6$$

  dengan $\text{array}[M] = 98$, diperoleh $\text{array}[M] = 83 = 98$, target ditemukan dan iterasi selesai

  $$\boxed{\text{Target ditemukan di } M = 5}$$

### Referensi:

- [3] “Binary Search Algorithm - Iterative and Recursive Implementation,” GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/binary-search/ [Accessed: Mar. 15, 2025.]
- [4] “Linear Search Algorithm,” GeeksforGeeks.  [Online]. Available: https://www.geeksforgeeks.org/linear-search/ [Accessed: Mar. 15, 2025.]

---

## Programming

### Realisasikan skenario ini dalam program bahasa C. Berikan juga analisa terhadap kode yang telah dibuat! <span style="color:red;">(40 Poin)</span>

---

Code Kalian :

```c++
#include <stdio.h>

int binarySearch(const int *arr, int size, int key);

int main() {
    int arr[] = { 77, 78, 83, 83, 90, 98, 100 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 98;
    int result = binarySearch(arr, size, target);

    if (result == -1) {
        printf("Student with score %d not found", target);
    } else {
        printf("Student with score %d found at index %d", target, result);
    }
}

int binarySearch(const int *arr, const int size, const int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

```

SS Output Program Kalian :

![image](https://hackmd.io/_uploads/SkOnlb72Jx.png)

**Analisa** :

Program pertama memasukan array nilai yang ingin di search secara langsung
`int arr[] = { 77, 78, 83, 83, 90, 98, 100 };`

Terdapat fungsi berupa `int binarySearch(const int *arr, int size, int key)`, fungsi ini meminta pointer array, size
dari array, serta key yang ingin di cari

Fungsi `binarySearch` pertama menginisialisasikan nilai `int low = 0` dan `int high = size - 1` (elemen terakhir array)

Untuk setiap iterasi, dihitung nilai `int mid = low + (high - low) / 2`, nilai `arr[mid]` akan dibandingkan dengan key
untuk mementukan step iterasi selanjutnya:

- Jika `arr[mid] = key`, maka telah ditemukan elemen yang dicari, sehingga nilai mid di return

- Jika `arr[mid] < key`, maka solusi berada di sebelah kanan, sehingga geser pencarian dengan mengassign `low = mid + 1`

- Jika `arr[mid] < key` (kondisi else), maka solusi berada di sebelah kiri, sehingga geser pencarian dengan mengassign
  `high = mid - 1`

- Jika tidak ditemukan nilai sama sekali, maka condition di `while(low <= high)` akan false, sehingga fungsi mereturn
  `-1`
