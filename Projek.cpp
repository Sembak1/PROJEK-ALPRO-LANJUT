#include <iostream>

using namespace std;

struct Menejemen {
    string tanggal;
    string jenis;
    long long jumlah;
};
Menejemen keuangan[100];
int jumlahmasuk = 0;

void masuk(){
    cout << "|========================================|" << endl;
    cout << "|             Masukan Transaksi          |" << endl;
    cout << "|========================================|" << endl;
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
    cout << "|===============================|" << endl;
    cout << "|            Search             |" << endl;
    cout << "|===============================|" << endl;
    cout << "Masukkan tanggal (DD/MM/YYYY): ";
    cin >> cari;
    system("cls");
    bool ditemukan = false;
    for (int i = 0; i < jumlahmasuk; i++) {
        if (keuangan[i].tanggal == cari) {
            cout << "|=======================|" << endl;
            cout << "|     Data Keuangan     |" << endl;
            cout << "|=======================|" << endl;
            cout << "Tanggal: " << keuangan[i].tanggal << endl;
            cout << "Jenis: " << keuangan[i].jenis << endl;
            cout << "Jumlah: " << keuangan[i].jumlah << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Data dengan tanggal " << cari << " tidak ditemukan." << endl;
    }
}


void menu() {
    cout << "|===========================|" << endl;
    cout << "|    Manajemen Keuangan     |" << endl;
    cout << "|===========================|" << endl;
    cout << "| 1. Masukkan Transaksi     |" << endl;
    cout << "| 2. Lihat Transaksi        |" << endl;
    cout << "| 3. Lihat Saldo            |" << endl;
    cout << "| 4. Search (Linear)        |" << endl;
    cout << "| 5. Search (Binary)        |" << endl;
    cout << "| 6. Urutkan Data           |" << endl;
    cout << "| 7. Keluar                 |" << endl;
    cout << "|===========================|" << endl;
}

void lihat(){
    cout << "|===========================|" << endl;
    cout << "|        Data Keuangan      | " << endl;
    cout << "|===========================|" << endl;
    for (int i = 0; i < jumlahmasuk; i++) {
        cout << "Tanggal: " << keuangan[i].tanggal << endl;
        cout << "Jenis: " << keuangan[i].jenis << endl;
        cout << "Jumlah: " << keuangan[i].jumlah << endl;
    cout << "============================" << endl;
    }
}
void saldo() {
    if (jumlahmasuk == 0) {
        cout << "Belum ada transaksi yang tercatat." << endl;
        return;
    }

    long long saldo = 0;
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
    cout << "Saldo Anda: Rp " << saldo << endl;
}
void sortkeuangan() {
    if (jumlahmasuk == 0) {
        cout << "Tidak ada data untuk diurutkan." << endl;
        return;
    }

    for (int i = 0; i < jumlahmasuk - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < jumlahmasuk; j++) {
            if (keuangan[j].tanggal < keuangan[minIndex].tanggal) {
                minIndex = j;
            }
        }
        swap(keuangan[i], keuangan[minIndex]);
    }
}


void urutkandata() {
    sortkeuangan();
    cout << "|================================|" << endl;
    cout << "|     Data Setelah Diurutkan     | " << endl;
    cout << "|================================|" << endl;
    for (int i = 0; i < jumlahmasuk; i++) {
        cout << "Tanggal: " << keuangan[i].tanggal << endl;
        cout << "Jenis: " << keuangan[i].jenis << endl;
        cout << "Jumlah: " << keuangan[i].jumlah << endl;
    cout << "==================================" << endl;
    }
}

int searchrekursif(int left, int right, string target) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (keuangan[mid].tanggal == target) {
        return mid;
    }
    else if (keuangan[mid].tanggal > target) {
        return searchrekursif(left, mid - 1, target);
    }
    else {
        return searchrekursif(mid + 1, right, target);
    }
}

void caribinary() {
    if (jumlahmasuk == 0) {
        cout << "Tidak ada data keuangan untuk dicari." << endl;
        return;
    }

    string cari;
    cout << "|=========================|" << endl;
    cout << "|  Search Binary Rekursif |" << endl;
    cout << "|=========================|" << endl;
    cout << "Masukkan tanggal (DD/MM/YYYY): ";
    cin >> cari;

    sortkeuangan();
    
    int hasil = searchrekursif(0, jumlahmasuk - 1, cari);

    system("cls");
    if (hasil != -1) {
        cout << "|=======================|" << endl;
        cout << "|     Data Keuangan     |" << endl;
        cout << "|=======================|" << endl;
        cout << "Tanggal: " << keuangan[hasil].tanggal << endl;
        cout << "Jenis: " << keuangan[hasil].jenis << endl;
        cout << "Jumlah: " << keuangan[hasil].jumlah << endl;
    } else {
        cout << "Data dengan tanggal " << cari << " tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;
    do {
        menu();
        cout << "|Masukkan pilihan: ";
        cin >> pilihan;
        system("cls");

        switch (pilihan) {
            case 1:
                masuk();
                system("pause");
                system("cls");
                break;
            case 2:
                lihat();
                system("pause");
                system("cls");
                break;
            case 3:
                saldo();
                system("pause");
                system("cls");
                break;
            case 4:
                cari();
                system("pause");
                system("cls");
                break;
            case 5:
                caribinary();
                system("pause");
                system("cls");
                break;
            case 6:
                urutkandata();
                system("pause");
                system("cls");
                break;
            case 7:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 7);

    return 0;
}
