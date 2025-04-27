//
// Created by kevin on 4/26/2025.
//
#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

#define SERVER "127.0.0.1"
#define PORT 8888

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;
    int recv_size;
    char messageRecv[100];
    string messageSend;

    // Kerjakan program kalian disini
    cout << "Initialising Winsock...\n";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cerr << "WSAStartup failed. Error code: " << WSAGetLastError() << "\n";
        return 1;
    }
    cout << "Winsock initialised.\n";

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        cerr << "Could not create socket. Error code: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }
    cout << "Socket created.\n";

    server.sin_addr.s_addr = inet_addr(SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(client_socket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        cerr << "Connection failed. Error code: " << WSAGetLastError() << "\n";
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }
    cout << "Connected to server.\n\n";

    /** Recive message dari server
    recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
    if(recv_size == SOCKET_ERROR){
        cout << "recv failed with error code" <<  WSAGetLastError();
    }
    else {
        messageRecv[recv_size] = '\0';
    }
    cout << "Pesan dari server: " << messageRecv << "\n";
    */

    /** Send message ke server
    cout << "\nPesan yang ingin dikirim ke server: ";
    cin >> messageSend;

    send(client_socket, messageSend.c_str(), messageSend.length(), 0);
    */

    string pass;
    string key;
    cout << "Send key to server (pass key): ";
    cin >> pass >> key;
    messageSend = pass + " " + key;

    send(client_socket, messageSend.c_str(), messageSend.length(), 0);

    recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
    if (recv_size == SOCKET_ERROR) {
        cout << "recv failed with error code" << WSAGetLastError();
    } else {
        messageRecv[recv_size] = '\0';
    }
    cout << "Checking Password..." << "\n";
    cout << "Message from server: " << messageRecv << "\n";

    closesocket(client_socket);
    WSACleanup();

    return 0;
}
