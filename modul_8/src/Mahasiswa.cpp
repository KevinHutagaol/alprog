//
// Created by kevin on 21/04/2025.
//

#include "Mahasiswa.h"
#include <iostream>


Mahasiswa::Mahasiswa(string nama, int id, Kelas alprog, Kelas sisben, Kelas matdis, Kelas fislis, Jurusan jurusan)
    : nama(nama), id(id), alprog(alprog), sisben(sisben), matdis(matdis), fislis(fislis), jurusan(jurusan) {
}


float Mahasiswa::getIPK() const {
    int total_sks = this->alprog.getSks() + this->sisben.getSks() + this->matdis.getSks() + this->fislis.getSks();

    float mutu_alprog = this->alprog.getNilai() * (float) this->alprog.getSks();
    float mutu_sisben = this->sisben.getNilai() * (float) this->sisben.getSks();
    float mutu_matdis = this->matdis.getNilai() * (float) this->matdis.getSks();
    float mutu_fislis = this->fislis.getNilai() * (float) this->fislis.getSks();

    return (mutu_alprog + mutu_sisben + mutu_matdis + mutu_fislis) / (float) total_sks;
}


void Mahasiswa::showDetails() {
    cout << "Nama: " << this->nama << ", ID: " << this->id << ", Jurusan: " << this->jurusan << endl;
    this->alprog.showDetails();
    this->sisben.showDetails();
    this->matdis.showDetails();
    this->fislis.showDetails();
    cout << "IPK: " << this->getIPK() << endl;
}

