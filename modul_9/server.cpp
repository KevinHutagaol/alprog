//
// Created by kevin on 4/26/2025.
//
#include <iostream>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888
#define PASSWORD "tmxa" //Boleh diganti

string decrypt(string text, int n) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        result += char((int(text[i] - 97 + n) % 26) + 97);
    }

    return result;
}

void parseMessage(const string &messageRecv, string &pass, int &key) {
    stringstream ss(messageRecv);
    string temp;

    getline(ss, temp, ' ');
    pass = "";
    for (int x = 0; x < temp.length(); x++) {
        pass += char(tolower(temp[x]));
    }

    getline(ss, temp, ' ');
    key = atoi(temp.c_str());
}

int main() {
    WSADATA wsa;
    SOCKET listen_socket, client_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char messageRecv[100];
    string messageSend;

    string pass;
    int key;

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
    cout << "Waiting for incoming connections...\n";

    c = sizeof(struct sockaddr_in);
    client_socket = accept(listen_socket, (struct sockaddr *) &client, &c);
    if (client_socket == INVALID_SOCKET) {
        cerr << "Accept failed. Error code: " << WSAGetLastError() << "\n";
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "Connection accepted.\n\n";


    /** Buat send ke client
    cout << "Pesan yang ingin dikirim ke client: ";
    cin >> messageSend;

    send(client_socket, messageSend.c_str(), messageSend.length(), 0);
    */

    /** Buat recive dari client
    recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
    if(recv_size == SOCKET_ERROR){
        cout << "recv failed with error code" <<  WSAGetLastError();
    }
    else {
        messageRecv[recv_size] = '\0';
    }
    cout << "Pesan dari client: " << messageRecv << "\n";
    */

    recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
    if (recv_size == SOCKET_ERROR) {
        cout << "recv failed with error code" << WSAGetLastError();
    } else {
        messageRecv[recv_size] = '\0';
    }
    cout << "Message from client: " << messageRecv << "\n";

    parseMessage(messageRecv, pass, key);

    string decrypted_pass = decrypt(pass, key);

    cout << "Cipher result: " << decrypted_pass << " " << "(with key=" << key << ")" << endl;

    cout << "Cipher result (" << decrypted_pass << "), "
            << (decrypted_pass == PASSWORD ? "Matches " : "Does not match ")
            << "password (" << PASSWORD << ")" << endl;

    messageSend = decrypted_pass == PASSWORD ? "SUCCESS" : "FAILURE";

    send(client_socket, messageSend.c_str(), messageSend.length(), 0);

    closesocket(client_socket);
    closesocket(listen_socket);
    WSACleanup();

    return 0;
}
