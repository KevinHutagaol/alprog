#include <stdio.h>

typedef enum {
    AKTIF,
    CUTI,
    LULUS
} StatusAkademik;

typedef struct {
    char nama[50];
    int usia;
    float ipk;
    StatusAkademik status;
} Mahasiswa;

void tampilkanData(Mahasiswa *mhs, int jumlah);

void tambahData(Mahasiswa *mhs, int jumlah);

void bacaData(Mahasiswa *mhs, int *jumlah);

void simpanData(Mahasiswa *mhs, int jumlah);

int main() {
    // Inisialisasi data mahasiswa awal
    Mahasiswa mhs[3] = {
        {"BudiBudiono", 20, 3.85f, AKTIF},
        {"BayuBayuawan", 19, 3.50f, AKTIF},
        {"SariSariwati", 22, 3.66f, LULUS}
    };

    tambahData(mhs, 3);

    return 0;
}

void tampilkanData(Mahasiswa *mhs, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        // Iterasi tiap record
        printf("Nama: %s, Usia: %d, IPK: %.2f, Status: %s\n",
               mhs[i].nama,
               mhs[i].usia,
               mhs[i].ipk,
               (mhs[i].status == AKTIF) ? "Aktif" : (mhs[i].status == CUTI) ? "Cuti" : "Lulus");
    }
}

void tambahData(Mahasiswa *mhs, int jumlah) {
    FILE *file = fopen("mahasiswa.txt", "a"); // Buka file dalam mode append
    if (file == NULL) return; // Cek apakah file terbuka
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%s %d %.2f %d\n", // Tulis data ke akhir file
                mhs[i].nama,
                mhs[i].usia,
                mhs[i].ipk,
                mhs[i].status);
    }
    fclose(file); // Tutup file
}

void bacaData(Mahasiswa *mhs, int *jumlah) {
    FILE *file = fopen("./mahasiswa.txt", "r"); // Buka file untuk baca
    if (file == NULL) return; // Cek keberhasilan buka file
    *jumlah = 0; // Inisialisasi jumlah data
    while (fscanf(file, "%s %d %f %d", // Baca tiap baris dengan format:
                  mhs[*jumlah].nama, // nama (string)
                  &mhs[*jumlah].usia, // usia (integer)
                  &mhs[*jumlah].ipk, // IPK (float)
                  (int *) &mhs[*jumlah].status) != EOF) {
        // status (enum)
        (*jumlah)++; // Tambah jumlah data
    }
    fclose(file); // Tutup file
}

void simpanData(Mahasiswa *mhs, int jumlah) {
    FILE *file = fopen("mahasiswa.txt", "w"); // Membuka file teks untuk menulis
    if (file == NULL) return; // Cek apakah file berhasil dibuka
    for (int i = 0; i < jumlah; i++) {
        // Iterasi setiap data mahasiswa
        fprintf(file, "%s %d %.2f %d\n", // Tulis data dengan format:
                mhs[i].nama, // nama (string)
                mhs[i].usia, // usia (integer)
                mhs[i].ipk, // IPK (float)
                mhs[i].status); // status (integer)
    }
    fclose(file); // Menutup file
}
