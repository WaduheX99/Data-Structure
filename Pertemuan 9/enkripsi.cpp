#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct pesan {
    char huruf;
};

struct pesan rahasia[100];
int top = 1;
int max = 100;

push_inqueue(char x){
    rahasia[top].huruf = x;
    top++;
}


tampildata(){
    cout << endl << endl;
    for(int x = 1; x < top; x++){
        cout << rahasia[x].huruf;
    }
    cout << endl << endl;
}

pop() {
    top--;
}

dequeue(){
    for(int x=2; x<top; x++)
        rahasia[x-1] = rahasia[x];

    top--;
}

int main() {
    char kata[100] = {"1I1L1O1V1E1Y1O1U"};
    int hurufke = 0;
    do {
        // cout << kata[hurufke];
        // hurufke++;
        if(kata[hurufke] == '1'){
            cout << kata[hurufke] << "-Lakukan Push / Inqueue : ";
            hurufke++;
            cout <<  kata[hurufke] << endl;
            push_inqueue(kata[hurufke]); //Menjalankan Proc/func Push/Iqueue
            getch();
        }
        if (kata[hurufke] == '2'){
            cout << kata[hurufke] << "-Lakukan POP : " <<endl;
            getch();
            pop();
        }
        if(kata[hurufke] == '3'){
            cout << kata[hurufke] << "Lakukan Dequeue" << endl;
            getch();
            dequeue();
        }      
        
        hurufke++;
        //getch();
    }
    while (hurufke < strlen(kata));

    tampildata();
    return 0;
}