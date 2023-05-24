#include <iostream>
using namespace std;

int main ()
{
    int jumlah;
    string nama[100];
    int angka[100];
    int max, i;
    string pemenang;

    cout << "Masukkan jumlah Peserta : ";
    cin >> jumlah;

    //proses simpanan input ke dalam array

    for(i=0; i<jumlah; i++){
        cout << "Masukan Nama Peserta ke - " << i+1 << " : ";
        cin >> nama[i];
        cout << "Jumlah rambutan yang dipetik " << nama[i] << " : ";
        cin >> angka[i];
    }

    //proses mencari nilai terbesar

    cout << endl;
    pemenang = nama[0];
    max = angka[0];
    for(i = 0; i < jumlah; i++){
        if(angka[i] > max){
            max = angka[i];
            if(max = angka[i]){
                pemenang = nama[i];
            }
        }
    }
    
    cout << "Jadi pemenangnya adalah " << pemenang << endl;
    cout << "Dengan rambutan terbanyak yaitu : " << max;

    return 0;
}