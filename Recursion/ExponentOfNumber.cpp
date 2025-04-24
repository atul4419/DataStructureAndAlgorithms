#include<iostream>
using namespace std;

int exponent(int base, int exp){
    if(exp == 0){
        return 1;
    }
    return base * exponent(base, exp -1);
}

int main(){
    int base = 4;
    int pow = 4;
    cout << exponent(base,pow) << endl;
}