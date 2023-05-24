#include <iostream>
#include <conio.h>

using namespace std;

struct TNode{
    int numb1;
    int numb2;
    string target;
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

void insertDepan(int a, int b, string nama)
{
    TNode *baru;
    baru = new TNode;
    baru->numb1 = a;
    baru->numb2 = b;
    baru->target = nama;
    baru->next = NULL;
    if(isEmpty()==1){
        head = tail = baru;
        tail -> next = NULL;
    }
    else{
        baru -> next = head;
        head = baru;
    }
    cout<<"Data masuk" << endl;
}

void insertTengah(int a, int b, string nama){
    TNode *baru;
    TNode *bantu;
    TNode *prebantu;
    baru = new TNode;
    bantu = head;
    prebantu = bantu;
    baru -> numb1 = a;
    baru -> numb2 = b;
    baru -> target = nama;
    system("cls");
    int pilihan;
    cout<<" ============================"<<endl;
    cout<<" ||    Pilih Mode Insert   ||"<<endl;
    cout<<" || 1. Insert Before       ||"<<endl;
    cout<<" || 2. Insert After        ||"<<endl;
    cout<<" ============================"<<endl;
    cin >> pilihan;
    switch (pilihan){
        case 1: system("cls");{
            if (head == NULL){
                head = baru;
                tail = baru;
            } else {
                int before;
                cout << "Memasukkan sebelum data : ";
                cin >> before;
                bool find = false;
                do{
                    if (before == bantu -> numb1 || before == bantu -> numb2 ){
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
                    if (after == bantu -> numb1 || after == bantu -> numb2){
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
            cout << "Maaf, opsi yang Anda pilih tidak valid!";
            break;
        }
    }
}

void insertBelakang(int a, int b, string nama){
    TNode *baru;
    baru = new TNode;
    baru -> numb1 = a;
    baru -> numb2 = b;
    baru -> target = nama;
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
    int i = 1;
        if(isEmpty() == 0)
        {
            while(bantu != NULL)
            {
                cout << i << ") " << bantu -> numb1 << " "<< bantu -> numb2 << " " << bantu -> target << endl;
                bantu = bantu -> next;
                i++;
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
        int cariAngka, opsi;
        string cariNama;
        bool find = false;
        bantu = head;
        
        system("cls");
        cout<<" ============================"<<endl;
        cout<<" || Pilih Metode Pencarian ||"<<endl;
        cout<<" || 1. Cari Angka          ||"<<endl;
        cout<<" || 2. Cari Nama           ||"<<endl;
        cout<<" ============================"<<endl;
        cin >> opsi;
        switch (opsi){
            case 1: system("cls");{
                cout << "Masukkan angka yang ingin dicari : ";
                cin >> cariAngka;
                do{
                    if (cariAngka == bantu -> numb1){
                        cout << "Data " << bantu -> numb1 << " " << bantu -> numb2 << " " << bantu -> target << " ditemukan";
                        find = true;
                    }
                    if (cariAngka == bantu -> numb2){
                        cout << "Data " << bantu -> numb1 << " " << bantu -> numb2 << " " << bantu -> target << " ditemukan";
                        find = true;
                    }
                    bantu = bantu -> next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Sorry Data tidak ada";
                }   

                break;
            }
            case 2 : system("cls");{
                cout << "Masukkan nama yang ingin dicari : ";
                cin >> cariNama;
                do{
                    
                    if (cariNama == bantu -> target){
                        cout << "Data " << bantu -> numb1 << " " << bantu -> numb2 << " " << bantu -> target << " ditemukan";
                        find = true;
                    }
                    bantu = bantu -> next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Sorry Data tidak ada";
                }

                break;
            }
            default: system("cls");{
                cout << "Maaf, opsi yang Anda pilih tidak valid!";
                break;
            }
        }    
    }
}

void hapusDepan()
{
    TNode *hapus;
    int e, f;
    string g;
    if (isEmpty() == 0)
    {
        if(head != tail)
        {
            hapus = head;
            e = hapus -> numb1;
            f = hapus -> numb2;
            g = hapus -> target;
            head = head -> next;
            delete hapus;
        }
        else{
            e = tail -> numb1;
            f = tail -> numb2;
            g = tail -> target;
            head = tail = NULL;
        }
    cout << "Data " << e << " " << f << " " << g <<" berhasil dihapus";
    }
    else {
        cout<<" Data masih kosong" << endl;
    }
}

void hapusTengah(){
    TNode *hapus;
    TNode *prehapus;
    TNode *temp;
    hapus = head;
    prehapus = hapus;
    bool success = false;
    int cariAngka2, opsi2; 
    string cariNama2;
    
    if(isEmpty() == 0){
        system("cls");
        cout<<" ============================"<<endl;
        cout<<" || Pilih Metode Hapus     ||"<<endl;
        cout<<" || 1. Hapus dengan Angka  ||"<<endl;
        cout<<" || 2. Hapus dengan Nama   ||"<<endl;
        cout<<" ============================"<<endl;
        cin >> opsi2;
        switch (opsi2){
            case 1: system("cls");{
                cout << "Masukkan angka untuk menghapus data : ";
                cin >> cariAngka2;
                do{
                if (hapus -> numb1 == cariAngka2 || hapus -> numb2 == cariAngka2){
                    prehapus -> next = hapus -> next;
                    temp = hapus;
                    temp -> next = NULL;
                    success = true;
                    cout << "Data " << temp -> numb1 << " " << temp -> numb2 << " " << temp -> target << " berhasil dihapus!" << endl;
                    delete temp;
                }
                prehapus = hapus;
                hapus = hapus -> next;
                } while (hapus != NULL);
            
                if (success == false){
                    cout << "Data tidak ditemukan!";
                }
                break;
            }
            case 2 : system("cls");{
                cout << "Masukkan nama untuk menghapus data : ";
                cin >> cariNama2;
                do{
                if (hapus -> target == cariNama2){
                    prehapus -> next = hapus -> next;
                    temp = hapus;
                    temp -> next = NULL;
                    success = true;
                    cout << "Data " << temp -> numb1 << " " << temp -> numb2 << " " << temp -> target << " berhasil dihapus!" << endl;
                    delete temp;
                }
                prehapus = hapus;
                hapus = hapus -> next;
                } while (hapus != NULL);
            
                if (success == false){
                    cout << "Data tidak ditemukan!";
                }

                break;
            }
            default: system("cls");{
                cout << "Maaf, opsi yang Anda pilih tidak valid!";
                break;
            }
        }
    }
    else {
        cout <<" Data masih kosong" << endl;
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
        cout << "Data " << hapus -> numb1 << " " << hapus -> numb2 << " " << hapus -> target << " telah terhapus!";
        delete hapus;
    }
    else {
        cout<<" Data masih kosong" << endl;
    }
}

void clear()
{
    TNode *bantu, *hapus;
    bantu = head;
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
    string dataC;

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
        cout <<" || 4. Hapus Depan         ||"<< endl;
        cout <<" || 5. Hapus Tengah        ||"<< endl;
        cout <<" || 6. Hapus Belakang      ||"<< endl;
        cout <<" || 7. Cari Data           ||"<< endl;
        cout <<" || 8. Tampil Data         ||"<< endl;
        cout <<" || 9. Hapus Semua Data    ||"<< endl;
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
                cout << "Masukkan Nama = ";
                cin >> dataC;
                insertDepan(dataA, dataB, dataC);
                break;
            }
            case 2: system("cls");{
                cout << "Masukan Data A = ";
                cin >> dataA;
                cout << "Masukan Data B = ";
                cin >> dataB;
                cout << "Masukkan Nama = ";
                cin >> dataC;
                insertTengah(dataA, dataB, dataC);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Data A = ";
                cin>>dataA;
                cout<<"Masukan Data B = ";
                cin>>dataB;
                cout << "Masukkan Nama = ";
                cin >> dataC;
                insertBelakang(dataA, dataB, dataC);
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