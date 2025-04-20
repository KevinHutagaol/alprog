//
// Created by kevin on 21/04/2025.
//

#ifndef KELAS_H
#define KELAS_H
#include "Dosen.h"
#include <string>

class Kelas {
private:
    string namaKelas;
    float nilai;
    int sks;
    Dosen dosen;

public:
    Kelas(string namaKelas, float nilai, int sks, Dosen dosen);

    void showDetails();

    [[nodiscard]] float getNilai() const;

    [[nodiscard]] int getSks() const;

    void setNilai(float nilai);

    void setSks(int sks);

    void setNamaKelas(string namaKelas);
};

#endif //KELAS_H
