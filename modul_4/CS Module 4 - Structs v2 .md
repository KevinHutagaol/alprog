# Case Study 4 - Pinjol 2 (RABU)

## Latar Belakang

Aplikasi pinjol viral terbaru belakangan ini terpaksa gulung tikar karena terlalu banyak peminjam yang gagal bayar dan merugikan perusahaan. Sebagai programmer handal, Anda diminta bos pinjol untuk membangun ulang sistem trackingnya agar kejadian ini tak terulang lagi di aplikasi pinjol berikutnya. 

![hqdefault](https://hackmd.io/_uploads/Syi-XbEo1e.jpg)

Disini, Anda diminta membuat sistem sederhana untuk mencatat data pinjaman dan status tiap peminjam. Sebagai programmer yang efisien, Anda berencana menggunakan **structs** agar database jadi ringkas.

#### Sistematis Program
- Pengguna akan pertama memasukkan jumlah peminjam dalam database (ibaratkan n)

`Note: Tidak diwajibkan memakai dynamic allocation seperti *malloc / calloc* `

- Pengguna kemudian memasukkan data masing-masing peminjam (n peminjam)
- Program menampilkan list peminjam dan data mereka
- Pengguna dapat memajukan waktu untuk mengupdate status pinjaman, atau keluar program

## Spesifikasi

**FORMAT INPUT**
- Baris pertama berupa integer (jumlah peminjam, misalkan n)
- Program meminta data peminjam yang berisi:

a. Nama (String)

b. Alamat (String)

c. No. Telp (String)

d. Pinjaman (Int / Float)

e. Rate Bunga (Float)

Program akan meminta ini sebanyak n kali.

**FORMAT OUTPUT**
- Selain data awal, untuk tiap pengguna, program menghitung `Tagihan` mereka (Jadi, struct akan berisi 7 variabel)
- Program menampilkan data masing-masing peminjam, beserta `tagihan` mereka
- Pengguna bisa 

a. Hitung total tagihan 

b. Tagihan semua orang +500 ribu, 

c. Tagihan semua orang -500 ribu, atau 

d. Exit program

Untuk `tagihan`

$\text{Tagihan} = (\text{Pinjaman Awal} \times (\text{RateBunga} + 1)$

## Contoh Output 

1
```
Jumlah Peminjam : 1

Nama Peminjam 1 : RAJA GALBAY
Alamat Peminjam 1 : Jalanan
No Telp Peminjam 1 : 0812
Pinjaman Peminjam 1 : 2500000
Rate Bunga Peminjam 1 : 0.25

---

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp3125000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

a

Total Tagihan 1 Peminjam:
Rp3125000

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp3125000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

b

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp3625000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

b

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp4125000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

d

Program Selesai!
```

(Note: Tidak wajib memformat rupiah jadi seperti Rp5.000.000 / Rp5.000.000,00, tapi diperbolehkan)

2
```
Jumlah Peminjam : 3

Nama Peminjam 1 : RAJA GALBAY
Alamat Peminjam 1 : Jalanan
No Telp Peminjam 1 : 0810
Pinjaman Peminjam 1 : 2500000
Rate Bunga Peminjam 1 : 0.25

Nama Peminjam 2 : Wasle
Alamat Peminjam 2 : Kutek
No Telp Peminjam 2 : 0811
Pinjaman Peminjam 2 : 1000000
Rate Bunga Peminjam 2 : 0.10

Nama Peminjam 3 : Hakim
Alamat Peminjam 3 : Seluk Beluk
No Telp Peminjam 3 : 0812
Pinjaman Peminjam 3 : 1500000
Rate Bunga Peminjam 3 : 1.50
---

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0810
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp3125000

Peminjam 2
Nama - Alamat : Wasle - Kutek
Telp: 0811
Pinjaman - Rate Bunga : Rp1000000 - 10%
Tagihan Bulan Ini : Rp1100000

Peminjam 3
Nama - Alamat : Hakim - Seluk Beluk
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 150%
Tagihan Bulan Ini : Rp6250000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

a

Total Tagihan 3 Peminjam:
Rp10475000

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0810
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp3125000

Peminjam 2
Nama - Alamat : Wasle - Kutek
Telp: 0811
Pinjaman - Rate Bunga : Rp1000000 - 10%
Tagihan Bulan Ini : Rp1100000

Peminjam 3
Nama - Alamat : Hakim - Seluk Beluk
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 150%
Tagihan Bulan Ini : Rp6250000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

c

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0810
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp2625000

Peminjam 2
Nama - Alamat : Wasle - Kutek
Telp: 0811
Pinjaman - Rate Bunga : Rp1000000 - 10%
Tagihan Bulan Ini : Rp600000

Peminjam 3
Nama - Alamat : Hakim - Seluk Beluk
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 150%
Tagihan Bulan Ini : Rp5750000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

a

Total Tagihan 3 Peminjam:
Rp8975000

Database Pinjol

Peminjam 1
Nama - Alamat : RAJA GALBAY - Jalanan
Telp: 0810
Pinjaman - Rate Bunga : Rp2500000 - 25%
Tagihan : Rp2625000

Peminjam 2
Nama - Alamat : Wasle - Kutek
Telp: 0811
Pinjaman - Rate Bunga : Rp1000000 - 10%
Tagihan Bulan Ini : Rp600000

Peminjam 3
Nama - Alamat : Hakim - Seluk Beluk
Telp: 0812
Pinjaman - Rate Bunga : Rp2500000 - 150%
Tagihan Bulan Ini : Rp5750000

a. Hitung total tagihan 
b. Tagihan semua orang +500 ribu 
c. Tagihan semua orang -500 ribu
d. Exit program

d

Program Selesai!
```


## Pengumpulan

Dikumpulkan dalam format .c

Format nama : 
```CS_ALPROG[NomorModul]_NamaLengkap_NPM.c```

Semangat mengerjakan! 🚀