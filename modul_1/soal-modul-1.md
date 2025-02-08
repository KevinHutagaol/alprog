# Tugas Pendahuluan - Introduction to C

```
Nama  : Kevin Imanuel Hutagaol
NPM   : 2306156763
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Sebutkan dan jelaskan minimal 10 tipe data dalam bahasa C! (10 poin)

---

#### Dalam bahasa C, terdapat 11 buah data type, yang dapat dibagi menjadi dua jenis: 
- Primitive Types
  ---
  Type dasar yang besar dan batasannya tentu dan sudah didefinisikan menurut bahasa C sendiri (dalam header `<limits.h>`), data type ini adalah : 
  - `char` : menyatakan sebuah karakter
  - `int` : menyatakan sebuah bilangan bulat
     - int memiliki 3 ukuran, `short int`, `int`, serta `long int`
     - int dapat berupa `unsigned int` atau signed int (`int`),
  - `float` : menyatakan bilangan floating point (desimal) (akurasi single)
  - `double` : menyatakan bilangan floating point (desimal) (akurasi double)
  - `void` : menyatakan tidak adanya nilai (himpunan kosong)
  
  > primitive type yang dapat dinyatakan sebagai bilangan bulat disebut sebagai *integral* types, yaitu `char`, `int`, semua ukuran, baik signed maupun unsigned

  > primitive type yang dapat dinyatakan sebagai bilangan desimal disebut sebagai *floating* types, yaitu `float`, `double` serta variasinya.

- Derived Types 
  ---
  Merupakan data type yang disusun dari primitive type, 
  - `array` : merupakan kumpulan type tertentu
  - `function` : merupakan 
  - `pointer`
  - `structure`
  - `union`

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

---

### 2. Jelaskan apa yang dimaksud dengan #include <math.h> dalam bahasa C! (10 poin)

[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

---

### 3. Jelaskan perbedaan antara for, while, dan do-while loop! (10 poin)

[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

### 4. Jelaskan apa yang menyebabkan terjadinya infinite loop? Hal ini dapat terjadi pada jenis looping statement apa saja? (10 poin)

[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

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

![Output Program](https://cdn.discordapp.com/attachments/880732274587500555/1337632640223674460/image.png?ex=67a826f9&is=67a6d579&hm=82724da82e092412cf128e96f0662ddc5f1f8c9cef8de5186df7a4bd38594430&)

### 2. Himpunan A berisi bilangan 1 - 50 (inklusif) yang habis dibagi 3 dan 5. Dengan **WHILE** loop, buatlah program yang akan print semua elemen dari A, tetapi skip 5 bilangan pertama dari A! Cantumkan kode program dan screenshot hasil outputnya! (20 poin)

---

```c
#include <stdio.h>

int main(void) { 
    // membuat himpunan A
    int min_number = 1;
    int max_number = 50; 
    // jumlah bilangan dalam range 1 - 50 yang dapat dibagi 3 dan dapat dibagi 5 (23)
    int length_array = (int) 50 / 3 + (int) 50 / 5 - (int) 50 / (3*5) - 1; 
    int himpunan_a[length_array];
    int count = 0;
    for (int i = min_number; i < max_number; i++) { 
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

![Output Program](https://cdn.discordapp.com/attachments/880732274587500555/1337631716453515305/image.png?ex=67a8261d&is=67a6d49d&hm=66d45e133fc6b35c9324a13b742e2ece65a679bc29e73c17023cbac6dd1ba455&)

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

![Output Program](https://cdn.discordapp.com/attachments/880732274587500555/1337651440021409833/image.png?ex=67a8387b&is=67a6e6fb&hm=2013658c5a2ba5af4696457ea119fc2b0982637d3b0efd6184d653a75236f813&)