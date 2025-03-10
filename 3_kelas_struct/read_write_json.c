#include <stdio.h>
#include <string.h>

typedef enum { AKTIF, CUTI, LULUS } StatusAkademik;

typedef struct {
    char nama[50];
    int usia;
    float ipk;
    StatusAkademik status;
    char matakuliah[5][50];
    int jumlahMatakuliah;
} Mahasiswa;

void parseJSON(const char *jsonString, Mahasiswa *mhs, int *jumlah);

void bacaDataJSON(Mahasiswa *mhs, int *jumlah);

void tampilkanData(Mahasiswa *mhs, int jumlah);

void simpanDataJSON(Mahasiswa *mhs, int jumlah);

int main() {
    // Data yang ingin di tambah
    int jumlah_tambah = 1;
    Mahasiswa mhs[1] = {
        {"Sari Sariwati", 22, 3.66f, LULUS, {"Rangkaian Listrik", "Kalkulus 2"}, 2}
    };

    int jumlah = 0;
    Mahasiswa mhs_arr[50];
    bacaDataJSON(mhs_arr, &jumlah);
    tampilkanData(mhs_arr, jumlah);
    printf("%d\n", jumlah);
    for (int i = 0; i < jumlah_tambah; i++) {
        mhs_arr[i + jumlah] = mhs[i];
    }
    tampilkanData(mhs_arr, jumlah + jumlah_tambah);
    simpanDataJSON(mhs_arr, jumlah + jumlah_tambah);
}

void parseJSON(const char *jsonString, Mahasiswa *mhs, int *jumlah) {
    const char *ptr = jsonString;
    *jumlah = 0;
    while ((ptr = strstr(ptr, "\"nama\":")) != NULL) {
        ptr += 8; // Skip over "nama": "
        sscanf(ptr, " \"%[^\"]\"", mhs[*jumlah].nama);

        ptr = strstr(ptr, "\"usia\":") + 8;
        sscanf(ptr, "%d", &mhs[*jumlah].usia);

        ptr = strstr(ptr, "\"ipk\":") + 7;
        sscanf(ptr, "%f", &mhs[*jumlah].ipk);

        ptr = strstr(ptr, "\"status\":") + 10;
        char statusStr[20];
        sscanf(ptr, " \"%[^\"]\"", statusStr);

        if (strcmp(statusStr, "Aktif") == 0)
            mhs[*jumlah].status = AKTIF;
        else if (strcmp(statusStr, "Cuti") == 0)
            mhs[*jumlah].status = CUTI;
        else if (strcmp(statusStr, "Lulus") == 0)
            mhs[*jumlah].status = LULUS;

        ptr = strstr(ptr, "\"matakuliah\":") + 12;
        char *startArray = strstr(ptr, "[");
        if (startArray == NULL) return;
        ptr = startArray + 1;
        mhs[*jumlah].jumlahMatakuliah = 0;
        while (*ptr != ']') {
            while (*ptr == ' ' || *ptr == '\n' || *ptr == '\t' || *ptr == ',') {
                ptr++;
            }
            if (*ptr == ']') break;

            if (*ptr == '\"') {
                ptr++;

                sscanf(ptr,
                       "%[^\"]",
                       mhs[*jumlah].matakuliah[mhs[*jumlah].jumlahMatakuliah]);
                mhs[*jumlah].jumlahMatakuliah++;

                ptr = strchr(ptr, '\"');
                if (ptr == NULL) break;
                ptr++;
            } else {
                ptr++;
            }
        }
        (*jumlah)++;
        char *endObj = strchr(ptr, '}');
        if (endObj != NULL)
            ptr = endObj + 1;
        else
            break;
    }
}

void bacaDataJSON(Mahasiswa *mhs, int *jumlah) {
    FILE *file = fopen("mahasiswa.json", "r");
    if (file == NULL) {
        printf("File tidak ditemukan !\n");
        *jumlah = 0;
        return;
    }
    char buffer[2048];
    fread(buffer, sizeof(char), 2048, file);
    fclose(file);

    // printf("%s\n", buffer);

    parseJSON(buffer, mhs, jumlah);
}

void tampilkanData(Mahasiswa *mhs, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        // Iterasi tiap record
        printf("Nama: %s, Usia: %d, IPK: %.2f, Status: %s\n",
               mhs[i].nama,
               mhs[i].usia,
               mhs[i].ipk,
               (mhs[i].status == AKTIF) ? "Aktif" : (mhs[i].status == CUTI) ? "Cuti" : "Lulus");
        printf("Matakuliah: ");
        for (int j = 0; j < mhs[i].jumlahMatakuliah; j++) {
            printf("%s, ", mhs[i].matakuliah[j]);
        }
        printf("\n\n");
    }
}

void simpanDataJSON(Mahasiswa *mhs, int jumlah) {
    FILE *file = fopen("mahasiswa.json", "w");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    fprintf(file, "[\n");
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "  {\n");
        fprintf(file, "    \"nama\": \"%s\",\n", mhs[i].nama);
        fprintf(file, "    \"usia\": %d,\n", mhs[i].usia);
        fprintf(file, "    \"ipk\": %.2f,\n", mhs[i].ipk);
        fprintf(file, "    \"status\": \"%s\",\n",
                (mhs[i].status == AKTIF) ? "Aktif" : (mhs[i].status == CUTI) ? "Cuti" : "Lulus");

        // Menulis array mata kuliah
        fprintf(file, "    \"matakuliah\": [\n");
        for (int j = 0; j < mhs[i].jumlahMatakuliah; j++) {
            fprintf(file, "      \"%s\"%s\n", mhs[i].matakuliah[j],
                    (j < mhs[i].jumlahMatakuliah - 1) ? "," : "");
        }
        fprintf(file, "    ]\n");

        fprintf(file, "  }%s\n", (i < jumlah - 1) ? "," : "");
    }
    fprintf(file, "]\n");
    fclose(file);
}
