#include<iostream>
using namespace std;

struct date
{
   int tgl,bln,thn;
};
struct date now;

void tanggalnya(struct date x)
{
    if(x.bln==1)
        cout<<x.tgl<<" Januari "<<x.thn;
    if(x.bln==2)
        cout<<x.tgl<<" Februari "<<x.thn;
    if(x.bln==3)
        cout<<x.tgl<<" Maret "<<x.thn;
    if(x.bln==4)
        cout<<x.tgl<<" April "<<x.thn;
    if(x.bln==5)
        cout<<x.tgl<<" Mei "<<x.thn;
    if(x.bln==6)
        cout<<x.tgl<<" Juni "<<x.thn;
    if(x.bln==7)
        cout<<x.tgl<<" Juli "<<x.thn;
    if(x.bln==8)
        cout<<x.tgl<<" Agustus "<<x.thn;
    if(x.bln==9)
        cout<<x.tgl<<" september "<<x.thn;
    if(x.bln==10)
        cout<<x.tgl<<" Oktober "<<x.thn;
    if(x.bln==11)
        cout<<x.tgl<<" November "<<x.thn;
    if(x.bln==12)
        cout<<x.tgl<<" Desember "<<x.thn;
}

void besok(struct date x)
{
   x.tgl++;
   tanggalnya(x);
}

void kemarin(struct date x)
{

}

int main()
{
    now.tgl=31;
    now.bln=12;
    now.thn=2022;
    cout<<"Sekarang Tanggal : ";tanggalnya(now);
    cout<<endl;
    cout<<"Besok Tanggal    : ";besok(now);
    cout<<endl;
    cout<<"Kemarin Tanggal  : ";kemarin(now);
    return 0;
}
