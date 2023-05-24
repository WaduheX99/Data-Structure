#include <iostream>

using namespace std;

void tampil(char x[100], int z){
    for(int a=1; a <= z; a++){
        cout << a << x << endl;
    }
}

int hitung(int z, int w){
    int hasil;
    hasil = z+w;
    return hasil;
}

int main(){
    tampil("SEMARANG", 8);
    int hasil=hitung(10,20);
    cout << hasil;
    return 0;
}