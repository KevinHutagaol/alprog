## Socket Programming
Pembuat Daste : NS

---

### Definisi

Socket Programming atau Network programming adalah sebuah cabang dari pemrograman dengan tujuan untuk membuat sebauh aplikasi atau program yang dapat berkomunikasi dan bertukar data melalui jaringan. Komunikasi antar aplikasi akan dilakukan melalui socket dan protokol jaringan yang diterapkan. Socket disini berfungsi untuk menjadi perantara antara jaringan dengan aplikasi.

Dalam network programming, terdapat dua jenis program yang digunakan untuk melakukan komunikasi, yaitu :
- Server node 
  Server node berfungsi untuk membuat *listener socket* yang berfungsi untuk menunggu adanya komunikasi yang ingin dilakukan di suatu *port* pada jaringan tersebut. 
- Client node
  Client node berfungsi untuk menginisiasikan komunikasi dengan cara mengakses *port* jaringan di mana *listener socket* server node telah dibuat.

Setelah koneksi antara client node dan server node telah terbentuk, server node maupun client node dapat mengirim data melalui jaringan untuk dibaca oleh pihak lain.

### Concept

![Basic Concept Of Socket Programming](http://cdn.digilabdte.com/u/Ak6Tl3.png)

Diagram di atas adalah gambaran sederhana bagaimana aplikasi saling terhubung. Dapat dilihat pada diagram, socket sebagai gerbang yang digunakan oleh kedua aplikasi untuk mengirimkan data melalui jaringan. Socket sendiri dibagi menjadi dua jenis, yaitu :
- Stream
  Stream socket adalah jenis socket yang menggunakan TCP sebagai protokol jaringannya.
- Datagram 
  Datagram socket adalah jenis socket yang menggunakna UDP sebagai protokol jaringannya

Pada network programming, socket ini diakses menggunakan *socket descriptor* yang dimana hal tersebut diperlakukan layaknya file descriptor. Secara sederhana, file descriptor adalah sebuah identifier yang digunakan untuk mentrack atau menandai sebuah sumber dari input atau output. Oleh karena itu, program akan merujuk pada file descriptor tersebut untuk membaca atau mengirimkan data melalui jaringan.


### Implementasi
![State Diagram of Server and Client Node](https://media.geeksforgeeks.org/wp-content/uploads/20220330131350/StatediagramforserverandclientmodelofSocketdrawio2-448x660.png)

Diagram diatas adalah state diagram dari server node dan client node selama aplikasi saling terkoneksi melalui jaringan dari awal hingga akhir. 
Server Process :
- Pembuatan socket 
  Untuk melakukan komunikasi pada jaringan, socket harus dibuat terlebih dahulu sebagai endpoint yang menghubungkan aplikasi dengan jaringan. Pada tahap ini, kita akan menentukan spesifikasi dari socket, seperti jenis protocol yang digunakan dan tipe dari socketnya.
- Mengikat socket dengan port jaringan
  Setelah membuat socket, kita harus mengasosiasikan socket tersebut ke suatu port yang tersedia pada jaringan agar client dapat mengakses aplikasi ini. 
- Menunggu koneksi dari client
  Selama proses ini, socket akan berada dalam mode pasif, menunggu sebuah client node untuk membangun koneksi ke server node.
- Menerima koneksi dari client
  Setelah ada client node yang mengirimkan permintaan untuk membangun koneksi, server node harus menerima permintaan tersebut agar server dan client dapat terkoneksi melalui jaringan.
- Mengirim dan menerima data
  Setelah koneksi terbangun, data dapat dikirim dan tierima melalui jaringan
- Menutup koneksi
  Jika program telah menyelesaikan pertukaran data, socket dari server node harus ditutup. Socket harus ditutup untuk memberhentikan proses pengiriman atau penerimaan data melalui socket tersebut.

Client process :
- Pembuatan socket 
  Sama seperti server, client node butuh membuat socket sebagai endpoint program pada jaringan.
- Membuat koneksi dengan sever
  Client node akan mengirimkan permintaan untuk membangun koneksi ke server node dan menunggu server untuk menerima permintaan tersebut. Pada tahap ini, client node membutuhkan informasi, seperti ip address, port, dan lainnnya, untuk mengirimkan permintaan koneksi ke server node
- Mengirim dan menerima data
  Setelah koneksi terbangun, data dapat dikirim dan tierima melalui jaringan
- Menutup koneksi
  Jika program telah menyelesaikan pertukaran data, socket dari server node harus ditutup. Socket harus ditutup untuk memberhentikan proses pengiriman atau penerimaan data melalui socket tersebut.


### Contoh

**Dalam modul ini, lbrary yang digunakan akan sedikit berbeda tergantung OS dari laptop kalian.**

#### Server Node
1. Windows OS
  ```cpp
  #include <iostream>
  #include <string>
  #include <winsock2.h>

  using namespace std;

  #define PORT 8888

  int main() {
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

      if (bind(listen_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
          cerr << "Bind failed. Error code: " << WSAGetLastError() << "\n";
          closesocket(listen_socket);
          WSACleanup();
          return 1;
      }
      cout << "Bind done.\n";

      listen(listen_socket, 3);
      cout << "Waiting for incoming connections...\n";

      c = sizeof(struct sockaddr_in);
      client_socket = accept(listen_socket, (struct sockaddr*)&client, &c);
      if (client_socket == INVALID_SOCKET) {
          cerr << "Accept failed. Error code: " << WSAGetLastError() << "\n";
          closesocket(listen_socket);
          WSACleanup();
          return 1;
      }
      cout << "Connection accepted.\n\n";

      cout << "Pesan yang ingin dikirim ke client: ";
      cin >> messageSend;

      send(client_socket, messageSend.c_str(), messageSend.length(), 0);

      recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
      if(recv_size == SOCKET_ERROR){
          cout << "recv failed with error code" <<  WSAGetLastError();
      }
      else {
          messageRecv[recv_size] = '\0';
      }
      cout << "Pesan dari client: " << messageRecv << "\n";

      closesocket(client_socket);
      closesocket(listen_socket);
      WSACleanup();

      return 0;
  }
  ```
2. MacOS / Linux
  ```cpp
  #include <iostream>
  #include <string>
  #include <cstring>     
  #include <unistd.h>    
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>

  using namespace std;

  #define PORT 8888

  int main() {
      int listen_socket, client_socket;
      struct sockaddr_in server{}, client{};
      socklen_t c;
      int recv_size;
      char messageRecv[100];
      string messageSend;

      cout << "Creating socket...\n";
      listen_socket = socket(AF_INET, SOCK_STREAM, 0);
      if (listen_socket < 0) {
          perror("Could not create socket");
          return 1;
      }
      cout << "Socket created.\n";

      server.sin_family = AF_INET;
      server.sin_addr.s_addr = INADDR_ANY;
      server.sin_port = htons(PORT);

      if (bind(listen_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
          perror("Bind failed");
          close(listen_socket);
          return 1;
      }
      cout << "Bind done.\n";

      listen(listen_socket, 3);
      cout << "Waiting for incoming connections...\n";

      c = sizeof(struct sockaddr_in);
      client_socket = accept(listen_socket, (struct sockaddr*)&client, &c);
      if (client_socket < 0) {
          perror("Accept failed");
          close(listen_socket);
          return 1;
      }
      cout << "Connection accepted.\n\n";

      cout << "Pesan yang ingin dikirim ke client: ";
      cin >> messageSend;

      send(client_socket, messageSend.c_str(), messageSend.length(), 0);

      recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
      if(recv_size == SOCKET_ERROR){
          cout << "recv failed with error code" <<  WSAGetLastError();
      }
      else {
          messageRecv[recv_size] = '\0';
      }
      cout << "Pesan dari client: " << messageRecv << "\n";

      close(client_socket);
      close(listen_socket);

      return 0;
  }
  ```

Penjelasan :
Program diatas adalah sebuah server node yang bertujuan untuk mengirimkan sebuah pesan ke suatu client node dan kemudian menerima pesan dari client node. Secara sederhana, program ini melakukan :
1. Menginisialisasi Winsock (khusus windows os)
2. Membuat socket untuk koneksi TCP dan mengikatnya pada port `8888`
3. Menunggu adanya koneksi yang datang pada port `8888`
4. Mengirim pesan ke client
5. Menerima pesan dari client dan menampilkannya pada terminal
6. Menutup socket



#### Client Node
1. Windows OS
  ```cpp
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

      if (connect(client_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
          cerr << "Connection failed. Error code: " << WSAGetLastError() << "\n";
          closesocket(client_socket);
          WSACleanup();
          return 1;
      }
      cout << "Connected to server.\n\n";

      recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
      if(recv_size == SOCKET_ERROR){
          cout << "recv failed with error code" <<  WSAGetLastError();
      }
      else {
          messageRecv[recv_size] = '\0';
      }
      cout << "Pesan dari server: " << messageRecv << "\n";
      
      cout << "\nPesan yang ingin dikirim ke server: ";
      cin >> messageSend;

      send(client_socket, messageSend.c_str(), messageSend.length(), 0);

      closesocket(client_socket);
      WSACleanup();
      return 0;
  }
  ```
2. MacOS / Linux
  ```cpp
  #include <iostream>
  #include <string>
  #include <cstring>    
  #include <unistd.h> 
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>

  using namespace std;

  #define SERVER "127.0.0.1"
  #define PORT 8888

  int main() {
      int client_socket;
      struct sockaddr_in server{};
      int recv_size;
      char messageRecv[100];
      string messageSend;

      cout << "Creating socket...\n";
      client_socket = socket(AF_INET, SOCK_STREAM, 0);
      if (client_socket < 0) {
          perror("Could not create socket");
          return 1;
      }
      cout << "Socket created.\n";

      server.sin_addr.s_addr = inet_addr(SERVER);
      server.sin_family = AF_INET;
      server.sin_port = htons(PORT);

      if (connect(client_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
          perror("Connection failed");
          close(client_socket);
          return 1;
      }
      cout << "Connected to server.\n\n";

      recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
      if(recv_size == SOCKET_ERROR){
          cout << "recv failed with error code" <<  WSAGetLastError();
      }
      else {
          messageRecv[recv_size] = '\0';
      }
      cout << "Pesan dari server: " << messageRecv << "\n";
      cin >> messageSend;

      send(client_socket, messageSend.c_str(), messageSend.length(), 0);

      close(client_socket);
      return 0;
  }
  ```

Penjelasan :
Program diatas adalah sebuah client node yang bertujuan untuk mengirimkan sebuah pesan ke suatu server node dan kemudian menerima pesan dari server node. Secara sederhana, program ini melakukan :
1. Menginisialisasi Winsock (khusus windows os)
2. Membuat socket untuk koneksi TCP
3. Membuat koneksi dengan server dengan IP `127.0.0.1` (localhost) pada port `8888`
4. Menerima pesan dari server node dan menampilkannya pada terminal
5. Mengirim pesan ke server node
6. Menutup socket