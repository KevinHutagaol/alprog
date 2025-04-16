# Case Study - Sorting

## Binary Sorting with Zeroes

Binary sorting merupakan proses pengurutan angka-angka desimal berdasarkan jumlah bit 0 dalam representasi biner mereka. Dalam hal ini, kita akan mengelompokkan angka-angka tersebut ke dalam kelompok yang memiliki jumlah bit 0 yang sama. Setiap kelompok akan ditandai dengan `[...]`. Angka-angka dalam kelompok tersebut juga perlu diurutkan.

Input:

- Jumlah angka
- Angka-angka yang akan diurutkan

Output:

- Angka-angka yang telah diurutkan

### Batasan

1. Asumsikan jumlah angka antara 1 hingga 1000.
2. Angka yang diberikan adalah bilangan bulat positif.

### Kriteria Pengurutan

- Angka-angka akan dikelompokkan berdasarkan jumlah bit `0` dalam representasi biner mereka.
- Setiap kelompok akan diurutkan berdasarkan jumlah bit `0` secara ascending.
- Angka-angka dalam kelompok yang sama perlu diurutkan secara descending.
- Output akan ditampilkan dalam format kelompok, misalnya: `[angka1 angka2], [angka3], [angka4 angka5]`.
- Kelompok dipisahkan oleh tanda koma `,` dan setiap kelompok ditandai dengan tanda kurung siku `[]`.
- Tidak perlu error handling.

### Kode Function

Berikut adalah kode function untuk mendapatkan jumlah bit 0 dari binary representation suatu angka desimal.

```c
int num_of_zeroes(int n)
{
    long long bin = 0;
    int rem, zeroes = 0, i = 1;

    while (n != 0)
    {
        rem = n % 2;
        if (rem == 0)
            zeroes++;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return zeroes;
}
```

---

### Contoh

> **Input:**

```sh
Jumlah angka: 5
Input angka:
1 2 3 4 5
```

> **Output:**

```sh
[3 1], [5 2], [4]
```

> **Penjelasan:**

```sh
- 1 dalam biner adalah `1` (1 bit 0)
- 2 dalam biner adalah `10` (1 bit 0)
- 3 dalam biner adalah `11` (0 bit 0)
- 4 dalam biner adalah `100` (2 bit 0)
- 5 dalam biner adalah `101` (1 bit 0)
- Kelompok pertama adalah [3 1] karena memiliki 0 bit 0.
- Kelompok kedua adalah [5 2] karena memiliki 1 bit 0.
- Kelompok ketiga adalah [4] karena memiliki 2 bit 0.
```

---

> **Input:**

```sh
Jumlah angka: 5
Input angka:
57 49 47 293 12
```

> **Output:**

```sh
[47], [57 12], [49], [293]
```

> **Penjelasan:**

```sh
- 47 dalam biner adalah `101111` (0 bit 0)
- 57 dalam biner adalah `111001` (2 bit 0)
- 12 dalam biner adalah `1100` (2 bit 0)
- 49 dalam biner adalah `110001` (3 bit 0)
- 293 dalam biner adalah `100100101` (5 bit 0)
- Kelompok pertama adalah [47] karena memiliki 0 bit 0.
- Kelompok kedua adalah [57 12] karena memiliki 2 bit 0.
- Kelompok ketiga adalah [49] karena memiliki 3 bit 0.
- Kelompok keempat adalah [293] karena memiliki 5 bit 0.
```

---

> **Input:**

```sh
Jumlah angka: 9
Input angka:
83 17 56 1 58 99 34 12 10
```

> **Output:**

```sh
[1], [58 12 10], [99 83 56 17], [34]
```

> **Penjelasan:**

```sh
- 1 dalam biner adalah `1` (0 bit 0)
- 58 dalam biner adalah `111010` (2 bit 0)
- 12 dalam biner adalah `1100` (2 bit 0)
- 10 dalam biner adalah `1010` (2 bit 0)
- 99 dalam biner adalah `1100011` (3 bit 0)
- 83 dalam biner adalah `1010011` (3 bit 0)
- 56 dalam biner adalah `111000` (3 bit 0)
- 17 dalam biner adalah `10001` (3 bit 0)
- 34 dalam biner adalah `100010` (4 bit 0)
- Kelompok pertama adalah [1] karena memiliki 0 bit 0.
- Kelompok kedua adalah [58 12 10] karena memiliki 2 bit 0.
- Kelompok ketiga adalah [99 83 56 17] karena memiliki 3 bit 0.
- Kelompok keempat adalah [34] karena memiliki 4 bit 0.
```

Good Luck! -BH
