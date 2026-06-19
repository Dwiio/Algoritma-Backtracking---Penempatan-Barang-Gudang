#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Barang {
    string kode;
    string nama;
    int berat;
    string kategori;
};

struct Rak {
    string kode;
    string posisi;
    int kapasitas;
    int totalBerat = 0;
    vector<Barang> isiBarang;
};

vector<Barang> daftarBarang;
vector<Rak> daftarRak;

int jumlahNode = 0;
int jumlahBacktrack = 0;

bool kategoriBertabrakan(string k1, string k2) {
    return (k1 == "Makanan" && k2 == "Kimia") ||
           (k1 == "Kimia" && k2 == "Makanan");
}

bool isValid(Barang barang, Rak rak) {

    if (rak.totalBerat + barang.berat > rak.kapasitas)
        return false;

    if (barang.berat >= 25 && rak.posisi != "Bawah")
        return false;

    for (Barang b : rak.isiBarang) {
        if (kategoriBertabrakan(barang.kategori, b.kategori))
            return false;
    }

    return true;
}

void masukkanBarang(Barang barang, int indexRak) {
    daftarRak[indexRak].isiBarang.push_back(barang);
    daftarRak[indexRak].totalBerat += barang.berat;
}

void keluarkanBarang(Barang barang, int indexRak) {
    daftarRak[indexRak].isiBarang.pop_back();
    daftarRak[indexRak].totalBerat -= barang.berat;
}

bool backtracking(int indexBarang) {

    jumlahNode++;

    if (indexBarang == daftarBarang.size())
        return true;

    Barang barang = daftarBarang[indexBarang];

    for (int i = 0; i < daftarRak.size(); i++) {

        cout << "Mencoba menempatkan "
             << barang.nama
             << " ke Rak "
             << daftarRak[i].kode;

        if (isValid(barang, daftarRak[i])) {

            cout << " -> BERHASIL\n";

            masukkanBarang(barang, i);

            if (backtracking(indexBarang + 1))
                return true;

            cout << "Backtracking dari "
                 << barang.nama
                 << " pada Rak "
                 << daftarRak[i].kode
                 << endl;

            jumlahBacktrack++;

            keluarkanBarang(barang, i);
        }
        else {
            cout << " -> GAGAL\n";
        }
    }

    return false;
}

void tampilBarang() {

    if (daftarBarang.empty()) {
        cout << "\nBelum ada barang.\n";
        return;
    }

    cout << "\nDAFTAR BARANG\n";

    for (int i = 0; i < daftarBarang.size(); i++) {
        cout << i + 1 << ". "
             << daftarBarang[i].kode << " | "
             << daftarBarang[i].nama << " | "
             << daftarBarang[i].berat << " kg | "
             << daftarBarang[i].kategori
             << endl;
    }
}

void tampilRak() {

    if (daftarRak.empty()) {
        cout << "\nBelum ada rak.\n";
        return;
    }

    cout << "\nDAFTAR RAK\n";

    for (int i = 0; i < daftarRak.size(); i++) {
        cout << i + 1 << ". "
             << daftarRak[i].kode << " | "
             << daftarRak[i].posisi << " | "
             << daftarRak[i].kapasitas << " kg"
             << endl;
    }
}

void tambahBarang() {

    int n;

    cout << "\nJumlah barang : ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        Barang b;

        cout << "\nBarang ke-" << i + 1 << endl;

        cout << "Kode Barang : ";
        cin >> b.kode;

        cin.ignore();

        cout << "Nama Barang : ";
        getline(cin, b.nama);

        cout << "Berat Barang : ";
        cin >> b.berat;

        cout << "Kategori : ";
        cin >> b.kategori;

        daftarBarang.push_back(b);
    }
}

void tambahRak() {

    int n;

    cout << "\nJumlah rak : ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        Rak r;

        cout << "\nRak ke-" << i + 1 << endl;

        cout << "Kode Rak : ";
        cin >> r.kode;

        cout << "Posisi (Bawah/Tengah/Atas) : ";
        cin >> r.posisi;

        cout << "Kapasitas : ";
        cin >> r.kapasitas;

        daftarRak.push_back(r);
    }
}

void tampilHasil() {

    cout << "\n========================================";
    cout << "\nHASIL PENEMPATAN";
    cout << "\n========================================\n";

    for (Rak rak : daftarRak) {

        cout << "\nRak : " << rak.kode << endl;
        cout << "Posisi : " << rak.posisi << endl;
        cout << "Kapasitas : "
             << rak.kapasitas
             << " kg\n";

        cout << "Terpakai : "
             << rak.totalBerat
             << " kg\n";

        cout << "Sisa : "
             << rak.kapasitas - rak.totalBerat
             << " kg\n";

        if (rak.isiBarang.empty()) {
            cout << "Tidak ada barang\n";
        }
        else {
            for (Barang b : rak.isiBarang) {

                cout << "- "
                     << b.kode << " | "
                     << b.nama << " | "
                     << b.berat << " kg | "
                     << b.kategori
                     << endl;
            }
        }

        cout << "---------------------------------\n";
    }

    cout << "\nSTATISTIK BACKTRACKING\n";
    cout << "Node Dikunjungi : "
         << jumlahNode << endl;

    cout << "Jumlah Backtrack : "
         << jumlahBacktrack << endl;
}

void resetData() {

    daftarBarang.clear();
    daftarRak.clear();

    jumlahNode = 0;
    jumlahBacktrack = 0;

    cout << "\nData berhasil dihapus.\n";
}

int main() {

    int pilihan;

    do {

        cout << "\n=========================================\n";
        cout << " SISTEM PENEMPATAN BARANG DALAM GUDANG\n";
        cout << " ALGORITMA BACKTRACKING\n";
        cout << "=========================================\n";

        cout << "1. Tambah Barang\n";
        cout << "2. Tambah Rak\n";
        cout << "3. Lihat Daftar Barang\n";
        cout << "4. Lihat Daftar Rak\n";
        cout << "5. Jalankan Optimasi\n";
        cout << "6. Reset Data\n";
        cout << "7. Keluar\n";

        cout << "\nPilihan : ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            tambahBarang();
            break;

        case 2:
            tambahRak();
            break;

        case 3:
            tampilBarang();
            break;

        case 4:
            tampilRak();
            break;

        case 5:

            jumlahNode = 0;
            jumlahBacktrack = 0;

            if (backtracking(0)) {
                tampilHasil();
            }
            else {
                cout << "\nTidak ditemukan solusi.\n";
            }

            break;

        case 6:
            resetData();
            break;

        case 7:
            cout << "\nTerima kasih.\n";
            break;

        default:
            cout << "\nPilihan tidak valid.\n";
        }

    } while (pilihan != 7);

    return 0;
}