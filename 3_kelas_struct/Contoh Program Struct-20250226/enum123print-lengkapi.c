#include <stdio.h>

// Mendefinisikan enumerasi StatusAkademik
typedef enum { 
    AKTIF=1, //coba hapus =1 (jadi default)
    CUTI=2, //coba hapus =2 (jadi default)
    LULUS=3 //coba hapus =3 (jadi default)
} StatusAkademik;

typedef struct {
	char nama [50]; // Nama mahasiswa
	int usia; // Usia mahasiswa
	float ipk; // Indeks Prestasi Kumulatif
	StatusAkademik status; // Status akademik
} Mahasiswa;

int main() {
    // Deklarasi variabel status dengan tipe StatusAkademik
    StatusAkademik statusMahasiswa;

	//Membuat dan Menggunakan Variabel Struktur
	Mahasiswa mhs1 = {"Alice", 20, 3.5, CUTI};

	//Menampilkan Informasi Mahasiswa
	printf("Nama: %s\n", mhs1.nama);
	printf("Usia: %d\n", mhs1.usia);
	printf("IPK: %.2f\n", mhs1.ipk);
	printf("Status: %s\n",
	(mhs1.status == AKTIF) ? "Aktif" :
	(mhs1.status == CUTI) ? "Cuti" : "Lulus");
	printf("Kode status: %d\n", mhs1.status);
	
	return 0;
}
