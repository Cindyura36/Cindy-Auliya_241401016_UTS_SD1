#include <iostream>
using namespace std;

// Struktur data film
struct Film {
    string judul;
    int tahun, rating;
    Film* next;
};

Film* head = nullptr;

//Menambahkan Film di depan
void InsertFirst(string j, int t, int r) {
    Film* baru = new Film{j, t, r, head}; //membuat node baru
    head = baru; //node tersebut ditempatkan di depan
}

//Menambahkan Film di belakang
void InsertLast(string j, int t, int r) {
    Film* baru = new Film{j, t, r, nullptr}; //membuat node baru
    if (!head) head = baru; //jika linked list masih kosong, maka node akan ditempatkan di depan 
    else { //jika sudah berisi
        Film* temp = head; //buat node sementara untuk menelusuri linked list
        while (temp->next) temp = temp->next; //menelusuri hingga ke node terakhir
        temp->next = baru; //menambahkan node baru di belakang
    }
}

//Menambahkan Film di tengah (Setelah Film tertentu)
void InsertAfter(string target, string j, int t, int r) {
    Film* temp = head;
    while (temp && temp->judul != target) //mencari node dengan judul tertentu
        temp = temp->next;

    if (!temp) { //jika tidak ditemukan
        cout << "Film \"" << target << "\" tidak ditemukan!\n";
        return;
    }

    //jika ditemukan, tambahkan node baru setelah node tersebut
    Film* baru = new Film{j, t, r, temp->next};
    temp->next = baru;
}

//Menghapus Film yang sudah ditonton dari daftar film
void hapusFilm(string target) {
    if (head->judul == target) { //jika film yang dihapus adalah film pertama
        Film* hapus = head;
        head = head->next;
        delete hapus;
        cout << target << " dihapus dari daftar.\n";
        return;
    }
    Film* temp = head;
    //mencari film yang akan dihapus:
    while (temp->next && temp->next->judul != target) {
        temp = temp->next;
    }
    if (temp->next) { //jika film ditemukan
        Film* hapus = temp->next;
        temp->next = temp->next->next; //menghubungkan node
        delete hapus;
        cout << target << " dihapus dari daftar.\n";
    } else { //jika film tidak ditemukan
        cout << "Film tidak ditemukan.\n";
    }
}

//Menampilkan Daftar Film
void tampilkan() {
    Film* temp = head;
    int count = 0; //total film awalnya 0
    cout << "\nDaftar Film\n";
    while (temp) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        count++; //menghitung total film
        temp = temp->next;
    }
    cout << "\nTotal sisa film : " << count << endl;
}

int main() {
    int n, pilihan;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Film* baru = new Film; //membuat node baru
        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        cin >> ws; getline(cin, baru->judul);
        cout << "Tahun: ";
        cin >> baru->tahun;
        cout << "Rating: ";
        cin >> baru->rating;
        InsertLast(baru->judul, baru->tahun, baru->rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    if (hapus == 'y' || hapus == 'Y') {
        string target;
        cout << "Masukkan judul film yang sudah ditonton: ";
        cin >> ws; getline(cin, target);
        hapusFilm(target);
    }

    tampilkan(); 

     do {
        cout << "\nMenu Daftar Film :\n";
        cout << "1. Menambah film di depan\n";
        cout << "2. Menambah film di tengah (setelah film tertentu)\n";
        cout << "3. Menambah film di belakang\n";
        cout << "4. Hapus film\n";
        cout << "5. Tampilkan daftar film\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        string judul, target;
        int tahun, rating;

        switch (pilihan) {
        case 1: // Tambah film di depan
            cout << "Judul: ";
            cin >> ws; getline(cin, judul);
            cout << "Tahun: ";
            cin >> tahun;
            cout << "Rating (1-10): ";
            cin >> rating;
            InsertFirst(judul, tahun, rating);
            break;

        case 2: // Tambah film di tengah (setelah film tertentu)
            cout << "Judul film baru: ";
            cin >> ws; getline(cin, judul);
            cout << "Tahun: ";
            cin >> tahun;
            cout << "Rating (1-10): ";
            cin >> rating;
            cout << "Masukkan ke daftar setelah film: ";
            cin >> ws; getline(cin, target);
            InsertAfter(target, judul, tahun, rating);
            break;

        case 3: // Tambah film di belakang
            cout << "Judul: ";
            cin >> ws; getline(cin, judul);
            cout << "Tahun: ";
            cin >> tahun;
            cout << "Rating (1-10): ";
            cin >> rating;
            InsertLast(judul, tahun, rating);
            break;

        case 4: // Hapus film
            cout << "Masukkan judul film yang sudah ditonton: ";
            cin >> ws; getline(cin, target);
            hapusFilm(target);
            break;

        case 5: // Tampilkan daftar film
            tampilkan();
            break;

        case 0: // Keluar dari program
            cout << "Terima kasih!.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

}