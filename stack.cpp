#include <iostream>

using namespace std;

struct STACK{
    int data[10];
    int top;
};

STACK tumpuk;

void push(int input){
    tumpuk.top++;
    tumpuk.data[tumpuk.top] = input;
}

void pop(){
    cout << "Data yang di pop yaitu : " << tumpuk.data[tumpuk.top] << endl;
    tumpuk.top--;
}

void setawal(){
    tumpuk.top = -1;
}

bool isEmpty(){
    if(tumpuk.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

bool isFull(){
    if(tumpuk.top == 9){
        return 1;
    }
    else{
        return 0;
    }
}

void print(){
    int i;
    cout << "Data : " << endl;
    for(i = 0; i <= tumpuk.top; i++){
        cout << tumpuk.data[i] << " ";
    }
}

int main(){
    int pilih, input;
    setawal();
    do{
        cout <<"1) Push data" << endl;
        cout <<"2) Pop data" << endl;
        cout <<"3) Print data" << endl;
        cout <<"4) Clear data" << endl;
        cout <<"5) Exit" << endl;
        cout <<"Masukan pilihan : ";
        cin >> pilih;
        switch(pilih){
            case 1 :
            {
                if(isFull() == 1){
                    cout <<"Tumpukkan Penuh";
                    cout << endl;
                }
                else{
                    cout <<"Data yang di push :";
                    cin >> input;
                    push(input);
                }
                break;
            }
            case 2 :
            {
                if(isEmpty() == 1){
                    cout <<"Tumpukkan Kosong";
                    cout << endl;
                }
                else{
                    pop();
                }
                break;
            }
            case 3 :
            {
                if(isEmpty() == 1){
                    cout <<"Tumpukkan Kosong";
                    cout << endl;
                }
                else{
                    print();
                    cout << endl;
                }
                break;
            }
            case 4 :
            {
                setawal();
                break;
            }
            case 5 :
            {
                cout <<"Keluar sistem" << endl;
                break;
            }
            default :
            {
                cout <<"Opsi yang anda masukkan invalid" << endl;
            }
        }
    }
    while(pilih != 5);
    return 0;
}