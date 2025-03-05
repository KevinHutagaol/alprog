#include <stdio.h>

int main() {
	FILE *file = fopen("data.txt", "r");
	if (file) {
		fseek(file , 5, SEEK_SET); // Pindah ke posisi ke -10 dari awal file
		char buffer [50];
		fgets(buffer , 50, file);
		printf("Data dari posisi ke -5: %s", buffer);
		fclose(file);
}

	return 0;
}
