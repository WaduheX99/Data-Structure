#include <iostream>

using namespace std;

int big(int a, int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }

}
int main(){
    int upin, ipin, fizi, mail, ros;
    
    cout << "Masukkan rambutan yang telah dipetik oleh Upin : ";
    cin >> upin;
    cout << "Masukkan rambutan yang telah dipetik oleh Ipin : ";
    cin >> ipin;
    cout << "Masukkan rambutan yang telah dipetik oleh Fizi : ";
    cin >> fizi;
    cout << "Masukkan rambutan yang telah dipetik oleh Maul : ";
    cin >> mail;

    ros = big(big (upin, ipin), big(fizi, mail));

    cout << "Jadi, rambutan yang diterima Kak Ros sebanyak : " << ros;

    return 0;
}