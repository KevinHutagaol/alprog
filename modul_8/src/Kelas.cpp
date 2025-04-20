//
// Created by kevin on 21/04/2025.
//

#include "Kelas.h"
#include <iostream>

Kelas::Kelas(string namaKelas, float nilai, int sks, Dosen dosen): namaKelas(namaKelas), nilai(nilai), sks(sks),
                                                                   dosen(dosen) {
}

void Kelas::showDetails() {
    cout << "Kelas: " << this->namaKelas << ", Nilai: " << this->nilai << ", SKS: " << this->sks << ", Dosen: " << this->dosen.getName() << endl;
}

float Kelas::getNilai() const {
    return this->nilai;
};

int Kelas::getSks() const {
    return this->sks;
}

void Kelas::setNilai(float nilai) {
    this->nilai = nilai;
}

void Kelas::setSks(int sks) {
    this->sks = sks;
}

void Kelas::setNamaKelas(string namaKelas) {
    this->namaKelas = namaKelas;
}