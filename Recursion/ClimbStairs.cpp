#include<iostream>
using namespace std;

void climbStairs(int num){
    if(num == 0) {
        cout << " Reached " << endl;
        return;
    }
    cout << num << " "; 
    climbStairs(num-1);
    cout << num << endl; 
}

int main(){
    int input;
    cin >> input;
    climbStairs(input);
}