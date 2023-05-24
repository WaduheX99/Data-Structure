#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

struct Mahasiswa
{
  char Nim[9];
  char Nama[25];
  char Alamat[4];
  int Umur;
};
main()
{
  Mahasiswa Mhs[5];
  int i;
  for (i=0; i<5; i++)
  {
    cout<<"Nim  : ";
    cin>>Mhs[i].Nim;
    cout<<"Nama  : ";
    cin>>Mhs[i].Nama;
    cout<<"Alamat  : ";
    cin>>Mhs[i].Alamat;
    cout<<"Umur  : ";
    cin>>Mhs[i].Umur;
  }
  for(i=0; i<5; i++)
  {
    cout<<"\n\nNIM  : "<<Mhs[i].Nim;
    cout<<"\nNama  : "<<Mhs[i].Nama;
    cout<<"\nAlamat  : "<<Mhs[i].Alamat;
    cout<<"\nUmur  : "<<Mhs[i].Umur;
  }
  getch();
}