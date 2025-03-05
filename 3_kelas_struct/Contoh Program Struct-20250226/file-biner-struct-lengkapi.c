#include <stdio.h>

//lengkapi typedef enum dan struct


void simpanKeFileBiner(const char *namaFile , Mahasiswa *mhs , int jumlah) {
	FILE *file = fopen(namaFile , "wb"); // Buka file biner untuk menulis
	if (file) {
		fwrite(mhs , sizeof(Mahasiswa), jumlah , file); // Tulis data ke file biner
		fclose(file); // Tutup file
	}
}

void bacaDariFileBiner(const char *namaFile , Mahasiswa *mhs , int *jumlah) {
	FILE *file = fopen(namaFile , "rb"); // Buka file biner untuk membaca
	if (file) {
		*jumlah = fread(mhs , sizeof(Mahasiswa), 10, file); // Baca hingga 10 record
		fclose(file); // Tutup file
	}
}

void tambahKeFileBiner(const char *namaFile , Mahasiswa *mhs , int jumlah) {
	FILE *file = fopen(namaFile , "ab"); // Buka file biner dalam mode append
	if (file == NULL) return; // Cek apakah file terbuka
		fwrite(mhs , sizeof(Mahasiswa), jumlah , file); // Tambahkan data ke file
		fclose(file); // Tutup file
}

//lengkapi dari file-teks-struct.c
//void tampilkanData(Mahasiswa *mhs , int jumlah) {


int main() {
	// Inisialisasi data mahasiswa awal
	Mahasiswa mhs[3] = {
	{"BudiSantoso", 21, 3.75, AKTIF},
	{"SitiRahmawati", 22, 3.80, CUTI},
	{"AgusWijaya", 20, 3.60, LULUS}
	};
	
	simpanKeFileBiner("mahasiswa.bin", mhs , 3);
	int jumlah = 0;
	Mahasiswa mhsBaca [10];
	bacaDariFileBiner("mahasiswa.bin", mhsBaca , &jumlah);
	tampilkanData(mhsBaca , jumlah); 
	
	return 0;
}
