#include <iostream>
#include <conio.h>

using namespace std;

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

void tambahbelakang(string judul, int durasi, string genre)
{
    lagu *baru = new lagu;
    baru->judul = judul;
    baru->durasi = durasi;
    baru->genre = genre;
    baru->next = NULL;
    baru->prev = NULL;
    if(head == NULL)
    {
        head = baru;
        tail = baru;
        head->prev = tail;
        tail->next = head;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        head->prev = tail;
        tail->next = head;
    }
}

void tampil()
{
    int z=1;
    lagu *bantu;
    bantu = head;
    if(head == NULL)
    {
        cout<<"data kosong"<<endl;
    }
    else
    {
    do
    {
        cout<<z<<"."<<bantu->judul<<"-"<<bantu->durasi<<"-"<<bantu->genre<<endl;
        z++;
        bantu = bantu->next;
    }
    while(bantu != head);
    }
}

void hapusdata(string genre)
{
    lagu *bantu=head;
    lagu *hapus;
    bool flag = false;
    while(flag != true)
    {
        if(bantu->genre == genre)
        {
            hapus = bantu;
            bantu->next->prev = bantu->prev;
            bantu->prev->next = bantu->next;
            if(head == tail && bantu->genre == genre)
            {
                head = NULL;
                tail = NULL;
            }
            else if(bantu == head)
            {
                head = head->next;
            }
            else if (bantu == tail)
            {
                tail = tail->prev;
            }
            delete hapus;
        }
        if(bantu == tail || tail == NULL)
        {
            flag = true;
        }
        bantu = bantu->next;
    }
}

void caridata(string genre)
{
    lagu *bantu=head;
    int Cgenre = 0 ,Celse = 0, x = 1 ;
    int arr[50];
    string else1,else2;
    if(genre == "pop")
    {
        else1 = "dangdut";
        else2 = "rock";
    }else
    if(genre == "rock")
    {
        else1 = "dangdut";
        else2 = "pop";
    }else
    if(genre == "dangdut")
    {
        else1 = "pop";
        else2 = "rock";
    }
    do
    {
        if(bantu->genre == genre)
        {
            Cgenre++;
            arr[x] = 5;
        }
        else
        {
            Celse++;
            arr[x] = 0;
        }
        x++;
        bantu = bantu->next;
    }while(bantu != head);
    cout<<"genre lagu "<<genre<<" ada "<<Cgenre<<" lagu"<<endl;
    cout<<"terletak di data ke ";
    for(int i=0;i<x;i++)
    {
        if(arr[i] == 5)
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"sedangkan genre "<<else1<<" dan "<<else2<<" berjumlah "<<Celse<<endl;
}

int main()
{
    string jdl[10]={"hati-hati dijalan","ambyar","sisa rasa","what have you done","going under","the catalyst","menghapus jejakmu","milik orang"};
    int dur[10]={4,6,5,6,5,7,6,8};
    string gen[10]={"pop","pop","pop","rock","rock","rock","pop","dangdut"};
    for(int x=0;x<8;x++)
    {
        //cout<<jdl[x]<<" "<<dur[x]<<" "<<gen[x]<<endl;
        tambahbelakang(jdl[x],dur[x],gen[x]);
    }
    string genre;
    int pilih;
    do
    {
        system("cls");
        cout<<"implementasi DLL : player music"<<endl;
        cout<<"1. tambah belakang"<<endl;
        cout<<"2. hapus data"<<endl;
        cout<<"3. tampil data"<<endl;
        cout<<"4. cari data"<<endl;
        cout<<"5. exit"<<endl;
        cout<<"masukkan pilihan = ";
        cin>>pilih;
        if (pilih == 1)
        {
            int x = 9;
            cout<<"masukkan judul lagu = ";
            cin.ignore(1,'\n');
            getline(cin,jdl[x]);
            cout<<"masukkan durasi lagu = ";
            cin>>dur[x];
            cout<<"masukkan genre lagu = ";
            cin>>gen[x];
            tambahbelakang(jdl[x],dur[x],gen[x]);
            x++;
        }
        else if (pilih == 2)
        {
            cout<<"masukan genre yang ingin dihapus = ";
            cin>>genre;
            hapusdata(genre);
            getch();
        }
        else if (pilih == 3)
        {
            tampil();
            getch();
        }
        else if (pilih == 4)
        {
            cout<<"masukan genre yang ingin dicari = ";
            cin>>genre;
            caridata(genre);
            getch();
        }
    }while(pilih != 5);




    return 0;
}
