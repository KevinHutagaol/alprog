//
// Created by kevin on 4/23/2025.
//

#include "Directory.h"
#include "File.h"

Directory::Directory(string name, vector<File> files): name(name), files(files) {
}

void Directory::addFile(string name) {
    this->files.push_back(File(name, ""));
}

vector<File>& Directory::getFiles() {
    return this->files;
}

void Directory::setName(string name) {
    this->name = name;
}

string Directory::getName() const {
    return this->name;
}
