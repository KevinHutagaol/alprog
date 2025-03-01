---
title: TP_Modul4_Structs

---

---
title: TP_Modul4_Structs

---

# Tugas Pendahuluan Modul 4 - Structs

```
Nama  : [your name here]
NPM   : [your NPM here]
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 1.

## Teori

### 1. Bagaimana cara mendeklarasikan, menginisialisasi, dan mengakses anggota dari sebuah struct?  (15 poin)

---

**Structures**

`struct` merupakan data type yang berisi variable dengan data type lainnya (dapat juga berupa `struct` lain)

```c++
// mendefinisi, sebuah struct
struct titik {
    int x, y; 
    float nilai;
};

// mendeklarasi dan menginisialisasi sebuah struct
struct titik titik_akhir = {5, 6, 12.5};

// cara lain untuk menginisialisasi struct
struct titik titik_awal = {.x = 5, .y = 6, .nilai = 12.5};
```

`struct` dapat mengandung `struct` didalamnya

```c++
struct garis {
    struct titik a, b; 
};

struct garis garis_pertama = { {1,2}, {5,6} };
```

Elemen pada sebuah struct dapat diakses dengan operator dot:

```c++
garis_pertama.a.x = 10; 
garis_pertama.a.y = 20; 
```

### Referensi:

- [1] "Structures" The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Structures [Accessed: Mar. 01, 2025]
- [2] B. W. Kernighan and D. M. Ritchie, "Structures", in *The C programming language*, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.
- [3] K. N. King, "Structures, Unions, and Enumerations" in _C programming: a modern approach, Second edition_. New York
  London: W.W. Norton & Company, 2008.

---

### 2. Jelaskan apa itu nested struct (struct dalam struct) dan bagaimana cara implementasinya! (10 poin)

`(Note: Bisa menggunakan typedef agar struct jadi lebih ringkas)`

Nested struct merupakan sebuah struct yang salah satu elemennya juga merupakan struct. Nested struct berguna dalam
menyimpan struktur data yang lebih kompleks

```c++
struct Person_name {
    char first[50];
    char middle[50];
    char last[50];
}

struct Person {
    struct Person_name name;
    int age;
}
```

Pada contoh diatas, `struct person` memiliki `struct peson_name` didalamnya, sehingga merupakan nested struct.

Pengaksesan nilai elemen dilakukan seperti struct biasa

```c++

struct Person person1;

person1.age = 50;

// akan mengakses struct name yang dimiliki person1, yang didalamnya terdapat elemen last
strcpy(person1.name.last, "Bob");

strcpy(person1.name.first, "Budi");

```

### Referensi:

- [4] K. N. King, "Nested Arrays and Structures" in _C programming: a modern approach, Second edition_. New York London:
  W.W. Norton & Company, 2008.
- [5] "Structures" The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Structures [Accessed: Mar. 01, 2025]
- [6] B. W. Kernighan and D. M. Ritchie, "Structures", in *The C programming language*, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.

---

### 3. Bagaimana cara mengirimkan struct sebagai parameter ke dalam fungsi (by value dan by reference)? Contohkan dengan singkat! (15 poin)

Sebuah struct dapat diberikan langsung kepada fungsi, hal ini akan membuat copy dari struct tersebut (pass-by-value)

```c++
typedef struct {
    double x;
    double y;
} Point;

double distance_by_value(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

Point p1 = {1.0, 2.0};
Point p2 = {4.0, 6.0};

double distance = distance_by_value(p1, p2);
```

Metode pass-by-value akan membuat copy dari sebuah data structure yang dapat berukuran besar, hal ini menyebabkan
pengunaan memori yang kurang efisien.

Struct dapat juga diberikan dengan metode pass-by-reference.

```c++
double distance_by_reference(Point *a, Point *b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}


Point p1 = {1.0, 2.0};
Point p2 = {4.0, 6.0};

double distance = distance_by_reference(&p1, &p2);

```

Fungsi yang menggubakan parameter pass-by-reference juga dapat memodifikasi nilai elemen secara langsung.

```c++
void move_point(Point *a, int distance) {
    a->x += distance;
    a->y += distance;
}
```

### Referensi:

- [7] B. W. Kernighan and D. M. Ritchie, "Structures and Functions", in *The C programming language*, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.
- [8] “Structure Pointer in C” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/structure-pointer-in-c/
  [Accessed: Mar. 01, 2025.]
- [9] "Structures" The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Structures [Accessed: Mar. 01, 2025]

### 4. Apakah perbedaan dari metode akses anggota struct lewat titik (.) dibanding dengan panah (->)?  (10 poin)

Operator dot `.` digunakan untuk mengakses elemen dari sebuah struct, sedangkan operator `->` digunakan untuk mengakses
sebuah elemen yang ditunjuk oleh pointer kepada struct. 

Operator `->` pada sebuah pointer ekivalen kepada melakukan indirection, lalu mengakses elemennya:

```c++
typedef struct {
  int x;
  int y;
} Point;

Point a = {1,2};
// Mengakses elemen dengan .
a.x = 3;

Point *a_ptr = &a;

// Mengakses elemen dengan ->
a_ptr->y = 5;
// ekivalen dengan operator ->
(*a_ptr).y = 5; 
```

### Referensi:

- [10] B. W. Kernighan and D. M. Ritchie, "Structures and Functions", in *The C programming language*, 2nd ed.
  Englewood Cliffs, N.J: Prentice Hall, 1988.
- [11] “Structure Pointer in C” GeeksforGeeks. [Online].
  Available: https://www.geeksforgeeks.org/structure-pointer-in-c/
  [Accessed: Mar. 01, 2025.]
- [12] "Structures" The GNU C Reference Manual. [Online].
  Available: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Structures [Accessed: Mar. 01, 2025]

---

## Programming

### 5. Buatlah sebuah program yang dapat memanage data mahasiswa menggunakan array of structs dengan nested structs! (30 poin)

#### Spesifikasi:

- Program akan memberi opsi untuk menambahkan siswa baru atau menampilkan semua siswa yang ada dalam database
- Boleh menggunakan array dengan dynamic memory allocation agar jumlah mahasiswa fleksibel, atau boleh juga menggunakan
  array dengan size 100 (max 100 mahasiswa)
- Implementasikan nested structs untuk pemisahan data.

* Struct `AkademikInfo` yang berisi:
* Semester (int)
* IPK (float / double)
* Jurusan (string)
  Struct `PersonalInfo` yang berisi:
* Nama (string)
* NPM (string)
* Alamat (string)
  Struct `Mahasiswa` yang berisi:
* PersonalInfo (struct)
* AkademikInfo (struct)
* Kesibukan (string)

Contoh:

```c++
Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


1


List Mahasiswa
---------------


Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


2


Add Mahasiswa
---------------
Data Personal:
Nama : Theory
NPM : 2307274500
Alamat : Jl M Kahfi II 
Jurusan : Teknik Elektro
Semester : 4
IPK : 3.88
Kesibukan : Magang di BNI
Mahasiswa ditambahkan!


Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


2


Add Mahasiswa
---------------
Data Personal:
Nama : Hendy Bengkel
NPM : 2408040201
Alamat : Bengkel
Jurusan : Teknik Elektro
Semester : 2
IPK : 2.1
Kesibukan : Bengkel
Mahasiswa ditambahkan!


Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


1


List Mahasiswa
---------------
1. Theory - 2307274500
Alamat: Jl M Kahfi II
Jurusan: Teknik Elektro
Semester 4
IPK 3.88
Kesibukan: Magang di BNI

2. Hendy Bengkel - 2408040201
Alamat: Bengkel
Jurusan: Teknik Elektro
Semester 2
IPK 2.1
Kesibukan: Bengkel
   
   
Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


3


Program selesai!
```

Kode

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_BUF_SIZE 2
#define MAX_STR_SIZE 256


typedef struct {
    char name[MAX_STR_SIZE];
    char npm[MAX_STR_SIZE];
    char address[MAX_STR_SIZE];
} PersonalInformation;

typedef struct {
    int semester;
    float gpa;
    char major[MAX_STR_SIZE];
} AcademicInformation;

typedef struct {
    PersonalInformation personal_information;
    AcademicInformation academic_information;
    char activities[MAX_STR_SIZE];
} Student;

int editor(Student **student_data_arr, int *num_students);

void print_student_data(Student **student_data_arr, int num_students);

void add_student_data(Student **student_data_arr, int *num_students);

int main() {
    int current_buffer_size = MIN_BUF_SIZE;
    Student *student_database = (Student *) malloc(current_buffer_size * sizeof(Student));
    if (student_database == NULL) {
        printf("Memory allocation error\n");
        return -1;
    }

    int num_students = 0;
    for (;;) {
        if (num_students == current_buffer_size) {
            current_buffer_size = current_buffer_size + (current_buffer_size / 2);
            void *temp = realloc(student_database, current_buffer_size * sizeof(Student));
            if (temp == NULL) {
                printf("Memory allocation error\n");
                free(student_database);
                exit(1);
            }
            student_database = temp;
        }

        int loop_flag = editor(&student_database, &num_students);
        if (loop_flag == 0) {
            break;
        }
    }

    free(student_database);
    return 0;
}


int editor(Student **student_data_arr, int *num_students) {
    printf("----------------\n");
    printf("Student Database\n");
    printf("----------------\n");
    printf("  1. Show students data\n");
    printf("  2. New student\n");
    printf("  3. Exit\n");

    int choice = 0;
    printf("Enter option: ");
    scanf(" %d", &choice);

    while (getchar() != '\n') {
    }

    switch (choice) {
        case 1:
            print_student_data(student_data_arr, *num_students);
            break;
        case 2:
            add_student_data(student_data_arr, num_students);
            break;
        case 3:
            printf("Exiting editor........\n\n");
            return 0;
        default:
            printf("Invalid Choice, try again\n\n");
    }

    return 1;
}

void add_student_data(Student **student_data_arr, int *num_students) {
    char buffer[MAX_STR_SIZE];
    printf("Enter student's data:\n");

    printf("  Name: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].personal_information.name, buffer);

    printf("  NPM: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].personal_information.npm, buffer);

    printf("  Address: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].personal_information.address, buffer);

    printf("  Major: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].academic_information.major, buffer);

    printf("  Semester: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    (*student_data_arr)[*num_students].academic_information.semester = strtol(buffer, NULL, 10);

    printf("  GPA : ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    (*student_data_arr)[*num_students].academic_information.gpa = strtof(buffer, NULL);

    printf("  Activities: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].activities, buffer);

    *num_students += 1;
}

void print_student_data(Student **student_data_arr, const int num_students) {
    printf("Data of students:\n");
    printf("----------------\n");
    if (num_students == 0) {
        printf("Empty student data\n\n");
        return;
    }
    for (int i = 0; i < num_students; i++) {
        printf("%d %s - %s\n", i + 1, (*student_data_arr)[i].personal_information.name,
               (*student_data_arr)[i].personal_information.npm);
        printf("  Address: %s\n", (*student_data_arr)[i].personal_information.address);
        printf("  Major: %s\n", (*student_data_arr)[i].academic_information.major);
        printf("  Semester: %d\n", (*student_data_arr)[i].academic_information.semester);
        printf("  GPA: %.2f\n", (*student_data_arr)[i].academic_information.gpa);
        printf("  Activities: %s\n", (*student_data_arr)[i].activities);
        printf("\n");
    }
}
```

SS Output Program Kalian :
![Output Program](https://hackmd.io/_uploads/By1FBoxoJg.png)