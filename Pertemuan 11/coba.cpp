#include <iostream>
#include <conio.h>

using namespace std;

struct TNode{
    int numb1;
    int numb2;
    TNode *next;
};

TNode *head, *tail;

//Inisialisasi data
void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void insertDepan(int a, int b)
{
    TNode *baru;
    baru = new TNode;
    baru->numb1 = a;
    baru->numb2 = b;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head = tail = baru;
        tail -> next = NULL;
    }else
    {
        baru -> next = head;
        head = baru;
    }
    cout<<"Data masuk" << endl;
}

void insertTengah(int a, int b){
    system("cls");
    int pilihan;
    cout<<" ============================"<<endl;
    cout<<" =     Pilih Mode Insert    ="<<endl;
    cout<<" =  1. Insert Before        ="<<endl;
    cout<<" =  2. Insert After         ="<<endl;
    cout<<" ============================"<<endl;
    cin >> pilihan;
    switch (pilihan){
        case 1: system("cls");{
            TNode *baru;
            TNode *bantu;
            TNode *prebantu;
            baru = new TNode;
            if (head == NULL){
                head = baru;
                tail = baru;
            } else {
                int before;
                cout << "Memasukkan sebelum data : ";
                cin >> before;
                bantu = head;
                prebantu = bantu;
                baru -> numb1 = a;
                baru -> numb2 = b;
                bool find = false;
                do{
                    if (before == bantu -> numb1){
                        baru -> next = prebantu -> next;
                        prebantu -> next = baru;
                        find = true;
                        cout << "Data Masuk" << endl;
                    }
                    
                    prebantu = bantu;
                    bantu = bantu -> next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Sorry Data yang dicari tidak ada!";
                }
            }        
            break;
        }
        case 2: system("cls");{
            TNode *baru;
            TNode *bantu;
            baru = new TNode;
            baru -> numb1 = a;
            baru -> numb2 = b;
            baru -> next = NULL;
            if (head == NULL){
                head = baru;
                tail = baru;
            } else {
                int after;
                cout << "Memasukkan setelah data : ";
                cin >> after;
                bantu = head;
                bool find = false;
                do{
                    if (after == bantu -> numb2){
                        baru -> next = bantu -> next;
                        bantu -> next = baru;
                        find = true;
                        cout << "Data Masuk" << endl;
                    }
                    
                    bantu = bantu -> next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Maaf, data yang dicari tidak ada!";
                }
            }
            break;
        }
        default: system("cls");{
            cout << "Maaf, opsi yang Anda tidak valid!";
            break;
        }
    }
}

void insertBelakang(int a, int b){
    TNode *baru;
    baru = new TNode;
    baru -> numb1 = a;
    baru -> numb2 = b;
    baru -> next = NULL;
    if (head == NULL){
        head = baru;
        tail = baru;
    } else {
        tail -> next = baru;
        tail = baru;
    }
    cout<<"Data masuk" << endl;
}

void tampil(){
    TNode *bantu;
    bantu = head;
        if(isEmpty() == 0)
        {
            while(bantu != NULL)
            {
                cout << bantu -> numb1<<" ";
                cout << bantu -> numb2<<" " << endl;
                bantu = bantu -> next;
            }
        }else{ 
            cout << "Data masih kosong" << endl;
        }
}

void cariData(){
    if (head == NULL){
        cout << "Sorry Data Kosong";
    } else {
        TNode *bantu;
        int cari;
        cout << "Masukkan isi data : ";
        cin >> cari;
        bool find = false;
        bantu = head;

        do{
            if (cari == bantu -> numb1){
                cout << "Data " << bantu -> numb1 << " " << bantu -> numb2 << " Ketemu!";
                find = true;
            }
            if (cari == bantu -> numb2){
                cout << "Data " << bantu -> numb1 << " " << bantu -> numb2 << " Ketemu!";
                find = true;
            }
            
            bantu = bantu -> next;
        } while (bantu != NULL);

        if (find == false){
            cout << "Sorry Data tidak ada";
        }
    }
}

void hapusDepan()
{
    TNode *hapus;
    int d;
    if (isEmpty() == 0)
    {
        if(head != tail)
        {
            hapus = head;
            d = hapus -> numb1;
            head = head -> next;
            delete hapus;
        }else
        {
            d = tail -> numb1;
            head = tail = NULL;
        }
    cout << d <<"terhapus";
    }
    else {
        cout<<" Data masih kosong" << endl;
    }
}

void hapusTengah(){
    TNode *hapus;
    //TNode *prehapus;
    TNode *temp;
    hapus = head;
    //prehapus = hapus;
    bool success = false;
    int dataA;
    
    if(isEmpty() == 0){
        cout << "Masukkan Data : ";
        cin >> dataA;
        do{
            if (hapus -> next -> numb1 == dataA || hapus -> next -> numb2 == dataA){
                //prehapus -> next = hapus -> next;
                temp = hapus -> next;
                hapus -> next = hapus -> next -> next;
                success = true;
                cout << "Data " << temp -> numb1 << " " << temp -> numb2 << " berhasil dihapus!" << endl;
                delete temp;
            }
            //prehapus = hapus;
            hapus = hapus -> next;
        } while (hapus != NULL);
    
        if (success == false){
            cout << "Data tidak ditemukan!";
        }
        
    }
    else {
        cout<<" Data masih kosong" << endl;
    }
}
    
void hapusBelakang(){
    TNode *hapus;
    TNode *temp;
    hapus = head;
    
    if(isEmpty() == 0){
        while (hapus -> next != NULL){
            temp = hapus;
            hapus = hapus->next;
        }

        temp->next = NULL;
        cout << "Data " << hapus -> numb1 << " " << hapus -> numb2 << " telah terhapus!";
        delete hapus;
    }
    else {
        cout<<" Data masih kosong" << endl;
    }
}

void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    do{
        hapus = bantu;
        bantu = bantu -> next;
        delete hapus;
    } 
    while (bantu != NULL);
    
    head = NULL;
    cout << "Data telah dikosongkan" << endl;
}

main(){
    int pilih, dataA, dataB;
    do
    {
        system("cls");
        cout << endl;
        cout <<" ============================"<< endl;
        cout <<" ||   PROGRAM LINKED LIST  ||"<< endl;
        cout <<" ============================"<< endl;
        cout <<" || 1. Insert Depan        ||"<< endl;
        cout <<" || 2. Insert Tengah       ||"<< endl;
        cout <<" || 3. Insert Belakang     ||"<< endl;
        cout <<" || 4. Delete Depan        ||"<< endl;
        cout <<" || 5. Delete Tengah       ||"<< endl;
        cout <<" || 6. Delete Belakang     ||"<< endl;
        cout <<" || 7. Cari Data           ||"<< endl;
        cout <<" || 8. Tampil Data         ||"<< endl;
        cout <<" || 9. Clear               ||"<< endl;
        cout <<" || 10. Keluar Sistem      ||"<< endl;
        cout <<" ============================"<< endl;
        cout <<" Masukan Pilihan : ";
        cin >> pilih;
        switch (pilih)
        {
            case 1: system("cls");{
                cout<<"Masukan Data A = ";
                cin >> dataA;
                cout << "Masukan Data B = ";
                cin >> dataB;
                insertDepan(dataA, dataB);
                break;
            }
            case 2: system("cls");{
                cout << "Masukan Data A = ";
                cin >> dataA;
                cout << "Masukan Data B = ";
                cin >> dataB;
                insertTengah(dataA, dataB);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Data A = ";
                cin>>dataA;
                cout<<"Masukan Data B = ";
                cin>>dataB;
                insertBelakang(dataA, dataB);
                break;
            }
            case 4: system("cls");{
                hapusDepan();
                break;
            }
            case 5: system("cls");{
                hapusTengah();
                break;
            }
            case 6: system("cls");{
                hapusBelakang();
                break;
            }
            case 7: system("cls");{
                cariData();
                break;
            }
            case 8: system("cls");{
                tampil();
                break;
            }
            case 9: system("cls");{
                clear();
                break;
            }
            case 10: system("cls");{
                cout<<"Keluar sistem";
                return 0;
                break;
            }
            default : system("cls");{
                cout<<"Maaf, opsi yang Anda masukkan tidak valid!";
            }
        }
        getch();
    } 
    while(pilih!=10);
}