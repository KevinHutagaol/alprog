# Tugas Pendahuluan Modul 8

```
Nama  : Kevin Imanuel Hutagaol 
NPM   : 2306156763
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Jelaskan apa itu class dan object. Berikan contoh penggunaan class dan object serta tunjukkan bagian mana yang merupakan class ataupun object dalam bahasa pemrograman C++! (10 poin)

---

- Class :
  Sebuah blueprint atau template untuk membuat object. Class mendefinisikan properti (atribut/variabel data) dan
  perilaku (metode/fungsi) yang akan dimiliki oleh object yang dibuat darinya.

- Object :
  Sebuah instance dari class. Object memiliki state (nilai dari atributnya) dan behavior (metode yang bisa
  dijalankannya) sesuai dengan definisi class-nya.

Secara analogi class merupakan sebuah cetakan, dan object merupakan sesuatu yang telah di cetak

```c++
#include <iostream>
#include <string>
using namespace std;

// Bagian Class 
// Mendefinisikan blueprint 'Mobil'
class Mobil {
public: 
    string merek;
    int tahun;

    void tampilkanInfo() {
        cout << "Merek: " << merek << endl;
        cout << "Tahun: " << tahun << endl;
    }
}; 

int main() {
    // Object 
    // Membuat sebuah object (mobilSaya) dari class Mobil
    Mobil mobilSaya; 

    mobilSaya.merek = "Toyota";
    mobilSaya.tahun = 2023;

    cout << "Info Mobil Saya:" << endl;
    mobilSaya.tampilkanInfo();
    return 0;
}
```

### Referensi:

- [1] “Object Oriented Programming in C++ | GeeksforGeeks.”  [Online].
  Available: https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/ [Accessed: Apr. 21, 2025.]
- [2] “Introduction of Object Oriented Programming,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/ [Accessed: Apr. 21, 2025.]
- [3] B. Stroustrup. "Classes" in A tour of C++, Third edition. in C++ in-depth series. Boston: Addison-Wesley, 2023.

---

### 2. Jelaskan apa itu constructor. Berikan contoh penggunaan constructor dalam bahasa pemrograman C++! (10 poin)

- Merupakan sebuah metode spesial di dalam class yang namanya sama dengan nama class itu sendiri. Constructor tidak
  memiliki tipe return (bukan void).

- Constructor berfungsi menginisialisasi (memberikan nilai awal) pada atribut-atribut object saat object tersebut
  pertama kali dibuat. Constructor dipanggil secara otomatis saat membuat sebuah object dari class tersebut.

```c++
#include <iostream>
#include <string>

using namespace std;

//  Class Mobil dengan Constructor 
class Mobil {
public: 
    // Atribut (properti)
    string merek;
    int tahun;

    //  Constructor dari Mobil 
    Mobil(string m, int t) {
        cout << "Constructor telah dipanggil" << endl;
        merek = m; 
        tahun = t; 
    } 

    // Metode (perilaku)
    void tampilkanInfo() {
        cout << "Merek: " << merek << endl;
        cout << "Tahun: " << tahun << endl;
    }
}; 

int main() {
    //  Membuat Object Menggunakan Constructor
    Mobil mobilSaya("Toyota", 2023);

    // Object sudah terinisialisasi 
    cout << "\nInfo Mobil Saya:" << endl;
    mobilSaya.tampilkanInfo();

    return 0;
}
```

### Referensi:

- [4] “Object Oriented Programming in C++ | GeeksforGeeks.”  [Online].
  Available: https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/ [Accessed: Apr. 21, 2025.]
- [5] “Introduction of Object Oriented Programming,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/ [Accessed: Apr. 21, 2025.]
- [6] B. Stroustrup. "Classes" in A tour of C++, Third edition. in C++ in-depth series. Boston: Addison-Wesley, 2023.

---

### 3. Jelaskan apa itu encapsulation dan manfaatnya sebagai salah satu konsep OOP! Berikan contoh kode encapsulation dalam C++! (10 poin)

- Encapsulation merupakan salah satu konsep di OOP dimana sebuah data (atribut) atau metode akan diencapsulate (
  dibunguks) dalam sebuah class

- Encapsulation memastikan detail dan implementasi internal sebuah class akan tersembunyi (private) dah hanya mengexpose
  fungsionalitas yang diinginkan (public)

Manfaat:

- Melindungi data internal dari modifikasi langsung (dapat tidak sah), misalnya menjaga nilai agar diatas 0
- Menambah kontrol atas atribut yang ada melalui getter dan setter
- Menyembunyikan implementasi internal, sedangkan interface public tetap sama
- Mengurangi kompleksitas karena kode external hanya butuh mengakses melalui interface public

```c++
#include <iostream>
#include <string>

using namespace std;

class Mobil {
private: // Atribut private
    string merek;
    int tahun;

public: // Interface public
    Mobil(string m, int t) {
        cout << "Constructor Mobil dipanggil." << endl;
        // Menggunakan setter untuk inisialisasi agar validasi terpanggil
        setMerek(m);
        setTahun(t);
    }

    //  Getter Methods (Akses Baca ke Data Private) 
    string getMerek() {
        return merek;
    }

    int getTahun() {
        return tahun;
    }

    // Method Setter (dapat dilakukan validasi)
    void setMerek(string m) {
        if (!m.empty()) { // validasi  nama mobil
            merek = m;
        } else {
            cout << "Error: Merek tidak boleh kosong!" << endl;
        }
    }

    void setTahun(int t) {
        if (t > 1885 && t <= 2024) { // validasi tahun
            tahun = t;
        } else {
            cout << "Error: Tahun tidak valid (" << t << ")!" << endl;
        }
    }

    // Metode publik lain
    void tampilkanInfo() {
        // Mengakses data private dari dalam class itu sendiri
        cout << "Merek: " << merek << endl;
        cout << "Tahun: " << tahun << endl;
    }
}; 

int main() {
    Mobil mobilSaya("Toyota", 2023);

    cout << "\nInfo Awal:" << endl;
    mobilSaya.tampilkanInfo();

    // Mengakses data melalui metode publik 
    cout << "\nMengambil merek: " << mobilSaya.getMerek() << endl;

    // --- Mencoba mengubah data melalui setter (dengan validasi) ---
    cout << "\nMencoba mengubah tahun menjadi 2025..." << endl;
    mobilSaya.setTahun(2025); // Ini akan menampilkan error karena > 2024

    cout << "\nMencoba mengubah tahun menjadi 2020..." << endl;
    mobilSaya.setTahun(2020); // Ini berhasil

    return 0;
}
```

### Referensi:

- [7] “Object Oriented Programming in C++ | GeeksforGeeks.”  [Online].
  Available: https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/ [Accessed: Apr. 21, 2025.]
- [8] “Introduction of Object Oriented Programming,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/ [Accessed: Apr. 21, 2025.]
- [9] B. Stroustrup. "Classes" in A tour of C++, Third edition. in C++ in-depth series. Boston: Addison-Wesley, 2023.

---

### 4. Jelaskan apa itu access modifier dan jelaskan perbedaan antara public, private, dan protected! (10 poin)

Access modifier merupakan keyword yang berfungsi dalam menentukan jenis encapsulation dari sebuah atribut.method

Encapsulation dilakukan dengan access specifier:

- `private`:
  Atribut/Method hanya dapat diakses di dalam class itu sedir. Menyembunyikan implementasi dan data

- `public`:
  Dapat dikases dimana saja (diluar class). Membuat interface yang dapat digunakan diatas objek.

- `protected`:
  Mirip seperti `private`, dimana tidak bisa diakses dari luar class, tetapi dapat diakses dari sebuah child class (
  berguna bagi inheritance)

### Referensi:

- [10] “Object Oriented Programming in C++ | GeeksforGeeks.”  [Online].
  Available: https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/ [Accessed: Apr. 21, 2025.]
- [11] “Introduction of Object Oriented Programming,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/ [Accessed: Apr. 21, 2025.]
- [12] B. Stroustrup. "Classes" in A tour of C++, Third edition. in C++ in-depth series. Boston: Addison-Wesley, 2023.

---

### 5. Jelaskan apa itu abstraction dalam OOP! Tunjukkan contoh kode abstraction lewat header file dalam C++! (10 poin)

Abstraksi merupakan konsep dalam OOP dimana detail implementasi yang kompleks akan disembunyikan, dan hanya fitur yang
relevan yang dibuka kepada penggunanya.

Abstraksi di c++ dapat dilakukan melalui header file:

File : Mobil.h

```c++
// mobil.h - Mendefinisikan interface class Mobil

#ifndef MOBIL_H // Include guard untuk mencegah multiple inclusion
#define MOBIL_H

#include <string> 
using namespace std;

class Mobil {
private: 
    string merek;
    int tahun;
    bool mesinMenyala;

public: 
    Mobil(string m, int t);

    // Metode publik (deklarasi apa saja yang dapat dilakukan)
    void startMesin();
    void stopMesin();
    void tampilkanInfo();
    string getMerek(); 
    bool isMesinMenyala(); 

}; 

#endif // MOBIL_H
```

File : Mobil.cpp

```c++
// mobil.cpp - Mengimplementasikan metode class Mobil

#include "mobil.h" // Sertakan header yg berisi deklarasi
#include <iostream> 
using namespace std;

Mobil::Mobil(string m, int t) {
    merek = m;
    tahun = t;
    mesinMenyala = false; 
}

void Mobil::startMesin() {
    if (!mesinMenyala) {
        mesinMenyala = true;
        cout << merek << ": Mesin dinyalakan" << endl;
    } else {
        cout << merek << ": Mesin sudah menyala." << endl;
    }
}

void Mobil::stopMesin() {
    if (mesinMenyala) {
        mesinMenyala = false;
        cout << merek << ": Mesin dimatikan" << endl;
    } else {
        cout << merek << ": Mesin sudah mati" << endl;
    }
}

void Mobil::tampilkanInfo() {
    cout << "--- Info Mobil ---" << endl;
    cout << "Merek: " << merek << endl;
    cout << "Tahun: " << tahun << endl;
    cout << "Status Mesin: " << (mesinMenyala ? "Menyala" : "Mati") << endl;
}

string Mobil::getMerek() {
    return merek;
}

bool Mobil::isMesinMenyala() {
    return mesinMenyala;
}
```

### Referensi:

- [13] “Object Oriented Programming in C++ | GeeksforGeeks.”  [Online].
  Available: https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/ [Accessed: Apr. 21, 2025.]
- [14] “Introduction of Object Oriented Programming,” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/ [Accessed: Apr. 21, 2025.]
- [15] B. Stroustrup. "Classes" in A tour of C++, Third edition. in C++ in-depth series. Boston: Addison-Wesley, 2023.

## Programming

> Gunakan abstraction lewat header file untuk kode di bawah ini.

### 1. Buatlah enumeration bernama `Jurusan` dengan isi sebagai berikut:

```cpp
enum Jurusan {
    ELEKTRO,
    BIOMEDIK,
    KOMPUTER
};
```

---

### 2. Buatlah class bernama `Dosen` dengan isi sesuai deskripsi berikut:

- Class ini memiliki atribut private `name` dan `id`.
- Buat **constructor** untuk mengisi kedua atribut tersebut.
- Tambahkan getter `getName()` dan setter `setName()` serta `setId()` untuk encapsulation.

---

### 3. Buatlah class bernama `Kelas` dengan atribut private:

- `namaKelas` (string)
- `nilai` (float)
- `sks` (int)
- `dosen` (objek dari class `Dosen`)

Isi dari class:

- Buat constructor yang menerima semua atribut sebagai parameter.
- Buat method `showDetail()` yang menampilkan informasi nama kelas, nama dosen pengajar, SKS, dan nilai.
- Tambahkan method `getNilai()`, `getSKS()`, serta setter `setNilai()`, `setSKS()`, dan `setNamaKelas()`.

Contoh output method `showDetail()`:

```bash
Kelas: Alpro, Nilai: 3.5, SKS: 3, Dosen: Mr. Budi
```

---

### 4. Buatlah class `Mahasiswa` dengan atribut private:

- `nama` (string)
- `id` (int)
- `alprog`, `sisben`, `matdis`, `fislis` (tipe Kelas)
- `jurusan` (tipe enum Jurusan)

Isi dari class:

- Constructor untuk mengisi semua atribut.
- Method `getIPK()` yang menghitung IPK berdasarkan rumus:

```txt
IPK = (nilai * sks dari semua mata kuliah) / total sks
```

- Method `showDetail()` yang menampilkan:
    - Nama mahasiswa
    - ID
    - Jurusan (sebagai string, seperti "Teknik Elektro", dll)
    - IPK dengan format dua angka di belakang koma
    - Informasi seluruh kelas mahasiswa (panggil `showDetail()` dari masing-masing objek kelas)

Contoh output:

```bash
Nama: Ali, ID: 12345, Jurusan: Teknik Elektro
Kelas: Alpro, Nilai: 3.5, SKS: 3, Dosen: Mr. Budi
Kelas: Sisben, Nilai: 3.7, SKS: 3, Dosen: Mr. Thomas
Kelas: Matdis, Nilai: 3.9, SKS: 3, Dosen: Ms. Puff
Kelas: Fislis, Nilai: 3.6, SKS: 2, Dosen: Ms. Sandy
IPK: 3.66
```

---

### 5. Buatlah `main.cpp` dan lakukan hal berikut:

- Buat 4 objek dosen:
-

| Object      | Nama Dosen | ID |
|-------------|------------|----|
| dosenAlpro  | Mr. Budi   | 10 |
| dosenSisben | Mr. Thomas | 11 |
| dosenMatdis | Ms. Puff   | 12 |
| dosenFislis | Ms. Sandy  | 13 |

- Buat 4 objek kelas:

| Object | Nama Kelas            | Nilai | SKS | Dosen       |
|--------|-----------------------|-------|-----|-------------|
| alprog | Algoritma Pemrograman | bebas | 3   | dosenAlpro  |
| sisben | Sistem Benam          | bebas | 3   | dosenSisben |
| matdis | Matematika Diskrit    | bebas | 3   | dosenMatdis |
| fislis | Fisika Listrik        | bebas | 2   | dosenFislis |

- Buat 1 objek `Mahasiswa` dengan nama bebas yang mengikuti 4 objek kelas yang sudah diset di atas.

---

### 6. Jalankan program dan pastikan output menampilkan:

- Informasi setiap kelas (`alprog`, `sisben`, `matdis`, `fislis`)
- Informasi lengkap mahasiswa

Contoh output:

```bash
Nama: Burhan, ID: 12345, Jurusan: Teknik Elektro
Kelas: Alprog, Nilai: 3.8, SKS: 3, Dosen: Pak Budi
Kelas: Fismek, Nilai: 3.5, SKS: 3, Dosen: Bu Sari
Kelas: Matdis, Nilai: 4, SKS: 2, Dosen: Pak Budi
Kelas: Fislis, Nilai: 3.6, SKS: 2, Dosen: Bu Sari
IPK: 3.71
```

---

Nama File 1 : `main.cpp`

```c++
//
// Created by kevin on 21/04/2025.
//

#include <iostream>
#include "Dosen.h"
#include "Kelas.h"
#include "Mahasiswa.h"
#include "Jurusan.h"

using namespace std;

int main() {

    Dosen dosenAlprog("Mr. Budi", 10);
    Dosen dosenSisben("Mr. Thomas", 11);
    Dosen dosenMatdis("Ms. Puff", 12);
    Dosen dosenFislis("Ms. Sandy", 13);

    Kelas alprog("Algoritma Pemrograman", 90.0, 3, dosenAlprog);
    Kelas sisben("Sistem Benam", 85.0, 3, dosenSisben);
    Kelas matdis("Matematika Diskrit", 74.0, 3, dosenMatdis);
    Kelas fislis("Fisika Listrik", 92, 2, dosenFislis);

    Mahasiswa mahasiswa("budi tabudi",11922, alprog, sisben, matdis, fislis, ELEKTRO);

    mahasiswa.showDetails();
    float ipk = mahasiswa.getIPK();
    cout << "IPK: " << ipk << endl;
}
```

Nama File 2 : `Dosen.h`

```c++
#ifndef DOSEN_H
#define DOSEN_H

#include <string>
using namespace std;

class Dosen {
private:
    string name;
    int id{};

public:
    Dosen(string name, int id);

    string getName() const;

    void setName(string name);

    void setId(int id);
};

#endif //DOSEN_H
```

Nama File 3 : `Dosen.cpp`

```c++
#include "Dosen.h"

Dosen::Dosen(string name, int id): name(name), id(id) {}

string Dosen::getName() const {
    return name;
}

void Dosen::setName(string name) {
    this->name = name;
}

void Dosen::setId(int id) {
    this->id = id;
}
```

Nama File 4 : `Kelas.h`

```c++
#ifndef KELAS_H
#define KELAS_H
#include "Dosen.h"
#include <string>

class Kelas {
private:
    string namaKelas;
    float nilai;
    int sks;
    Dosen dosen;

public:
    Kelas(string namaKelas, float nilai, int sks, Dosen dosen);

    void showDetails();

    [[nodiscard]] float getNilai() const;

    [[nodiscard]] int getSks() const;

    void setNilai(float nilai);

    void setSks(int sks);

    void setNamaKelas(string namaKelas);
};

#endif //KELAS_H
```

Nama File 5 : `Kelas.cpp`

```c++
#include "Kelas.h"
#include <iostream>

Kelas::Kelas(string namaKelas, float nilai, int sks, Dosen dosen): namaKelas(namaKelas), nilai(nilai), sks(sks),
                                                                   dosen(dosen) {
}

void Kelas::showDetails() {
    cout << "Kelas: " << this->namaKelas << ", Nilai: " << this->nilai << ", SKS: " << this->sks << ", Dosen: " << this->dosen.getName() << endl;
}

float Kelas::getNilai() const {
    return this->nilai;
};

int Kelas::getSks() const {
    return this->sks;
}

void Kelas::setNilai(float nilai) {
    this->nilai = nilai;
}

void Kelas::setSks(int sks) {
    this->sks = sks;
}

void Kelas::setNamaKelas(string namaKelas) {
    this->namaKelas = namaKelas;
}
```

Nama File 6: `Mahasiswa.h`

```c++
#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
#include "Kelas.h"
#include "Jurusan.h"

using namespace std;

class Mahasiswa {
private:
    string nama;
    int id;
    Kelas alprog;
    Kelas sisben;
    Kelas matdis;
    Kelas fislis;

    Jurusan jurusan;

public:
    Mahasiswa(string nama, int id, Kelas alprog, Kelas sisben, Kelas matdis, Kelas fislis, Jurusan jurusan);

    [[nodiscard]] float getIPK() const;

    void showDetails();

};

#endif //MAHASISWA_H
```

Nama File 7: `Mahasiswa.cpp`

```c++
#include "Mahasiswa.h"
#include <iostream>


Mahasiswa::Mahasiswa(string nama, int id, Kelas alprog, Kelas sisben, Kelas matdis, Kelas fislis, Jurusan jurusan)
    : nama(nama), id(id), alprog(alprog), sisben(sisben), matdis(matdis), fislis(fislis), jurusan(jurusan) {
}


float Mahasiswa::getIPK() const {
    int total_sks = this->alprog.getSks() + this->sisben.getSks() + this->matdis.getSks() + this->fislis.getSks();

    float mutu_alprog = this->alprog.getNilai() / 25 * (float) this->alprog.getSks();
    float mutu_sisben = this->sisben.getNilai() / 25 * (float) this->sisben.getSks();
    float mutu_matdis = this->matdis.getNilai() / 25 * (float) this->matdis.getSks();
    float mutu_fislis = this->fislis.getNilai() / 25 * (float) this->fislis.getSks();


    return (mutu_alprog + mutu_sisben + mutu_matdis + mutu_fislis) / (float) total_sks;
}


void Mahasiswa::showDetails() {
    cout << "Nama: " << this->nama << ", ID: " << this->id << ", Jurusan: " <<
    (this->jurusan == 0
         ? "Teknik Elektro"
         : this->jurusan == 1
               ? "Teknik Komputer"
               : "Teknik Biomedik") << endl;

    this->alprog.showDetails();
    this->sisben.showDetails();
    this->matdis.showDetails();
    this->fislis.showDetails();
}
```

Nama File 8: `Jurusan.h`

```c++
#ifndef JURUSAN_H
#define JURUSAN_H

enum Jurusan {
    ELEKTRO,
    BIOMEDIK,
    KOMPUTER
};


#endif //JURUSAN_H
```

SS Output Program Kalian :
![Output Program](https://hackmd.io/_uploads/HJDbSFXkxe.png)

