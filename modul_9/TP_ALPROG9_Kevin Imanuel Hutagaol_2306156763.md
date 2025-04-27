# Tugas Pendahuluan

Pembuat Soal : NS

---

```bash
Nama    : Kevin Imanuel Hutagaol
NPM     : 2306156763
```

### Screenshot hasil run dari kedua program yang ada di dasar teori :

#### 1. Server.cpp | 2. Client.cpp

![image](https://hackmd.io/_uploads/Hyhacbc1ge.png)



---

## Teori

#### 1. Jelaskan apa itu socket programming dan mengapa socket programming dibutuhkan!

Socket programming (network programming) merupakan metode pemrograman yang bertujuan untuk menghubungkan
aplikasi/program agar dapat berkomunikasi melalui network.

Komunikasi dilakukan melalui protokol jaringan yang ada, dimana socket berfungsi untuk menjadi perantara antara jaringan
dan aplikasi.

Referensi:

- [1] “Socket Programming in C++,” GeeksforGeeks.  [Online].
  Available: https://www.geeksforgeeks.org/socket-programming-in-cpp/ [Accessed: Apr. 26, 2025.]
- [1] “Beej’s Guide to Network Programming.”  [Online].
  Available: https://beej.us/guide/bgnet/html/split/ [Accessed: Apr. 26, 2025.]

#### 2. Jelaskan apa itu server node dan client node pada socket programming! Jelaskan juga perbedaan antara server node dan client node!

**Server Node**
Merupakan program yang memberikan (serve) kepada client. Server melakukan beberapa hal seperti:

- Listening : membuka socket listener pada port tertentu untuk mengunggu adanya koneksi dari client
- Melayani client : server menerima permintaan dari client dan mengirimkan response kepada client.

**Client Node**
Merupakan program yang menginisiasi koneksi dan meminta layanan (service) ke server. Client melakukan beberapa hal
seperti:

- Inisiasi : Menginisiasi koneksi dengan mengakses port server
- Mengirim permintaan : Client dapat mengirim permintaan kepada server (misalnya code, web page)
- Menerima response : Client dapat menunggu dan menerima response dari sever menurut permintaannya

Referensi:

- [1] “Socket Programming in C++,” GeeksforGeeks.  [Online].
  Available: https://www.geeksforgeeks.org/socket-programming-in-cpp/ [Accessed: Apr. 26, 2025.]
- [1] “Beej’s Guide to Network Programming.”  [Online].
  Available: https://beej.us/guide/bgnet/html/split/ [Accessed: Apr. 26, 2025.]

#### 3. Jelaskan bagaimana proses server node dan client node saling berkomunikasi melalui jaringan dari awal hingga akhir! (Dapat menggunakan flowchart untuk membantu dalam penjelasan)

Pada server:

- Server membuat socket untuk melakukan komunikasi, menentukan spesifikasi dari socket tersebut, seperti protokol
- Menyambungkan socket dengan port tertentu agar dapat diakses
- Menunggu koneksi dari client
- Menerima koneksi dari client setelah ada client yang mengirim permintaan
- Mengirim dan menerima data melaui jaringan
- Menutup koneksi setelah selesai

Pada client: 

- Pembuatan socket
- Membuat komunikasi dengan server dengan mengirim permintaan ke server node 
- Mengirim dan menerima data setelah koneksi terbangun
- Menutup koneksi setelah selesai 

![State Diagram of Server and Client Node](https://media.geeksforgeeks.org/wp-content/uploads/20220330131350/StatediagramforserverandclientmodelofSocketdrawio2-448x660.png)

Referensi:

- [1] “Socket Programming in C++,” GeeksforGeeks.  [Online].
  Available: https://www.geeksforgeeks.org/socket-programming-in-cpp/ [Accessed: Apr. 26, 2025.]
- [1] “Beej’s Guide to Network Programming.”  [Online].
  Available: https://beej.us/guide/bgnet/html/split/ [Accessed: Apr. 26, 2025.]


#### 4. Jelaskan apa itu stream socket dan datagram socket! Jelaskan juga kapan masing - masing jenis socket digunakan dan perbedaan dari kedua socket tersebut!

Socket dapat dibagi dua menurut protokolnya, yaitu:
- Stream Socket : Menggunakan protokol TCP (Transmission Control Protocol)
- Datagram Socket : Menggunakan protokol UDP (User Datagram Protocol)

**TCP**

Koneksi dua arah yang lebih reliable dan teratur
- TCP akan mengecek pembangunan koneksi dua arah dengan "handshake", dan koneksi harus selalu terjaga
- TPC akan mengecek apakah data yang terkirim sudah diterima atau tidak 
- Data yang dikirim merupakan stream byte berkelanjutan tanpa batasan jelas.

Kegunaan: 

TCP digunakan saat keutuhan data yang dikirim penting seperti pada: 
- File transfer: agar file tidak rusak
- Web browsing: page tidak ada yang hilang 
- Koneksi database

**UDP**

Pengiriman data tanpa koneksi jelas dan tidak teratur 
- UDP tidak memerlukan pembangunan koneksi sebelumnya
- UDP tidak memberi jaminan data seluruhnya dikirim/diterima
- Data yang terkirim mungkin tidak terurut
- Koneksi lebih cepat (tidak ada overhead koneksi)

Kegunaan:

TCP digunakan kecepatan pengiriman data lebih penting
- Streaming video/audio : data yang ditransfer besar dan boleh sedikit rusak
- Game online : Informasi game perlu ditransfer secara cepat untuk mengurangi delay 
- DNS : Domain name akan lebih cepat diproses, dan jika hilang dapat dikirim ulang

Referensi:

- [1] “Socket Programming in C++,” GeeksforGeeks.  [Online].
  Available: https://www.geeksforgeeks.org/socket-programming-in-cpp/ [Accessed: Apr. 26, 2025.]
- [1] “Beej’s Guide to Network Programming.”  [Online].
  Available: https://beej.us/guide/bgnet/html/split/ [Accessed: Apr. 26, 2025.]

## Praktikal

#### 5. Buatlah sebuah program server node dan client node dengan spesifikasi berikut :<ol><li>Server dan client berkomunikasi secara dua araha</li><li>Client node mengirimkan sebuah kata dengan suatu angka yang akan di proses oleh server node</li><li>Server node akan melakukan caesar cipher pada kata yang dikirimkan oleh client dan digeser ke kanan sebanyak angka yang dikirimkan oleh client</li><li><ul><li>Jika password yang ada di server node dan hasil caesar cipher sama, maka server akan mengirimkan "Success" ke client</li><li>Jika password yang ada di server node dan hasil caesar cipher berbeda, maka server akan mengirimkan "Failed" ke client</li></ul></li><li>Input pada client hanya berupa lowercase letter</li><li>Password pada server di hardcode sebagai variable</li></ol>

Hasil run:

- case berhasil
    1. Contoh 1
       ![image](https://hackmd.io/_uploads/H1oCd-qJee.png)
    2. Contoh 2
       ![image](https://hackmd.io/_uploads/SJScYW9ylg.png)
- case gagal
    1. Contoh 1
       ![image](https://hackmd.io/_uploads/Hk5IKbqyxx.png)
    2. Contoh 2
       ![image](https://hackmd.io/_uploads/SJw6tZcJlx.png)

Code :

- Windows OS

- Server.cpp

```c++
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
```

- Client.cpp

```c++
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
```
