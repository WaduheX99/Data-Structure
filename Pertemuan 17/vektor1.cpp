#include <iostream>
#include <conio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> V;				/*Variabel V - Vector, Untuk Menampung Sebuah Angka*/

int main()
{
	int pilih, choose, x, a;  // x adalah data, sedangkan a adalah posisi
	do
	{
		cout << "1. Menambah Data Didepan" << endl;
		cout << "2. Menambah Data Belakang" << endl;
		cout << "3. Menambah Data DiTengah" << endl;	
		cout << "4. Menghapus Data DiDepan" << endl;	
		cout << "5. Menghapus Data DiBelakang" << endl;	
		cout << "6. Menghapus Data DiTengah" << endl;	
		cout << "7. Menampilkan Data" << endl;
		cout << "8. Sorting Data " << endl;
		cout <<"9. Keluar" << endl;
		
		
		cout<<"Pilihan Anda [1-9] : ";
		cin>>pilih;
		switch (pilih)
        {
        	case 1: system("cls");{
				cout << "Masukkan Data : " << endl;
				cin >> x;
				V.insert(V.begin(), x);
				cout << "Data berhasil masuk" << endl;
				getch();
                break;
            }
            case 2: system("cls");{    
				cout << "Masukkan Data : " << endl;
				cin >> x;
				V.push_back(x);
				cout << "Data berhasil masuk" << endl;
				getch();
                break;
            }
            case 3: system("cls");{
                cout << "Masukkan Data : " << endl;
				cin >> x;
				cout << "=== TIPE INSERT ===" << endl;
				cout << "1. Insert Before" << endl;
				cout << "2. Insert After" << endl; 
				cin >> choose;
				if (choose == 1){
					bool found = false;
					cout << "Masukkan sebelum data : " << endl;
					cin >> a;
					for(int i = 0; i < V.size(); i++){
						if(a == V[i]){
							V.insert(V.begin() + (i), x);
							cout << "Data berhasil masuk" << endl;
							found == true;
						}
					}
					if(found == false){
						cout << "Maaf Data yang dicari tidak ada" << endl;
					}
					getch();
				} 
				if (choose == 2){
					bool found = false;
					cout << "Masukkan setelah data : ";
					cin >> a;
					for(int i = 0; i < V.size(); i++){
						if(a == V[i]){
							V.insert(V.begin() + (i+1), x);
							cout << "Data berhasil masuk" << endl;
							found == true;
						}
					}
					if(found == false){
						cout << "Maaf Data yang dicari tidak ada" << endl;
					}
					getch();
				}
                break;
            }
            case 4: system("cls");{
                V.erase(V.begin());
				cout << "Data berhasil dihapus" << endl;
				getch();
                break;
            }
            case 5: system("cls");{
                V.pop_back();
				cout << "Data berhasil dihapus" << endl;
				getch();
                break;
            }
            case 6: system("cls");{
				bool found = false;
                cout << "Masukkan data yang ingin dihapus : ";
				cin >> a;
				for (int i = 0; i < V.size(); i++){
					if (a == V[i]){
						cout << "Data " << V[x] << " berhasil dihapus" << endl;
						V.erase(V.begin() + i);
						found = true;
					}	
				}
				if(found == false){
					cout << "Maaf data tidak ketemu" << endl;
				}
				getch();
                break;
            }
            case 7: system("cls");{
				for (int i = 0; i < V.size(); i++){
					cout << i+1 << ") " << V[i] << endl;
				}
                break;
            }
			case 8: system("cls");{
				cout << "==== TIPE SORTING ====" << endl;
				cout << "1. Ascending " << endl;
				cout << "2. Descending " << endl;
				cin >> choose;

				if (choose == 1){
					sort(V.begin(), V.end());
					cout << "Data berhasil diurutkan secara ascending" << endl;
					getch();
				}
				if (choose == 2){
					sort(V.begin(), V.end(), greater<int>());
					cout << "Data berhasil diurutkan secara descending" << endl;
					getch();
				}
				break;
			}
            case 9: system("cls");{
                cout<<"Keluar sistem";
                return 0;
                break;
            }
            default : system("cls");{
                cout<<"Maaf, opsi yang Anda masukkan tidak valid!";
				getch();
            }
        }
	}
	while(pilih!=9);
}
