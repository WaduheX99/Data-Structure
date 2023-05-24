/* Faza Faresha Affandi
   A11.2021.13917       */

#include <iostream>

using namespace std;

struct stack
{
    string nama;
    int Nilai;
    stack *next;
};

stack *head=NULL, *tail=NULL;
int top=1;
int maks=5;

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(){
    if(top > maks){
        return 1;
    }
    else {
        return 0;
    }
}

void insert_belakang(int a, string b){
    stack *baru;
    baru = new stack;
    baru -> Nilai = a;
    baru -> nama = b;
    baru -> next = NULL;
    if (head == NULL){
        head = baru;
        tail = baru;
    } else {
        tail -> next = baru;
        tail = baru;
    }
    top++;
    cout<<"Data masuk" << endl;
}

void delete_belakang(){
    stack *hapus;
    stack *temp;
    hapus = head;
    
    if(isEmpty() == 0){
        while (hapus -> next != NULL){
            temp = hapus;
            hapus = hapus->next;
        }

        temp->next = NULL;
        cout << "Data " << hapus -> Nilai << " " << hapus -> nama << " telah terhapus!" << endl;
        delete hapus;
        top--;
    }
    else {
        cout<<" Data masih kosong" << endl;
    }
}

void tampil_data(){
    stack *bantu;
    bantu = head;
    int i = 1;
        if(isEmpty() == 0)
        {
            while(bantu != NULL)
            {
                cout << i << ") " << bantu -> Nilai << " "<< bantu -> nama << endl;
                bantu = bantu -> next;
                i++;
            }
        }else{ 
            cout << "Data masih kosong" << endl;
        }
}

int main()
{
    int pilih, dataA;
    string dataB;

    do
    {
        cout<<"MENU STACK"<<endl;
        cout<<"1. Push Data"<<endl;
        cout<<"2. Pop Data"<<endl;
        cout<<"3. Tampil Data"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<endl<<"Pilihan anda [1-4] : ";
        cin>>pilih;
        if(pilih==1)
        {
            if(isFull()==1){
                cout << "Data sudah penuh" << endl;
            }
            else {
                cout << "Masukkan Nilai = ";
                cin >> dataA;
                cout << "Masukkan Nama = ";
                cin >> dataB;
                insert_belakang(dataA, dataB);
            }
        }
        if(pilih==2)
        {
            delete_belakang();
        }
        if(pilih==3)
        {
            tampil_data();
        }
    }
    while(pilih!=4);
    return 0;
}
