#include<iostream>
#include<vector>
using namespace std;

vector<string> DIGITS = {"Zero", "One","Two", "Three","Four","Five","Six", "Seven",
"Eight", "Nine"};

void SayDigits(int num){
    if(num == 0){return;} 
    int lastdigit = num % 10;
    num = num/10;
    SayDigits(num);
    cout << DIGITS[lastdigit] << " ";
}

int main(){
    int inp{0};
    cin >> inp;
    SayDigits(inp);
}

