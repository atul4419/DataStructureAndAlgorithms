#include<iostream>
using namespace std;

int sumOfArray(int arr[], int start, int size){
    if(start == size){
        return arr[start];
    }

    return arr[start] +  sumOfArray(arr, start + 1, size);
}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    cout << "Sum " << sumOfArray(arr, 0, size - 1);
}