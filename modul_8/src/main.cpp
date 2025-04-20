//
// Created by kevin on 21/04/2025.
//

#include <iostream>
#include "Dosen.h"
#include "Kelas.h"

using namespace std;

int main() {

    Dosen d1("budi", 01233);
    Dosen d2("asdasd", 0134533);

    Kelas myKelas("alin", 1.1, 4, d1);

    myKelas.setNilai(4.4);

    myKelas.showDetails();

    cout << myKelas.getSks() << endl;
}