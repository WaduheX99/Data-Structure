#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode
{
    int data;
    int NilaiX;
    int NilaiY;
    TNode *next;
};

TNode *head, *tail;

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(head==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void insertDepan(int databaru1, int databaru2){
    TNode *baru;
    baru = new TNode;
    baru -> NilaiX = databaru1;
    baru -> NilaiY = databaru2;
    baru -> next = NULL;
    if(isEmpty()==1){
        head = tail = baru;
        tail -> next = NULL;
    }
    else {
        baru -> next = head;
        head = baru;
    }
    cout << "Data masuk" << endl;
}

void tampil(){
    TNode *bantu;
    bantu = head;
    if(isEmpty()==0){
        while(bantu!=NULL){
            cout << bantu -> data <<" ";
            bantu = bantu -> next;
        }
    }
    else {
        cout << "Masih kosong" << endl;
    }
}

void insertDepan(int databaru1, int databaru2){
    TNode *baru;
    baru = new TNode;
    baru -> NilaiX = databaru1;
    baru -> NilaiY = databaru2;
    baru -> next = NULL;
    if(isEmpty()==1){
        head = tail = baru;
        tail -> next = NULL;
    }
    else {
        tail -> next = head;
        tail = baru;
    }
    cout << "Data masuk" << endl;
}

void hapusDepan(){
    TNode *hapus;
    int d;
    if(isEmpty()==0){
        if(head!=tail) {
            hapus = head;
            d = hapus -> data;
            head = head -> next;
            delete hapus;
        }
        else {
            d = tail -> data;
            head = tail = NULL;
        }
        cout << d << "Terhapus";
    }
    else {
        cout << "Masih kosong" << endl;
    }
}

void clear(){
    TNode *bantu, *hapus;
    bantu = head;
    while(bantu!=NULL) {
        hapus = bantu;
        bantu = bantu -> next;
        delete hapus;
    }
    head = NULL;
    cout << "clear" << endl;
}

main() {
    int pil, databaru1, databaru2;
    do {
        system("cls");
        cout << endl;
        cout << "====================================="<< endl;
        cout << "          PROGRAM LINKED LIST        "<< endl;
        cout << "====================================="<< endl;
        cout << "= 1. Insert Depan                   ="<< endl;
        cout << "= 2. Delete Depan                   ="<< endl;
        cout << "= 3. Tampil Data                    ="<< endl;
        cout << "= 4. Clear                          ="<< endl;
        cout << "= 5. Exit                           ="<< endl;
        cout << "====================================="<< endl;
        cout << "Masukkan Pilihan : " << endl;
        cin >> pil;
        switch (pil)
        {
            case 1 : system("cls");
            {
                cout << "Masukkan Data X :" << endl;
                cin >> databaru1;
                cout << "Masukkan Data y :" << endl;
                cin >> databaru2;
                insertDepan(databaru1, databaru2);
                break;
            }
            case 2 : system("cls");
            {
                hapusDepan();
                break;
            }
            case 3 : system("cls");
            {
                tampil();
                break;
            }
            case 4 : system("cls");
            {
                clear();
                break;
            }
            case 5 : system("cls");
            {
                return 0;
                break;
            }
            default :
            {
                cout << "Maaf, opsi tidak valid" << endl;
                break;
            }
        }
    }
    while(pil!=7);
}