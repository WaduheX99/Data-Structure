#include <iostream>

using namespace std;

struct date {
    int tgl,bln,thn;
};

struct date now;

void tanggalnya(struct date x){
    if(x.bln == 1){
        cout << x.tgl <<" Januari " << x.thn;
    }
    if(x.bln == 2){
        cout << x.tgl <<" Februari " << x.thn;
    }
    if(x.bln == 3){
        cout << x.tgl <<" Maret " << x.thn;
    }
    if(x.bln == 4){
        cout << x.tgl <<" April " << x.thn;
    }
    if(x.bln == 5){
        cout << x.tgl <<" Mei " << x.thn;
    }
    if(x.bln == 6){
        cout << x.tgl <<" Juni " << x.thn;
    }
    if(x.bln == 7){
        cout << x.tgl <<" Juli " << x.thn;
    }
    if(x.bln == 8){
        cout << x.tgl <<" Agustus " << x.thn;
    }
    if(x.bln == 9){
        cout << x.tgl <<" September " << x.thn;
    }
    if(x.bln == 10){
        cout << x.tgl <<" Oktober " << x.thn;
    }
    if(x.bln == 11){
        cout << x.tgl <<" November " << x.thn;
    }
    if(x.bln == 12){
        cout << x.tgl <<" Desember " << x.thn;
    }
}

int akhiran(struct date x){
    if(x.bln == 1 || x.bln == 3 || x.bln == 5 || x.bln == 7 || x.bln == 8 || x.bln == 10 || x.bln == 12 ){
        return 31;
    }
    else{
        if (x. bln == 2 && x.thn % 4 == 0){
            return 29;
        }
        else{
            if(x.bln==2 && (x.thn % 4)!=0){
				return 28;
            }
			else{
				return 30;
            }
        }
    }
}

void besok(struct date x){
    int tglAkhir = akhiran(x);

    if(x.bln == 12 && x.tgl == 31){
        x.tgl = 1;
        x.bln = 1;
        x.thn++;
    }
    else{
        if (x.tgl!= tglAkhir){
            x.tgl++;
        } 
        else {
            x.tgl = 1;
            x.bln++;
        }
    }

    tanggalnya(x);
};

void kemarin (struct date x){
    if(x.tgl == 1){
        if(x.bln == 1, 3, 5, 7, 8, 10, 12){
            if(x.bln == 1){
                x.bln = 12;
                x.thn--;
                x.tgl = 31;
            }
            else if(x.bln == 3){
                if(x.thn%4 == 0){
                    x.tgl = 29;
                }
                else{
                    x.tgl = 28;
                }
                x.bln--;
            }
            else{
                x.tgl = 30;
                x.bln--;
            }
        }
        else if(x.bln == 2, 4, 6, 9, 11){
            x.tgl = 31;
            x.bln--;
        }
        
        else{
            x.bln--;
        }
    }
    else{
        x.tgl--;
    }
    tanggalnya(x);
}

int main(){
    now.tgl = 28;
    now.bln = 02;
    now.thn = 2024;
    cout <<"Sekarang tanggal    : "; tanggalnya(now);
    cout << endl;
    cout <<"Besok tanggal       : "; besok(now);
    cout << endl; 
    cout <<"Kemarin tanggal     : "; kemarin(now);
    cout << endl;
    return 0;
}