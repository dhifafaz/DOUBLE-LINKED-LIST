#include  <iostream>
using namespace std;

int main(){
double panjang,sisa;
// double jarak=0, hitung;

cin >> panjang;
sisa=panjang;
for (int i=0; i<11; i++)
{
    sisa/=2;


}

cout << sisa<< endl;
return 0;
}