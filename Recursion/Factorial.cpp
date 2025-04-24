#include<iostream>
using namespace std;

int factorial(int num){
    if(num == 0) return 1;
    return num*factorial(num-1);
}

int main(){
    int input = 0;
    cin >> input ;

    cout << factorial(input) << endl;
    return 0;
}