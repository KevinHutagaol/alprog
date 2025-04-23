# Case Study Modul 8 - Rabu

## Simple File System with CLI

> Gunakan bahasa pemrograman **C++** dan abstraksi lewat **header file**.

---

### 1. **Buatlah class `File` dengan atribut `name` dan `content`.**

- Class ini menyimpan data dari sebuah file dalam bentuk: (**private**)
  - `name` → nama file.
  - `content` → isi file.
- Buat:
  - **Constructor** untuk menginisialisasi nama dan isi.
  - **Getter dan Setter** untuk `name` dan `content`.

---

### 2. **Buatlah class `Directory` yang menyimpan koleksi file.**

- Memiliki: (**private**)
  - Atribut `name` untuk nama direktori (misal `"root"`).
  - Atribut `files` berupa `vector`.
- Buat **constructor** untuk menginisialisasi nama `Directory`.
- Tambahkan method:
  - `addFile(string name)` → tambah file baru dengan nama tertentu.
  - `getFiles()` → mengakses list file.
  - **Getter dan Setter** untuk nama direktori.

---

### 3. **Buatlah class `FileSystemManager` yang menangani perintah user.**

- Memiliki private atribut `Directory`.
- Constructor untuk menginisialisasi `Directory`.
- Buat method-method berikut: (bertipe **void**)
  - `touch(name)` → membuat file kosong dengan nama `name`.
  - `echo(content, name, mode)` → overwrite menulis (`mode = 1`) atau append (`mode = 2`) isi file.
  - `cat(name)` → menampilkan isi file yang memiliki nama `name`.
  - `ls()` → menampilkan file-file yang ada dalam direktori.
  - `run()` → memproses perintah CLI seperti `touch`, `echo`, `cat`, `exit` dll. (**Copas kode di bawah ini**)
- User dapat memasukkan perintah `exit` untuk keluar dari program.
- Pseudocode untuk method-method di atas:

```txt
touch(name)
Function touch(name):
    Tambahkan file baru ke direktori dengan nama sesuai argumen

echo(content, name, mode)
Function echo(content, name, mode):
    Dapatkan semua file di direktori
    Untuk setiap file dalam direktori:
        Jika nama file sama dengan 'name':
            Jika mode == 1:
                Ganti isi file dengan 'content' (overwrite)
            Jika mode == 2:
                Tambahkan 'content' ke akhir isi file yang sudah ada (append)

ls()
Function ls():
    Dapatkan semua file di direktori
    Untuk setiap file dalam direktori:
        Cetak nama file ke terminal

cat(name)
Function cat(name):
    Dapatkan semua file di direktori
    Untuk setiap file dalam direktori:
        Jika nama file adalah 'name':
            Cetak isi file ke terminal
```

- Berikut adalah kode untuk method `run()`:

```cpp
void FileSystemManager::run()
{
    string command;
    while (true)
    {
        cout << "[" << directory.getName() << "]$ ";
        cin >> command;

        if (command == "touch")
        {
            string name;
            cin >> name;
            touch(name);
        }
        else if (command == "echo")
        {
            string content, name, option;
            cin >> content;
            cin >> option;
            if (option == ">")
            {
                cin >> name;
                echo(content, name, 1);
            }
            else if (option == ">>")
            {
                cin >> name;
                echo(content, name, 2);
            }
        }
        else if (command == "ls")
        {
            ls();
        }
        else if (command == "cat")
        {
            string name;
            cin >> name;
            cat(name);
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Unknown command." << '\n';
        }
    }
}
```

---

### 4. **Buat file `main.cpp` untuk menjalankan CLI file system.**

- Di dalam `main.cpp`:
  - Buat objek `Directory` (misal `"root"` atau bebas namanya).
  - Buat objek `FileSystemManager` dengan direktori tersebut.
  - Panggil `run()` pada objek `FileSystemManager` untuk masuk ke perintah CLI.

---

### 5. **Output yang Diharapkan**

- Sistem menerima dan memproses input user.
- Hasilnya sesuai dengan operasi yang dilakukan:
  - `touch` menambahkan file baru.
  - `echo >` kosongin isi file dulu, baru tulis isi baru.
  - `echo >>` menambahkan isi.
  - `cat` menampilkan isi.
  - `ls` menampilkan nama file.
- Contoh output:

```bash
[root]$ touch hello.txt
[root]$ echo hello123 > hello.txt
[root]$ echo 123hello >> hello.txt
[root]$ cat hello.txt
hello123123hello
[root]$ ls
hello.txt
[root]$ exit
```
