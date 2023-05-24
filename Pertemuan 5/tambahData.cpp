#include <iostream>
#include <conio.h>

using namespace std;

struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

void tambahdata(int x){
    cout <<"Data ke - " << x << endl;
    cout << "Masukkan Jenis Barang  : ";
    cin >> kirim[x].jenis_brg;
    cout << "Masukkan Berat Barang  : ";
    cin >> kirim[x].berat;
    cout << "Masukkan Kota Tujuan   : ";
    cin >> kirim[x].kota;
    cout << endl;
}

void hapusdata(int x){
    cout << "Data yang dihapus adalah : " << endl;
    cout << "Jenis barang   : " << kirim[x-1].jenis_brg << endl;
    cout << "Berat barang   : " << kirim[x-1].berat << endl;
    cout << "Kota tujuan    : " << kirim[x-1].kota << endl;
}

void tampildata(int x){
    cout << "DAFTAR KIRIMAN" << endl;
    for( int i = 1; i < x; i++){
        cout << "Jenis barang   : " << kirim[i].jenis_brg << endl;
        cout << "Berat barang   : " << kirim[i].berat << endl;
        cout << "Kota tujuan    : " << kirim[i].kota << endl << endl;
    }

}

int main(){
    int pilih;
    int datake=1;               //Index awal data yang akan dimasukkan

    do{
        cout <<"1. Tambah Data" << endl;
        cout <<"2. Hapus Data Terakhir" << endl;
        cout <<"3. Tampil Data" << endl;
        cout <<"9. Keluar" << endl;
        cout << endl << endl <<"Pilihan Anda [1-9] : ";
        cin >> pilih;
        if(pilih == 1){
            tambahdata(datake);     // Menambah data baru di posisi DATAKE
            datake++;       //Indek DATAKE bertambah 1
        }
        if(pilih == 2){
            hapusdata(datake);     // Menghapus data x
            datake--;
        }
        if(pilih == 3){
            tampildata(datake);     // Menampilkan data x
        }
    }
    while (pilih!=9);

    return 0;
}