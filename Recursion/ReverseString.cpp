#include<iostream>
#include<string>
using namespace std;

void swap(char &first, char&second){
    char temp = first;
    first = second;
    second = temp;
}

void reverseStringSinglePointer(string &str,int start) {
    int temp = str.length() - start; //to store end point
    if(start >= temp){
        return;
    }  

    swap(str[start], str[temp-1]);
    reverseStringSinglePointer(str,start+1);
}
void reverseString(string &str, int start, int end){
    if(start >= end){
        return;
    }
    swap(str[start], str[end]);
    reverseString(str,start+1, end-1);
    return;
}

int main(){
    string str = "AtulTiwari";

    //reverseString(str, 0, str.length()-1);
    reverseStringSinglePointer(str,0);
    cout << str << endl;
}