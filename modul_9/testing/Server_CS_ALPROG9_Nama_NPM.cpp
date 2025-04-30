#include <iostream>
#include <fstream>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888


class File {
    public:
        string name;
        string type;

        File(string file_name){
            stringstream ss (file_name);
            string temp;

            getline(ss, temp, '.');
            name = temp;
            
            getline(ss, temp);
            type = temp;
        }
};


class DirectoryReader {
    private:
        string DIRECTORY = "system";

        void _create_file(string file_name){
            ofstream file;
        
            file.open("./" + DIRECTORY + file_name);
            file.close();
        }

        void _create_directory(){
            mkdir(DIRECTORY.c_str());
            string tmpFile = "output.txt";
            string path = "./" + DIRECTORY;

            _create_file("A.txt");
            _create_file("B.txt");
            _create_file("k.cpp");
            _create_file("b.cpp");

            string command = "ls " + path + " > " + tmpFile;
    
            system(command.c_str());
        }

    public:
        static vector<File> GetData() {
            DirectoryReader reader;
            reader._create_directory();

            vector<File> data = {};

            string tmpFile = "output.txt";
            ifstream file_data;

            file_data.open(tmpFile);

            string line, result;
            while (!file_data.eof()) {
                getline(file_data, line);
                
                File newFile(line);
                data.push_back(newFile);
            }
            file_data.close();

            remove(tmpFile.c_str()); 

            return data;
        }
};

/*
string processRequest(vector<File>& file_list, string request){
    
}
*/

int main() {
    vector<File> file_list = DirectoryReader::GetData();
    
    // Kerjakan Program anda disini


    return 0;
}
