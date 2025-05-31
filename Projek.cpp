#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Menejemen {
    string tanggal;
    string jenis;
    long long jumlah;
};
Menejemen keuangan[1000];
int jumlahmasuk = 0;

void simpanfile() {
    ofstream file("data.txt");  
    if (!file) {  
        return;  
    }
    for (int i = 0; i < jumlahmasuk; i++) {
        file << keuangan[i].tanggal << ",";
        file << keuangan[i].jenis << ",";
        file << keuangan[i].jumlah << endl;
    }
    file.close();
}

void bacafile() {
    ifstream file("data.txt");
    if (!file) {
        return;
    }

    jumlahmasuk = 0;
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');

        if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) continue;

        keuangan[jumlahmasuk].tanggal = line.substr(0, pos1);
        keuangan[jumlahmasuk].jenis = line.substr(pos1 + 1, pos2 - pos1 - 1);
        keuangan[jumlahmasuk].jumlah = stoll(line.substr(pos2 + 1));

        jumlahmasuk++;
        if (jumlahmasuk >= 1000) break;
    }

    file.close();
}

void masuk(){
    int pilihan;
    bacafile();
    Menejemen* ptr = &keuangan[jumlahmasuk];
    cout << "|========================================|" << endl;
    cout << "|             Masukan Transaksi          |" << endl;
    cout << "|========================================|" << endl;
    cout << "Masukkan tanggal (dd-mm-yyyy) : ";
    cin >> ptr->tanggal;
    cout << "Pilih jenis transaksi: " << endl;
    cout << "1. Pemasukan" << endl;
    cout << "2. Pengeluaran" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;
    
    if (pilihan == 1) {
        ptr->jenis = "Pemasukan";
    } else if (pilihan == 2) {
        ptr->jenis = "Pengeluaran";
    } else {
        cout << "Pilihan tidak valid. Transaksi dibatalkan" << endl;
        return;}
    cout << "Masukkan jumlah: ";
    cin >> ptr->jumlah;
    if (ptr->jumlah < 0) {
    cout << "Jumlah tidak boleh negatif. Transaksi dibatalkan" << endl;
    return;}
    jumlahmasuk++;
    simpanfile(); 
}

void lihat() {
    bacafile();
    if (jumlahmasuk == 0) {
        cout << "Belum ada transaksi yang tercatat." << endl;
        return;
    }

    cout << "|===========================|" << endl;
    cout << "|        Data Keuangan     |" << endl;
    cout << "|===========================|" << endl;
    Menejemen* ptr = keuangan;
    for (int i = 0; i < jumlahmasuk; i++) {
        cout << "Tanggal : " << (ptr + i)->tanggal << endl;
        cout << "Jenis   : " << (ptr + i)->jenis << endl;
        cout << "Jumlah  : " << (ptr + i)->jumlah << endl;
        cout << "============================" << endl;
    }
}


void saldo() {
    if (jumlahmasuk == 0) {
        cout << "Belum ada transaksi yang tercatat." << endl;
        return;
    }

    long long saldo = 0;
    Menejemen* ptr = keuangan;
    for (int i = 0; i < jumlahmasuk; i++) {
        if ((ptr + i)->jenis == "Pemasukan") {
            saldo += (ptr + i)->jumlah;
        } else {
            saldo -= (ptr + i)->jumlah;
        }
    }

    cout << "|=======================|" << endl;
    cout << "|      Lihat Saldo      |" << endl;
    cout << "|=======================|" << endl;
    cout << "Saldo Anda: Rp " << saldo << endl;
}

void cari() {
    if (jumlahmasuk == 0) {
        cout << "Belum ada data untuk dicari." << endl;
        return;
    }

    string cari;
    cout << "|===============================|" << endl;
    cout << "|            Search             |" << endl;
    cout << "|===============================|" << endl;
    cout << "Masukkan tanggal (dd-mm-yyyy) : ";
    cin >> cari;
    system("cls");

    bool ditemukan = false;
    Menejemen* ptr = keuangan;
    for (int i = 0; i < jumlahmasuk; i++) {
        if ((ptr + i)->tanggal == cari) {
            cout << "|=======================|" << endl;
            cout << "|     Data Keuangan     |" << endl;
            cout << "|=======================|" << endl;
            cout << "Tanggal: " << (ptr + i)->tanggal << endl;
            cout << "Jenis: " << (ptr + i)->jenis << endl;
            cout << "Jumlah: " << (ptr + i)->jumlah << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Data dengan tanggal " << cari << " tidak ditemukan." << endl;
    }
}

void hapus() {
    if (jumlahmasuk == 0) {
        cout << "Tidak ada data untuk dihapus." << endl;
        return;
    }

    cout << "|===========================|" << endl;
    cout << "|        Hapus Data         |" << endl;
    cout << "|===========================|" << endl;
    cout << "Masukkan tanggal (dd-mm-yyyy) : ";
    string tanggal;
    cin >> tanggal;

    for (int i = 0; i < jumlahmasuk; i++) {
        if (keuangan[i].tanggal == tanggal) {
            for (int j = i; j < jumlahmasuk - 1; j++) {
                keuangan[j] = keuangan[j + 1];
            }
            jumlahmasuk--;
            simpanfile();
            cout << "Data dengan tanggal " << tanggal << " berhasil dihapus." << endl;
            return;
        }
    }

    cout << "Data dengan tanggal " << tanggal << " tidak ditemukan." << endl;
}

void sortkeuangan() {
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
    if (jumlahmasuk == 0) {
        cout << "Tidak ada data untuk diurutkan." << endl;
        return;
    }

    sortkeuangan();
    cout << "|================================|" << endl;
    cout << "|     Data Setelah Diurutkan     |" << endl;
    cout << "|================================|" << endl;
    for (int i = 0; i < jumlahmasuk; i++) {
        cout << "Tanggal: " << keuangan[i].tanggal << endl;
        cout << "Jenis: " << keuangan[i].jenis << endl;
        cout << "Jumlah: " << keuangan[i].jumlah << endl;
        cout << "==================================" << endl;
    }
}
int searchrekursif(int left, int right, string target) {
    if (left > right) { return -1;}
    int mid = left + (right - left) / 2;
    if (keuangan[mid].tanggal == target) {
        return mid;}
    else if (keuangan[mid].tanggal > target) {
        return searchrekursif(left, mid - 1, target);}
    else {
        return searchrekursif(mid + 1, right, target);}
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
    cout << "Masukkan tanggal (dd-mm-yyyy): ";
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

void searchgabung (){
    cout << "Pilih Opsi Seacrh" << endl;
    cout << "1. Search Binary Rekursif " << endl;
    cout << "2. Search Linear          " << endl;
    cout << "Pilih opsi: ";
    int pilihan;
    cin >> pilihan;
    system("cls");
    if (pilihan == 1) {
        caribinary();
    } else if (pilihan == 2) {
        cari();
    } else {
        cout << "Pilihan tidak ada." << endl;
    }
}

void merge(Menejemen arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Menejemen L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].tanggal <= R[j].tanggal) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergesort(Menejemen arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void sortmerge() {
    if (jumlahmasuk == 0) {
        cout << "Tidak ada data untuk diurutkan." << endl;
        return;
    }

    mergesort(keuangan, 0, jumlahmasuk - 1);

    cout << "|==================================|" << endl;
    cout << "|      Data Setelah Diurutkan      |" << endl;
    cout << "|==================================|" << endl;
    for (int i = 0; i < jumlahmasuk; i++) {
        cout << "Tanggal: " << keuangan[i].tanggal << endl;
        cout << "Jenis: " << keuangan[i].jenis << endl;
        cout << "Jumlah: " << keuangan[i].jumlah << endl;
    }
}

void sortgabung (){
    cout << "Pilih Opsi Sort" << endl;
    cout << "1. Sort Selection " << endl;
    cout << "2. Sort Merge          " << endl;
    cout << "Pilih opsi: ";
    int pilihan;
    cin >> pilihan;
    system("cls");
    if (pilihan == 1) {
        urutkandata();
    } else if (pilihan == 2) {
        sortmerge();
    } else {
        cout << "Pilihan tidak ada." << endl;
    }
}

void menu() {
    cout << "|===========================|" << endl;
    cout << "|    Manajemen Keuangan     |" << endl;
    cout << "|===========================|" << endl;
    cout << "| 1. Masukkan Transaksi     |" << endl;
    cout << "| 2. Lihat Transaksi        |" << endl;
    cout << "| 3. Lihat Saldo            |" << endl;
    cout << "| 4. Mencari Transaksi      |" << endl;
    cout << "| 5. Urutkan Transaksi      |" << endl;
    cout << "| 6. Hapus Transaksi        |" << endl;
    cout << "| 7. Keluar                 |" << endl;
    cout << "|===========================|" << endl;
}

int main() {
    bacafile();   
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
                searchgabung();
                system("pause");
                system("cls");
                break;
            case 5:
                sortgabung();
                system("pause");
                system("cls");
                break;
          
            case 6:
                hapus();
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
