#include <iostream>

using namespace std;

struct peta {
    int jarak;
};

struct peta sales[7][7] = {0, 7, 0, 5, 0, 0, 0,
                            7, 0, 8, 9, 7, 0, 0,
                            0, 8, 0, 0, 5, 0, 0,
                            5, 9, 0, 0, 15, 6, 0,
                            0, 7, 5, 15, 0, 8, 9,
                            0, 0, 0, 6, 8, 0, 11,
                            0, 0, 0, 0, 9, 11, 0
                            };

string kota[7] = {"Semarang" , "Demak", "Pati", "Kudus", "Salatiga", "Kendal", "Ambarawa"};
int tampung[50];
int top = 0;
int caritampung(int x){    // Menampung data tidak boleh NOL dan tidak boleh double
    int ketemu = 0;
    for(int z = 0; z < top; z++){
        if(x == tampung[z]){
            return 2;
            break;
        }
    }
    return 1;
}

int main() {
    /* for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            cout << "Inputkan jarak dari " << x << " ke " << y << " : ";
            // Kondisi Khusus
            if(x == y){cls

                sales[x][y].jarak = 0;
                cout << sales[x][y].jarak << endl;
            }
            else if(x > y){
                sales[x][y].jarak = sales[y][x].jarak;
                cout << sales[x][y].jarak << endl;
            }
            else {
                cin >> sales[x][y].jarak;
            }
        }
    }
    */

    //Tampilkan Datanya
    for (int x = 0; x < 7; x++){
        for (int y = 0; y < 7; y++){
            cout << "Jarak dari " << kota[x] << " ke Kota : " << kota[y] << " : " << sales[x][y].jarak << " " << endl;
            //Cek dat
            //Jika nilai
            if(sales[x][y].jarak != 0){
                if(caritampung(sales[x][y].jarak) == 1)
                tampung[top] = sales[x][y].jarak;
                top++;
            }
        }
        cout << endl;
    }
    return 0;
}