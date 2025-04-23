//
// Created by kevin on 4/23/2025.
//

#include "FileSystemManager.h"

#include <string>
#include <iostream>
#include "File.h"
#include <vector>
using namespace std;

FileSystemManager::FileSystemManager(Directory directory): directory(directory) {
}

void FileSystemManager::touch(string name) {
    this->directory.addFile(name);
}

void FileSystemManager::echo(string content, string name, int mode) {
    auto& files = this->directory.getFiles();

    for (auto &file: files) {
        if (file.get_name() == name) {
            if (mode == 1) {
                file.set_content(content);
            } else if (mode == 2) {
                auto temp = file.get_content();
                file.set_content(temp + content);
            }
        }
    }
}


void FileSystemManager::cat(string name) {
    auto files = this->directory.getFiles();

    for (auto file: files) {
        if (file.get_name() == name) {
            cout << file.get_content() << endl;
        }
    }

}

void FileSystemManager::ls() {
    auto files = this->directory.getFiles();
    for (auto file: files) {
        cout << file.get_name() << endl;
    }
}

void FileSystemManager::run() {
    string command;
    while (true) {
        cout << "[" << directory.getName() << "]$ ";
        cin >> command;

        if (command == "touch") {
            string name;
            cin >> name;
            touch(name);
        } else if (command == "echo") {
            string content, name, option;
            cin >> content;
            cin >> option;
            if (option == ">") {
                cin >> name;
                echo(content, name, 1);
            } else if (option == ">>") {
                cin >> name;
                echo(content, name, 2);
            }
        } else if (command == "ls") {
            ls();
        } else if (command == "cat") {
            string name;
            cin >> name;
            cat(name);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command." << '\n';
        }
    }
}


