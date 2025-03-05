#include <stdio.h>
#include <stdlib.h>

// Deklarasi struktur untuk matriks
struct Matrix {
	int rows; // Jumlah baris
	int cols; // Jumlah kolom
	int **data; // Elemen -elemen matriks
};

int main() {
	// Menggunakan struktur untuk menyimpan metadata matriks
	struct Matrix mat;
	mat.rows = 3;
	mat.cols = 3;
	// Menampilkan metadata matriks
	printf("Matrix dimensions: %d x %d\n", mat.rows , mat.cols);
	


	// Alokasi memori untuk baris = lihat referensi slide pekan 3 halaman 55
	mat.data = (int**) malloc(mat.cols * sizeof(int*)); //Lengkapi
	
	// Alokasi memori untuk setiap kolom
	for (int i = 0; i < mat.rows; i++) {
		mat.data[i] = (int*) malloc(mat.rows * sizeof(int));//Lengkapi
	}
	
	// Inisialisasi matriks
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++) {
			mat.data[i][j] = i+j;
		}
	}
	
	// Menampilkan matriks
	printf("Matriks:\n");
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++) {
			printf("%d ", mat.data[i][j]);
        }
		printf("\n");
	}

	// Dealokasi memori
	for (int i = 0; i < mat.rows; i++) {
		free(mat.data[i]);
	}
    free(mat.data);
	return 0;
}
