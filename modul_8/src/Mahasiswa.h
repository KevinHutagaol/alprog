//
// Created by kevin on 21/04/2025.
//

#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
#include "Kelas.h"
#include "Jurusan.h"

using namespace std;

class Mahasiswa {
private:
    string nama;
    int id;
    Kelas alprog;
    Kelas sisben;
    Kelas matdis;
    Kelas fislis;

    Jurusan jurusan;

public:
    Mahasiswa(string nama, int id, Kelas alprog, Kelas sisben, Kelas matdis, Kelas fislis, Jurusan jurusan);

    [[nodiscard]] float getIPK() const;

    void showDetails();

};

#endif //MAHASISWA_H


