#include<iostream>
using namespace std;

int fibonacciUsingIterative(int pos){
    int first{0}, second{1};
    int ans{0};
    for(int i = 0; i < pos; i++){
        ans = first + second;
        first = second;
        second = ans;
    }
    return first;
}

int fibRecursive(int num){
    if(num == 0) return 0;
    if (num == 1) return 1;

    return fibRecursive(num - 1) + fibRecursive(num - 2);
}
int main(){
    int num{0};
    cin >> num;
    cout << fibonacciUsingIterative(num) << endl;
    cout << fibRecursive(num) << endl;
}

