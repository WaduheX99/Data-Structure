#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<vector>

using namespace std;

struct player
{
    string nama;
    int nilai;
};

vector <player> V;
int maksimal = 5;

bool sortData(player a, player b){
    return (a.nilai > b.nilai);
}

void tampil(){
    for (int i = 0; i < V.size(); i++){
        cout << i+1 << ". " << V.at(i).nama << " " << V.at(i).nilai << "\n";
    }
}

int main()
{
    string nmplayer[10] = {"Agus","Indah","Heru","Kiki","Bagus","Yuli","Budi","Carlie","Linda","Putri"};
    int point[10] = {100,50,110,120,80,90,140,95,160,115};
    cout << "Daftar Player dan Nilai" << endl;
    for(int a = 0; a < 10; a++){
        system("cls");
        cout << nmplayer[a] << " " << point[a] << endl;
        /**disini code utk mengatur (menyimpan/menghapus) nama player dan nilainya
        1. Lakukan Penambahan Data Dibelakang
        2. Sorting Data secara DESCENDING
        3. Hapus Data paling belakang, jika data yg ada > maksimal
        4. Tampilkan Data
        **/

        //Memasukkan data di belakang
        if (V.size() <= maksimal){
            player isi = {nmplayer[a], point[a]};
            V.push_back(isi);
        }

        //mengurutkan data
        sort(V.begin(), V.end(), sortData);

        //Menghapus data jika lebih dari maksimal
        if (V.size() > maksimal){
            V.pop_back();
        }
        
        //menampilkan data
        tampil();
        getch();
    }
    return 0;
}