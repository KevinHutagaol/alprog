---
title: CS Module 3 - Pointers v2

---

# Case Study 3 - Caesar Cipher (RABU)

## Latar Belakang

Upin dan Ipin dah besar sedang mengerjakan PR Cybersecurity kelas 50 SD mereka.

![maxresdefault](https://hackmd.io/_uploads/rkqSNaqcyx.jpg)

Pada PR kali ini, mereka harus mentranslasi sebuah string dengan algoritma Caesar Cipher yang telah dimodifikasi. Akan tetapi, karena ada jadwal tanding bola melawan negara sebelah, Upin Ipin dah besar meminta bantuanmu untuk menyelesaikan tugas mereka.

![Caesar_cipher_left_shift_of_3.svg](https://hackmd.io/_uploads/Bkyn2Q3cyl.png)

#### Sistematis Program
- String akan "digeser" sejauh input pengguna
- Modifikasi Upin Ipin mencakup beberapa karakter spesial yang harus diperhatikan:
1. A / a -> 4
(Contoh: Jika string sudah digeser dan outputnya berisi huruf A atau a, maka A / a tersebut akan diubah menjadi 4)
2. E / e -> 3
3. I / i -> 1 (satu)
4. U / u -> V
5. O / o -> 0
6. Spasi -> Spasi (tetap / diabaikan)

(Note: Kalian bisa mengecek nilai masing-masing karakter dalam int lewat tabel ASCII)

![gambar](https://hackmd.io/_uploads/Skbpy4291e.png)


## Spesifikasi

FORMAT INPUT
- Baris pertama berupa sebuah string.
- Baris kedua berupa jarak perpindahan string (bisa negatif, bisa 0).

FORMAT OUTPUT
- Output berupa string yang sudah ditranslasi
- Gunakan function bertipe **void** untuk menggeser string dari pengguna (wajib void!).
- Gunakan call by reference untuk function tersebut (wajib call by reference / menggunakan pointer!).
- Input dan Output program berada di main function.
- **Tidak perlu menangani kasus dimana string digeser hingga melewati huruf Z / sebelum huruf A**
- **Asumsikan bahwa pengguna tidak akan memasukkan karakter selain alfabet dan spasi (tidak perlu handling input simbol/angka dll)**
- Jika lewat batasan alfabet, print "Out of Bounds!"

HINT
- Gunakan pointer sebagai parameter function untuk melakukan pemanggilan call by reference

## Contoh Output 

1
```
Halo Upin & Ipin (dah besar)!
Masukkan String: halo
Masukkan Jarak Geser: 1

---

String Cipher: 1bmp
```

h a l o
i b m p (Shift)
1 b m p (i -> 1, sesuai ketentuan)

2
```
Halo Upin & Ipin (dah besar)!
Masukkan String: Bombe
Masukkan Jarak Geser: -1

---

String Cipher: 4nl4d
```
B o m b e
A n l a d (Shift ke belakang)
4 n l 4 d (a dan A -> 4, sesuai ketentuan)

3
```
Halo Upin & Ipin (dah besar)!
Masukkan String: yyyy
Masukkan Jarak Geser: 10

---

Out of Bounds!
```

y shift 10 akan melewati batas alfabet

4
```
Halo Upin & Ipin (dah besar)!
Masukkan String: Jarjit
Masukkan Jarak Geser: 2

---

String Cipher: Lctlkv
```

5
```
Halo Upin & Ipin (dah besar)!
Masukkan String: Tadika Mesra
Masukkan Jarak Geser: 4

---

String Cipher: X3hm03 Q1wv3
```
T a d i k a M e s r a 
X e h m o e Q i w v e
X 3 h m 0 3 Q 1 w v 3

6
```
Halo Upin & Ipin (dah besar)!
Masukkan String: Atromen Ribut
Masukkan Jarak Geser: 0

---

String Cipher: Atromen Ribut
```

## Pengumpulan

Dikumpulkan dalam format .c

Format nama : 
```CS_ALPROG[NomorModul]_NamaLengkap_NPM.c```

Semangat mengerjakan! 🚀