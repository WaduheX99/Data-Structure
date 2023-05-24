#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

//  Faza Faresha Affandi
//  A11.2021.13917
//  A11.43UG2

struct lagu
{
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
    baru->judul = a;
    baru->durasi = b;
    baru->genre = c;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL){
        head = baru;
        tail = baru;
        //circullar
        tail->next = head;
        head->prev = tail;
        cout << "Data berhasil masuk!\n";
    }
    else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        //circullar
        tail->next = head;
        head->prev = tail;
        cout << "Data berhasil masuk!\n";
    }
}

void hapusLagu(){
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

void cariJudulLagu(){
    if (head == NULL){
        cout << "Maaf Playlist masih Kosong";
    }
    else {
        lagu* bantu;
        string cariJudul;
        bool find = false;
        bantu = head;
        cout << "Masukkan judul lagu : ";
        cin.ignore();
        getline(cin, cariJudul);
        do {
            if (cariJudul == bantu -> judul){
                cout << "Judul lagu " << bantu -> judul << " ketemu!";
                find = true;
                break;
            }

            bantu = bantu -> next;
        } while (bantu != head);

        if (find == false){
            cout << "Judul lagu tidak ada";
        }
    }
}

void cariGenreLagu(string cariGenre){
    if (head == NULL){
        cout << "Maaf Playlist masih Kosong";
    }
    else {
        lagu* bantu;
        int Cgenre = 0, Celse = 0, x = 1, y = 1;
        int arr[50];
        string else1, else2, else3;
        bantu = head;
        if(cariGenre == "POP"){
            else1 = "ROCK";
            else2 = "EDM";
            else3 = "RAP";
        }
        else if(cariGenre == "ROCK") {
            else1 = "POP";
            else2 = "EDM";
            else3 = "RAP";
        }
        else if(cariGenre == "EDM"){
            else1 = "ROCK";
            else2 = "POP";
            else3 = "RAP";
        }
        else if(cariGenre == "RAP"){
            else1 = "ROCK";
            else2 = "EDM";
            else3 = "POP";
        }
        do {
            if (bantu -> genre == cariGenre){
                cout << y << ". " << bantu -> judul << " | " << bantu -> durasi << " | " << bantu -> genre << endl;
                y++;
                Cgenre++;
                arr[x] = 5;
            }
            else {
                Celse++;
                arr[x] = 0;
            }
            x++;
            bantu = bantu -> next;
            
        } while (bantu != head);

        cout << "Genre Lagu " << cariGenre << " ada " << Cgenre << " Lagu." << endl;
        cout << "Yang berada di urutan Nomor ";
        for(int i = 0; i < x; i++){
            if(arr[i] == 5){
                cout << i << " ";
            }
        }
        cout << endl;
        cout << "Sedangkan genre " << else1 << ", " << else2 << ", dan " << else3 << " berjumlah " << Celse << endl;
    }
} 

int main()
{
    string jdl[8] = {"Backburner",
                           "Boulevard of Broken Dreams",
                           "Keeping Tabs",
                           "Sweet Caroline",
                           "All the Fucking Time",
                           "Head In The Clouds",
                           "Runaway",
                           "History"};

    int dur[8] = {4, 4, 3, 2, 3, 3, 3, 2};
    string gen[8] = {"POP", "ROCK", "POP", "POP",
                            "POP", "POP", "EDM", "RAP"};

    string namaLagu, genreLagu, cariGenre;
    int pilih, durLagu;
    lagu* bantu;
    bool find = false;

    for (int x = 0; x < 8; x++)
    {
        cout << jdl[x] << " " << dur[x] << " " << gen[x] << endl;
        tambahBelakang(jdl[x], dur[x], gen[x]);
    }

    do
    {
        system("cls");
        cout << endl;
        cout << " =============================" << endl;
        cout << " =   PROGRAM PLAYLIST LAGU   =" << endl;
        cout << " =============================" << endl;
        cout << " = 1. Insert Lagu            =" << endl;
        cout << " = 2. Hapus Lagu             =" << endl;
        cout << " = 3. Tampil Lagu            =" << endl;
        cout << " = 4. Cari Judul Lagu        =" << endl;
        cout << " = 5. Cari Genre Lagu        =" << endl;
        cout << " = 6. Exit Program           =" << endl;
        cout << " =============================" << endl;
        cout << " Pilihan : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            system("cls");
            {
                cout << "Masukkan nama lagu   : "; 
                cin.ignore();
                getline(cin, namaLagu);
                cout << "Masukkan durasi lagu : "; 
                cin >> durLagu;
                cout << "Masukkan genre lagu  : "; 
                cin.ignore();
                getline(cin, genreLagu);
                tambahBelakang(namaLagu, durLagu, genreLagu);
                
                getch();
                break;
            }
        case 2:
            system("cls");
            {
                if (head == NULL)
                {
                    cout << "Maaf data masih kosong!\n";
                } else {
                    hapusLagu();
                }
                getch();
                break;
            }
        case 3:
            system("cls");
            {
                if (head == NULL){
                    cout << "Maaf data lagu kosong!";
                } 
                else {
                    tampil();
                }
                
                getch();
                break;
            }
        case 4:
            system("cls");
            {
                cariJudulLagu();
                getch();
                break;
            }
        case 5:
            system("cls");
            {
                cout << "Masukkan genre lagu : ";
                cin >> cariGenre;
                cariGenreLagu(cariGenre);
                
                getch();
                break;
            }
        case 6:
            system("cls");
            {
                return 0;
                break;
            }
        default:
            system("cls");
            {
                cout << "Maaf pilihan tidak ada!\n";
                getch();
                break;
            }
        }
    } while (pilih != 6);

    cin.get();
    return 0;
}