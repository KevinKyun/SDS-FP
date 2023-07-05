#include <iostream>
#include <string>
using namespace std;

struct Sepatu {
    string nama;
    int harga;
    Sepatu* next;
};

class TokoSepatu {
private:
    Sepatu* head;

public:
    TokoSepatu() {
        head = NULL;
    }

    // Menambahkan sepatu ke toko
    void tambahSepatu(string nama, int harga) {
        Sepatu* newSepatu = new Sepatu;
        newSepatu->nama = nama;
        newSepatu->harga = harga;
        newSepatu->next = head;
        head = newSepatu;
    }

    // Menampilkan daftar sepatu yang dijual
    void tampilkanDaftarSepatu() {
        Sepatu* curr = head;
        if (curr == NULL) {
            cout << "Tidak ada sepatu yang dijual." << endl;
        }
        else {
            cout << "Daftar Sepatu yang Dijual:" << endl;
            while (curr != NULL) {
                cout << "Nama: " << curr->nama << ", Harga: " << curr->harga << endl;
                curr = curr->next;
            }
        }
    }

    // Membeli sepatu
    void beliSepatu(string namaSepatu) {
        Sepatu* curr = head;
        Sepatu* prev = NULL;
        while (curr != NULL && curr->nama != namaSepatu) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            cout << "Sepatu tidak ditemukan." << endl;
        }
        else {
            if (prev == NULL) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Sepatu berhasil dibeli." << endl;
        }
    }

    // Menghapus sepatu dari daftar
    void hapusSepatu(string namaSepatu) {
        Sepatu* curr = head;
        Sepatu* prev = NULL;
        while (curr != NULL && curr->nama != namaSepatu) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            cout << "Sepatu tidak ditemukan." << endl;
        }
        else {
            if (prev == NULL) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Sepatu berhasil dihapus." << endl;
        }
    }
};

int main() {
    TokoSepatu toko;

    int menu;
    string namaSepatu;
    int hargaSepatu;

    do {
        cout << "=== MENU ===" << endl;
        cout << "1. Penjual" << endl;
        cout << "2. Pembeli" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
        case 1:
            int submenuPenjual;
            do {
                cout << "\n=== MENU PENJUAL ===" << endl;
                cout << "1. Memasukkan barang" << endl;
                cout << "2. Melihat daftar barang" << endl;
                cout << "3. Menghapus barang" << endl;
                cout << "0. Kembali ke Menu Utama" << endl;
                cout << "Pilih menu: ";
                cin >> submenuPenjual;

                switch (submenuPenjual) {
                case 1:
                    cout << "Masukkan nama sepatu: ";
                    cin.ignore();
                    getline(cin, namaSepatu);
                    cout << "Masukkan harga sepatu: ";
                    cin >> hargaSepatu;
                    toko.tambahSepatu(namaSepatu, hargaSepatu);
                    cout << "Sepatu berhasil dimasukkan ke dalam toko." << endl;
                    break;
                case 2:
                    toko.tampilkanDaftarSepatu();
                    break;
                case 3:
                    toko.tampilkanDaftarSepatu();
                    cout << "Masukkan nama sepatu yang ingin dihapus: ";
                    cin.ignore();
                    getline(cin, namaSepatu);
                    toko.hapusSepatu(namaSepatu);
                    break;
                case 0:
                    break;
                default:
                    cout << "Menu tidak valid!" << endl;
                    break;
                }
            } while (submenuPenjual != 0);
            break;
        case 2:
            int submenuPembeli;
            do {
                cout << "\n=== MENU PEMBELI ===" << endl;
                cout << "1. Membeli barang" << endl;
                cout << "0. Kembali ke Menu Utama" << endl;
                cout << "Pilih menu: ";
                cin >> submenuPembeli;

                switch (submenuPembeli) {
                case 1:
                    toko.tampilkanDaftarSepatu();
                    cout << "Masukkan nama sepatu yang ingin dibeli: ";
                    cin.ignore();
                    getline(cin, namaSepatu);
                    toko.beliSepatu(namaSepatu);
                    break;
                case 0:
                    break;
                default:
                    cout << "Menu tidak valid!" << endl;
                    break;
                }
            } while (submenuPembeli != 0);
            break;
        case 0:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Menu tidak valid!" << endl;
            break;
        }
    } while (menu != 0);

    return 0;
}
