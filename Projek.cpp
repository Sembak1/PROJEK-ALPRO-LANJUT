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
    cout << "| 4. Search                 |" << endl;
    cout << "| 5. Sort                   |" << endl;
    cout << "| 6. Keluar                 |" << endl;
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

void seacrhgabung (){
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

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].tanggal <= R[j].tanggal) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Menejemen arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void sortmerge() {
    if (jumlahmasuk == 0) {
        cout << "Tidak ada data untuk diurutkan." << endl;
        return;
    }

    mergeSort(keuangan, 0, jumlahmasuk - 1);

    cout << "|==================================|" << endl;
    cout << "|      Data Setelah Diurutkan      |" << endl;
    cout << "|==================================|" << endl;
    for (int i = 0; i < jumlahmasuk; i++) {
        cout << "Tanggal: " << keuangan[i].tanggal << endl;
        cout << "Jenis: " << keuangan[i].jenis << endl;
        cout << "Jumlah: " << keuangan[i].jumlah << endl;
    }
}

void Sortgabung (){
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
                seacrhgabung();
                system("pause");
                system("cls");
                break;
            case 5:
                Sortgabung();
                system("pause");
                system("cls");
                break;
            case 6:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}
