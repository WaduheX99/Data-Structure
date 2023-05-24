#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct lagu{
    string judul;
    int durasi;
    string genre;
    lagu *next;
    lagu *prev;
};

lagu *head = NULL;
lagu *tail = NULL;

void tambahBelakang(string a, int b, string c){
    lagu *baru;
    lagu *bantu;
    baru = new lagu;
    baru -> judul = a;
    baru -> durasi = b;
    baru -> genre = c;
    baru -> next = NULL;
    baru -> prev = NULL;
    if (head == NULL){
        head = baru;
        tail = baru;
        //circullar
        tail -> next = head;
        head -> prev = tail;
        cout << "Data berhasil masuk!" << endl;
    }
    else {
        tail -> next = baru;
        baru -> prev = tail;
        tail = baru;
        //circullar
        tail -> next = head;
        head -> prev = tail;
        cout << "Data berhasil masuk!" << endl;
    }
}

void hapus(){
    lagu *bantu;
    lagu *hapus;
    string cariGenre;
    bool found = false;
    bantu = head;
    cout << "Masukkan genre musik yang ingin dihapus : ";
    cin.ignore();
    getline(cin, cariGenre);
    do 
    {
        //Menghapus data jika data hanya 1
        if(cariGenre == bantu -> genre && head == tail){
            hapus = head;
            head = NULL;
            tail == NULL;
            found = true;
            delete hapus;
            break;
        }

        //Menghapus data jika data berada di depan
        if(cariGenre == head -> genre){
            hapus = head;
            head = head -> next;
            tail -> next = head;
            head -> prev = tail;
            found = true;
            delete hapus;
            bantu = bantu -> next;
            continue;
        }

        //Menghapus data yang berada di tengah dan jika data lebih dari 1
        if(cariGenre == bantu -> genre && cariGenre != head -> genre){
            hapus = bantu;
            bantu -> prev -> next = bantu -> next;
            bantu -> next -> prev = bantu -> prev;
            found = true;
            delete hapus;
            bantu = bantu -> next;
            continue;
        }

        //Menghapus data yang berada di belakang
        if(cariGenre == tail -> genre){
            hapus = tail;
            tail = tail -> prev;
            tail -> next = head;
            head -> prev = tail;
            found = true;
            delete hapus;
            bantu = bantu -> next;
            continue;
        }

        bantu = bantu -> next;
        if(bantu == head){
            break;
        }
    }
    while (bantu != NULL);

    if(found == false){
        cout <<"Lagu tidak dapat ditemukan" << endl;
    }
    else{
        cout << "Genre " << cariGenre << " berhasil dihapus!" << endl;
    }
}

void tampil(){
    lagu *bantu;
    bantu = head;
    int z = 1;
    do 
    {
        cout << z << ". " << bantu -> judul << " | " << bantu -> durasi << " | " << bantu -> genre << endl;
        z++;
        bantu = bantu -> next;
    }
    while(bantu != head);
}

int main(){
    string jdl[10]={"Hati hati dijalan", 
                    "Ambyar", 
                    "Sisa Rasa", 
                    "What Have You Done", 
                    "Going Under", 
                    "The Catalyst",
                    "Menghapus Jejakmu",
                    "Milik Orang"};
            
    int dur[10]={5, 4, 3, 6, 8, 4, 4, 5};
    string gen[10]={"POP", "DANGDUT","POP", "ROCK", "ROCK", "ROCK", "POP", "DANGDUT"};

    string namaLagu, genreLagu;
    int durLagu;
    for(int x = 0; x < 8; x++){
        cout << jdl[x] << " " << dur[x] << " " << gen[x] << endl;
        tambahBelakang(jdl[x], dur[x], gen[x]);
    }

    int pilih;
    do
    {
        cout << "Implementasi DLL : Player Music" << endl;
        cout << "1. Tambah Belakang" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Tampil Data" << endl;
        cout << "4. Cari Data" << endl;
        cout << "5. Exit" << endl;
        cout << endl << "Pilihan Anda [1-5] : ";
       
        switch (pilih){  
        case 1 : system("cls"); 
            {
                cout << "Input Judul Lagu : ";
                cin.ignore();
                getline(cin, namaLagu);
                cout << "Input Durasi Lagu : ";
                cin.ignore();
                getline(cin, durLagu);
                cout << "Input Genre Lagu : ";
                cin.ignore();
                getline(cin, genreLagu);
                tambahBelakang(namaLagu, durLagu, genreLagu);

                getch();
                break;
            }
            case 2 : system("cls"); 
            {
                if (head == NULL){
                    cout << "Maaf data masih kosong!" << endl;
                }
                else {
                    
                }
                getch();
                break;
            }
            case 3 : system("cls");
            {
                if (head == NULL){
                    cout << "Maaf data masih kosong!";
                }
                else {
                    tampil();
                }
                getch();
                break;
            }
            case 4 : system("cls");
            {
                return 0;
                break;
            }
            default : system("cls");
            {
                cout << "Maaf pilihan tidak ada!" << endl;
                getch();
                break;
            }
        }
    } while (pilih!=5);
    
    cin.get();
    return 0;
}