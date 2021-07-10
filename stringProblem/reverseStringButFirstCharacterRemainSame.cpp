#include<iostream>
#include<string>

using namespace std;

void reverseStringUsingIndex(string &input, int start,int end){
    if(start == end) return;
    else start += 1;
    while(start < end){
        swap(input[start], input[end]);
        start++; end--;
    }
}

void reverseString(string &input){

    int start = 0;
    input.insert(input.end(), ' ');
    for(int i = 0; i < input.length(); i++){
        if(' ' == input[i]){
          reverseStringUsingIndex(input, start, i-1);
          start = i+1;  
        }
    }
    input.pop_back();
}
int main(){
    string str = "I Love Programming";
    string str2= "My Name Is Atul Tiwari";

    reverseString(str);
    cout << str << endl;
    
    reverseString(str2);
    cout << str2 << endl;

}
