#include <iostream>

using namespace std;

struct dll{
    int nilai;
    dll *next;
    dll *prev;
};

dll *head = NULL;
dll *tail = NULL;

void addDepan(){
    dll *baru;
    baru = new dll;
    cout << "Masukkan Data : ";
    cin >> baru -> nilai;
    baru -> next = NULL;
    baru -> prev = NULL;
    if(head == NULL){
        head = baru;
        tail = baru;
        baru -> next = tail;
        baru -> prev = head;
    }
    else {
        baru -> next = head;
        head -> prev = baru;
        head = baru;
        head -> prev = tail;
        tail -> next = head;
    }
}

void TampilDepan() {
    dll *bantu;
    bantu = head;
    cout << endl;
    do {
        cout << bantu -> nilai;
        bantu = bantu -> next;
    }
    while (bantu != head);
}

void TampilBelakang() {
    dll *bantu;
    bantu = tail;
    do {
        
    }
}

int main() {
    int pilih;
    do {
        cout << "Struktur Data : DOUBLE LINKED LIST" << endl;
        cout << "1. Tambah Data di Depan" << endl;
        cout << "2. Tambah Data di Tengah" << endl;
        cout << "3. Tambah Data di Belakang" << endl;
        cout << "4. Hapus Data di Depan" << endl;
        cout << "5. Hapus Data di Tengah" << endl;
        cout << "6. Hapus Data di Belakang" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Tampil Data dari Depan" << endl;
        cout << "9. Tampil Data dari Belakang" << endl;
        cout << "10. Selesai" << endl;
        cout << endl << "Pilihan Anda [1-10]";
        cin >> pilih;
        if(pilih == 1) {
            addDepan();
        }
        if (pilih == 8){
            TampilDepan();
        }
        if (pilih == 9) {
            TampilBelakang();
        }
    }
    while(pilih!=10);
    return 0;
}