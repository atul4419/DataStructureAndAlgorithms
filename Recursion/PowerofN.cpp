#include<iostream>
#include <cstdint>
using namespace std;

int powerfunc( int64_t base, int64_t pow){
if(pow == 0) return 1; //BC
cout << base << "  " << pow << endl;
return base * powerfunc(base, pow-1);
}

int main(){
    int base{0},pow{0};

    cin >> base >> pow;

    cout << powerfunc(base, pow) << endl;
    return 0;
}