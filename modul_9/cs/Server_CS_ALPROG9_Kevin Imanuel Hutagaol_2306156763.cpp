#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888


class File {
public:
    string name;
    string type;

    File(string file_name) {
        stringstream ss(file_name);
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

    void _create_file(string file_name) {
        ofstream file;

        file.open("./" + DIRECTORY + "/" + file_name);
        file.close();
    }

    void _create_directory() {
        mkdir(DIRECTORY.c_str());
        string tmpFile = "output.txt";
        string path = "./" + DIRECTORY;

        _create_file("A.txt");
        _create_file("B.txt");
        _create_file("k.cpp");
        _create_file("b.cpp");

        string command = "dir /b /a:-d \"" + path + "\" > \"" + tmpFile + "\"";
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

string processRequest(vector<File> &file_list, string command, string type_ext) {
    if (command == "list") {
        string output = "List of files with extention " + type_ext + ": ";
        int count = 0;
        for (const auto &file: file_list) {
            if (file.type == type_ext) {
                output += " " + file.name + "." + file.type;
                count++;
            }
        }
        if (count > 0) {
            return output;
        }
        return "No files with extention " + type_ext + " Found";
    }

    return "COMMAND NOT SUPPORTED";
}

int main() {
    vector<File> file_list = DirectoryReader::GetData();


    WSADATA wsa;
    SOCKET listen_socket, client_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char messageRecv[100];
    string messageSend;

    cout << "Initialising Winsock...\n";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cerr << "WSAStartup failed. Error code: " << WSAGetLastError() << "\n";
        return 1;
    }
    cout << "Winsock initialised.\n";

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == INVALID_SOCKET) {
        cerr << "Could not create socket. Error code: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }
    cout << "Socket created.\n";

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
        cerr << "Bind failed. Error code: " << WSAGetLastError() << "\n";
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "Bind done.\n";

    listen(listen_socket, 3);

    int server_running = 1;

    cout << "" << endl;
    while (server_running) {
        cout << "Waiting for incoming connections...\n";

        c = sizeof(struct sockaddr_in);
        client_socket = accept(listen_socket, (struct sockaddr *) &client, &c);
        if (client_socket == INVALID_SOCKET) {
            cerr << "Accept failed. Error code: " << WSAGetLastError() << "\n";
            closesocket(listen_socket);
            WSACleanup();
            return 1;
        }
        cout << "Connection accepted." << endl;


        recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
        if (recv_size == SOCKET_ERROR) {
            cout << "recv failed with error code" << WSAGetLastError();
        } else {
            messageRecv[recv_size] = '\0';
        }

        string command = messageRecv;

        for (char &ch: command) {
            ch = char(tolower(ch));
        }

        if (command == "shutdown") {
            messageSend = "Shutting server Down";
            send(client_socket, messageSend.c_str(), messageSend.length(), 0);
            closesocket(client_socket);
            break;
        }

        recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
        if (recv_size == SOCKET_ERROR) {
            cout << "recv failed with error code" << WSAGetLastError();
        } else {
            messageRecv[recv_size] = '\0';
        }

        string argument = messageRecv;

        cout << "Command from client: " << command << " " << argument << "\n";

        messageSend = processRequest(file_list, command, argument);

        send(client_socket, messageSend.c_str(), messageSend.length(), 0);

        closesocket(client_socket);

        cout << "Request Finished\n" << endl;
    }


    closesocket(listen_socket);
    WSACleanup();


    return 0;
}
