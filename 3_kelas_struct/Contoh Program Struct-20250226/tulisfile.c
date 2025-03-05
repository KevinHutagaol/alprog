#include <stdio.h>

int main() {
	FILE *file = fopen("output.txt", "w");
	if (file) {
		fprintf(file , "Ini adalah teks yang ditulis ke file.\n");
		fputs("Tambahan teks menggunakan fputs.\n", file);
		fclose(file);
	}
	return 0;
}
