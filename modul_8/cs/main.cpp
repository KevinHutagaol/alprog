//
// Created by kevin on 4/23/2025.
//

#include "Directory.h"
#include "File.h"
#include "FileSystemManager.h"
#include <vector>

using namespace std;

int main() {
    Directory directory("root", vector<File>{});
    FileSystemManager file_system(directory);
    file_system.run();
}