//
// Created by kevin on 4/23/2025.
//

#ifndef FILESYSTEMMANAGER_H
#define FILESYSTEMMANAGER_H


#include "Directory.h"

using namespace std;

class FileSystemManager {
public:
    explicit FileSystemManager(Directory directory);

    void touch(string name);

    void echo(string content, string name, int mode);

    void cat(string name);

    void ls();

    void run();



private:
    Directory directory;
};



#endif //FILESYSTEMMANAGER_H
