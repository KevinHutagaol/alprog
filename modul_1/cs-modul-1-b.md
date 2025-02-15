# Case Study - Introduction to C

## Brainrot-Calculator

Buatlah sebuah kalkulator sederhana yang dapat melakukan **operasi penjumlahan, pengurangan, dan perkalian pada bilangan integer**. Kalkulator awalnya akan menerima input berupa operasi yang diinginkan serta opsi untuk quit. Jika sudah memilih operasi yang diinginkan, maka akan dilanjutkan untuk meminta **input 2 bilangan** dari user. Output dari kalkulator tersebut adalah **sebuah pola / shape (shape nya silakan melihat contoh program)** dengan panjang yang ditentukan oleh hasil dari operasi tersebut. Kalkulator **akan berjalan terus** kecuali dilakukan quit oleh user. Sebaiknya menerapkan juga **error handling** dan **interface menu yang bagus**. Contoh output program adalah sebagai berikut:

> Interface menu dibebasin ke kalian mau bikin seperti apa, yang penting rapi dan jelas.

> Pola yang dibuat adalah huruf L

Test Case 1:  
Input:
```bash
======MENU=======
1. Tambah
2. Kurang
3. Kali
4. Quit
Pilihan: 5
```

Output: (Error handling)
```bash
Salah input. Coba lagi!
```

Test Case 2:  
Input:
```bash
======MENU=======
1. Tambah
2. Kurang
3. Kali
4. Quit
Pilihan: 2
Input angka 1: 2
Input angka 2: 1
```

Output: (Hasil kalkulasi adalah 1 dari 2 - 1)
```bash
*
```

Test Case 3:  
Input:
```bash
======MENU=======
1. Tambah
2. Kurang
3. Kali
4. Quit
Pilihan: 3
Input angka 1: 2
Input angka 2: 1
```

Output: (Hasil kalkulasi adalah 2 dari 2 * 1)
```bash
*
**
```

Test Case 4:  
Input:
```bash
======MENU=======
1. Tambah
2. Kurang
3. Kali
4. Quit
Pilihan: 1
Input angka 1: 2
Input angka 2: 2
```

Output: (Hasil kalkulasi adalah 4 dari 2 + 2)
```bash
*
*
*
****
```

Test Case 5:  
Input:
```bash
======MENU=======
1. Tambah
2. Kurang
3. Kali
4. Quit
Pilihan: 1
Input angka 1: 1
Input angka 2: 4
```

Output: (Hasil kalkulasi adalah 5 dari 1 + 4)
```bash
*
*
*
*
*****
```

### Rubrik Penilaian Program
1. Mampu melakukan operasi penjumlahan, pengurangan, dan perkalian pada bilangan integer: 20%
2. Mampu menampilkan pola / shape sesuai dengan hasil operasi tersebut: 30%
3. Mampu melakukan error handling: 10%
4. Mampu membuat interface menu yang bagus: 10%
5. Mampu membuat program berjalan terus: 20%
6. Mampu melakukan input dengan benar: 10%

### Video Demo Program
Link: https://youtu.be/BjjGvLc-56A