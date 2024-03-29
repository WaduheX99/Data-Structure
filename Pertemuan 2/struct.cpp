#include <iostream>

using namespace std;

struct date{
    int tgl, bln, thn;
};

struct nilai
{
    char nim[5];
    char nama[30];
    struct date tgl_lahir;
    int nilai;
};

struct nilai matematika[100];

void tanggalnya(struct date x){
    if(x.bln == 1){
        cout << x.tgl <<" Januari " << x.thn;
    }
    if(x.bln == 2){
        cout << x.tgl <<" Februari " << x.thn;
    }
    if(x.bln == 3){
        cout << x.tgl <<" Maret " << x.thn;
    }
    if(x.bln == 4){
        cout << x.tgl <<" April " << x.thn;
    }
    if(x.bln == 5){
        cout << x.tgl <<" Mei " << x.thn;
    }
    if(x.bln == 6){
        cout << x.tgl <<" Juni " << x.thn;
    }
    if(x.bln == 7){
        cout << x.tgl <<" Juli " << x.thn;
    }
    if(x.bln == 8){
        cout << x.tgl <<" Agustus " << x.thn;
    }
    if(x.bln == 9){
        cout << x.tgl <<" September " << x.thn;
    }
    if(x.bln == 10){
        cout << x.tgl <<" Oktober " << x.thn;
    }
    if(x.bln == 11){
        cout << x.tgl <<" November " << x.thn;
    }
    if(x.bln == 12){
        cout << x.tgl <<" Desember " << x.thn;
    }
}

int main(){

    int x=1, y;
    char jawab;
    float avg, total = 0;

    do{
        cout <<"Data Ke - " << x << endl;
        cout <<"Inputkan NIM            : ";
        cin >> matematika[x].nim;

        cout <<"Inputkan Nama           : ";
        cin >> matematika[x].nama;

        cout <<"Inputkan Tanggal Lahir  : ";
        cin >> matematika[x].tgl_lahir.tgl;
        cin >> matematika[x].tgl_lahir.bln;
        cin >> matematika[x].tgl_lahir.thn;

        cout <<"Inputkan Nilai          : ";
        cin >> matematika[x].nilai;
        cout << endl;

        total = total + matematika[x].nilai;

        cout <<"Ada data lagi ? [Y/T]  : ";
        cin >> jawab;
        cout << endl;
        x++;
    }

    while(jawab == 'y' || jawab == 'Y');
    avg = total / (x-1);
    cout << endl << endl <<"Nilai rata-rata     : " << avg << endl << endl;
    cout <<"Daftar Nilai Matematika" << endl << endl;
    for(y=1; y<x; y++){
        cout << y <<") " << matematika[y].nim <<" "<< matematika[y].nama <<" ";
        if(matematika[y].nilai < avg){
            cout <<" "<< matematika[y].nilai <<" REMIDI" << endl;
        }
        else{
            cout <<" "<< matematika[y].nilai << endl;
        }
        tanggalnya(matematika[y].tgl_lahir);
        cout << endl;
    }

    return 0;
}