#include <stdio.h>

int main() {
	FILE *file = fopen("data.txt", "r");
	if (file) {
		printf("heer");
		char buffer [100]; //Apa fungsi buffer? bagaimana jika dikurangi jadi 5?
		while (fgets(buffer, 100, file)) { // Membaca baris demi baris
			printf("%s", buffer);//kasih /n untuk lihat pengaruh buffer
		}
	fclose(file);
	}
	return 0;
}
