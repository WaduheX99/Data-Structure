#include <iostream>
#include <conio.h>
#define n 10

using namespace std;

struct mahasiswa{
    string nama;
    int nim;
}Mhs[n];

struct queue{
    int awal, akhir;
}Queue;

void init(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << "Data berhasil di reset" << endl << endl;
}

int isFull(){
    if(Queue.akhir == n - 1){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(){
    if(Queue.akhir == -1){
        return 1;
    }else {
        return 0;
    }
}

void inQueue(){
    if(isFull() == 0){
        string nama;
        int nim;
        cout << "Masukkan nama mahasiswa : ";
        cin >> nama;
        cout << "Masukkan NIM mahasiswa : ";
        cin >> nim;
        Mhs[Queue.akhir].nama = nama;
        Mhs[Queue.akhir].nim = nim;
        ++Queue.akhir;
        cout << endl;
    }else {
        cout << "Data penuh";
    }
}

void deQueue(){
    if(isEmpty() == 0){
        for(int i = Queue.awal; i < Queue.akhir; i++){
            Mhs[i].nama = Mhs[i+1].nama;
            Mhs[i].nim = Mhs[i+1].nim;
        }Queue.akhir--;
        cout << "Data berhasil dihapus" << endl;
        cout << endl;
    }else{
        cout << "antrian kosong" << endl;
    }
}

void tampil(){
    if(isEmpty() == 0){
        for(int i = 0; i < Queue.akhir; i++){
            cout << "Nama Mahasiswa: " << Mhs[i].nama << endl;
            cout << "NIM : " << Mhs[i].nim << endl; 
            cout << endl;
        }
    }else if (isEmpty() == 1) {
        cout << "Data masih kosong"<< endl << endl;
    }
}

int main(){
    int pilih;
    do {
        system("cls");
        cout << "1. masukkan data" << endl;
        cout << "2. Hapus satu data" << endl;
        cout << "3. Reset data" << endl;
        cout << "4. tampil data" << endl;
        cout << "5. Keluar Sistem" << endl;
        cout << "Masukkan pilihan anda [1-5] : ";
        cin >> pilih;
        cout << endl;
        switch (pilih){
            case 1 : system("cls");
            {
                inQueue();
                break;
            }
            case 2 : system("cls");
            {
                deQueue();
                break;
            }
            case 3 : system("cls");
            {
                init();
                break;
            }
            case 4 : system("cls");
            {
                tampil();
                break;
            }
            case 5 : system("cls");
            {
                cout << "Keluar Sistem" << endl;
                return 0;
                break;
            }
            default : system("cls");
            {
                cout << "Opsi yang Anda masukkan tidak valid" << endl;
            }
        }
        getch();
    }
    while(pilih != 5);
}