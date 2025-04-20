//
// Created by kevin on 21/04/2025.
//

#ifndef DOSEN_H
#define DOSEN_H

#include <string>
using namespace std;

class Dosen {
private:
    string name;
    int id{};

public:
    Dosen(string name, int id);

    string getName() const;

    void setName(string name);

    void setId(int id);
};

#endif //DOSEN_H
