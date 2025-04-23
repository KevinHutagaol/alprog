//
// Created by kevin on 4/23/2025.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "File.h"
#include <string>
#include <vector>

using namespace std;

class Directory {
public:
    Directory(string name, vector<File> files);

    void addFile(string name);

    vector<File> &getFiles();

    void setName(string name);

    [[nodiscard]] string getName() const;

private:
    string name;
    vector<File> files;
};


#endif //DIRECTORY_H
