#include <iostream>

using namespace std;

struct Menejemen {
    string tanggal;
    string jenis;
    double jumlah;
};
Menejemen keuangan[100];
int jumlahmasuk = 0;

void masuk(){
    cout << "|=======================|" << endl;
    cout << "|   Masukan Transaksi   |" << endl;
    cout << "|=======================|" << endl;
    cout << "Masukkan tanggal (DD/MM/YYYY): ";
    cin >> keuangan[jumlahmasuk].tanggal;
    cout << "Masukkan jenis (Pemasukan/Pengeluaran): ";
    cin >> keuangan[jumlahmasuk].jenis;
    cout << "Masukkan jumlah: ";
    cin >> keuangan[jumlahmasuk].jumlah;
    jumlahmasuk++;
}

void cari(){
    string cari;
    cout << "|=======================|" << endl;
    cout << "|        Search         |" << endl;
    cout << "|=======================|" << endl;
    cout << "Masukkan tanggal (DD/MM/YYYY): ";
    cin >> cari;
    system("cls");
    for (int i = 0; i < jumlahmasuk; i++) {
        if (keuangan[i].tanggal == cari) {
            cout << "|=======================|" << endl;
            cout << "|     Data Keuangan     | " << endl;
            cout << "|=======================|" << endl;
            cout << "Tanggal: " << keuangan[i].tanggal << endl;
            cout << "Jenis: " << keuangan[i].jenis << endl;
            cout << "Jumlah: " << keuangan[i].jumlah << endl;
        }
    }
}

void menu (){
    cout << "|=======================|" << endl;
    cout << "|  Menjemen Keuangan    |" << endl;
    cout << "|=======================|" << endl;
    cout << "| 1. Masukan Transaksi  |" << endl;
    cout << "| 2. Lihat Transaksi    |" << endl;
    cout << "| 3. Lihat Saldo        |" << endl;
    cout << "| 4. Search             |" << endl;
    cout << "| 5. Keluar             |" << endl;
    cout << "|=======================|" << endl;
}
void lihat(){
    cout << "|=======================|" << endl;
    cout << "|     Data Keuangan     | " << endl;
    cout << "|=======================|" << endl;
    for (int i = 0; i < jumlahmasuk; i++) {
        cout << "Tanggal: " << keuangan[i].tanggal << endl;
        cout << "Jenis: " << keuangan[i].jenis << endl;
        cout << "Jumlah: " << keuangan[i].jumlah << endl;
    }
}
void saldo(){
    double saldo = 0;
    for (int i = 0; i < jumlahmasuk; i++) {
        if (keuangan[i].jenis == "Pemasukan") {
            saldo += keuangan[i].jumlah;
        } else {
            saldo -= keuangan[i].jumlah;
        }
    }
    cout << "|=======================|" << endl;
    cout << "|      Lihat Saldo      |" << endl;
    cout << "|=======================|" << endl;
    cout << "Saldo Anda: " << saldo << endl;
    
}
int main() {
    char kembali;
    do {
        menu();
        int pilihan;
        cout << "|Masukkan pilihan: ";
        cin >> pilihan;
        system("cls");

        switch (pilihan) {
            case 1:
                masuk();
                break;
            case 2:
                lihat();
                break;
            case 3:
                saldo();
                break;
            case 4:
                cari();
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << "Apakah Anda ingin kembali ke menu? (y/n): ";
        cin >> kembali;
        system("cls"); 
    } while (kembali == 'y' || kembali == 'Y');

    return 0;
}
