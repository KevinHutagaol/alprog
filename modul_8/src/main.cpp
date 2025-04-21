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

