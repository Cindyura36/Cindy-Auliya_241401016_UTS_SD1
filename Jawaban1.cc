#include <iostream>
#include <string>
using namespace std;

//Struktur data untuk pasien hewan
struct Pasien {
    string nama, jenis;
    int umur, tingkatDarurat;
};

// Fungsi untuk menukar dua pasien (digunakan saat sorting)
void tukar(Pasien &a, Pasien &b) {
    Pasien temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer agar getline tidak terlewat

    // Dynamic array untuk menyimpan data pasien
    Pasien *daftar = new Pasien[n];

    // Input data pasien
    for (int i = 0; i < n; i++) {
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, daftar[i].nama);
        cout << "Jenis hewan: ";
        getline(cin, daftar[i].jenis);
        cout << "Umur: ";
        cin >> daftar[i].umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> daftar[i].tingkatDarurat;
        cin.ignore(); // membersihkan buffer
    }

    // Sort pasien berdasarkan tingkat darurat (descending)
    // Jika darurat sama, urutan input dipertahankan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (daftar[j].tingkatDarurat > daftar[i].tingkatDarurat) {
                tukar(daftar[i], daftar[j]);
            }
        }
    }

    // Tampilkan urutan pasien berdasarkan prioritas
    cout << "\n=== URUTAN PENANGANAN PASIEN ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << daftar[i].nama << " (" 
             << daftar[i].umur << " tahun) - Darurat " 
             << daftar[i].tingkatDarurat << endl;
    }

    // Hapus memory dynamic array
    delete[] daftar;
    return 0;
}
