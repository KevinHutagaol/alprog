# Case Study - Socket Programming
> Pembuat Soal: NS
```
Nama  : [aLOHa]
NPM   : [0791348265]
```
---

#### Pengantar

Pada hari ini, anda ditugaskan untuk membuat sebuah sistem sederhana berbasis client-server. Server akan memproses permintaan dari client berdasarkan request yang dikirimkan oleh client ke server. Pada case study kali ini, kalian berusaha untuk mensimulasikan sebuah file server sederhana dengan fitur tambahan untuk mematikan server.

#### Kriteria program
- Server
  - Server akan membuat sebuah directory dengan nama `system` dan membaca sejumlah file yang ada di dalam directory tersebut
  - Server akan membuka socket untuk menerima request dari client
  - Format request yang valid dari client adalah `LIST [ext]`
  - Jika bentuk request valid, maka server akan mengirimkan teks dari sesuai permintaan yang dikirim.
  - Pada request `LIST`, apabila file dengan extension `[ext]` ditemukan, maka server akan mengirimkan nama - nama file dengan extension tersebut
  - Pada request `LIST`, apabila file dengan extension `[ext]` tidak ada, maka server akan memberitahu bahwa tidak ada file dengan extension tersebut.
  - Pada request `shutdown`, server akan menutup koneksi dan mengirimkan pesan konfirmasi bahwa request berhasil dijalankan
- Client
  - Client akan terhubung dengan server
  - Client meminta input ke user, lalu mengirimkannya request tersebut ke server
  - Client menampilkan hasil dari request yang dilakukan ke server dengan format :
    - Case `LIST`:
      - Case ditemukan:
        ```
        "File with "[ext]" extension are [list nama file dengan extension tersebut]..."
        ```
      - Case tidak ditemukan:
        ```
        File with "[ext]" extension does not exist...
        ```
      **Note** : [ext] akan diganti sesuai extension yang diminta oleh client
    - Case `SHUTDOWN`:
        ```
        Server shutdowned...
        ```
#### Contoh run program

- video
    **KLIK GAMBARNYA**
    [![Thumbnail](https://cdn.digilabdte.com/u/PO0JIx.png)](https://youtu.be/I6HW8_4fT6Q)

- Test case:
  - Case 1:
    Input client: `LIST txt`
    Output client:
    ```
    File with "txt" extension are [A.txt, B.txt]...
    ```
    Terminal:
    ![Case 1](http://cdn.digilabdte.com/u/skhWWF.png)
  - Case 2:
    Input client: `LIST cpp`
    Output client:
    ```
    File with "cpp" extension are [k.cpp, b.cpp]...
    ```
    Terminal:
    ![Case 2](http://cdn.digilabdte.com/u/gnu2F8.png)
  - Case 3:
    Input client: `LIST csv`
    Output client:
    ```
    File with "csv" extension does not exist...
    ```
    Terminal:
    ![Case 3](http://cdn.digilabdte.com/u/VFPK6F.png)
  - Case 3:
    Input client: `DELETE k.cpp`
    Output client:
    ```
    Command is not recognized...
    ```
    Terminal:
    ![Case 4](http://cdn.digilabdte.com/u/Jkigeg.png)
  - Case 5:
    Input client: `SHUTDOWN`
    Output client:
    ```
    Server shutdowned...
    ```
    Terminal:
    ![Case 5](https://cdn.digilabdte.com/u/4DOeAM.png)


#### Note

Pada file server terdapat dua buah class, yaitu `File` dan `DirectoryReader`. Detail dari class tersebut :
- `File` adalah class dari data file yang ada di dalam directory. Class `File` akan menyimpan nama dari file dan extension dari file. 
- `DirectoryReader` adalah class yang bertujuan untuk membaca file dalam bentuk teks yang ada di dalam directory `./system/` menjadi data dalam bentuk vector `File`. 

Penggunaan class `DirectoryReader` sudah diterapkan dalam program. Kalian hanya perlu memikirkan bagaimana data dengan class `File` diolah pada file server. Class `DirectoryReader` tidak ada implementasi tambahan selain yang sudah ada pada file.

Function `string processRequest(vector<File>& file_list, string request)` pada file server tidak harus diterapkan, anda diberi kebebasan bagaimana anda menyelesaikan CS ini. Akan tetapi, saya menyarankan untuk menerapkan function tersebut agar file lebih rapih dan modular. Function `processRequest` tersebut menerima dua argumen, yaitu keseluruhan list dari file dan request yang dikirimkan oleh client. Setelah memproses request client, function akan me-return sebuah string berupa message yang harus dikirimkan ke client.