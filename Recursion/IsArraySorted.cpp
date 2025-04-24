#include<iostream>
using namespace std;

// bool isArraySorted(int arr[], int start, int end){

//     if(start == end){
//         return true;
//     }

//     if(arr[start] > arr[start + 1]){
//         return false;
//     }

//     return isArraySorted(arr,start+1,end);
// }

bool isArraySorted(int arr[], int size){
    if(size==0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    return isArraySorted(arr+1,size-1);
}

//solve below program using DP
// bool arraySortedOrNot(vector<int>& arr) {
//     // code here
//     if(arr.size()==0 || arr.size() == 1){
//     return true;
// }
// if(arr[0] > arr[1]){
//     return false;
// }
// std::vector<int> subArray(arr.begin() + 1, arr.end());
// return arraySortedOrNot(subArray);
// }

// bool arraySortedOrNot(const vector<int> &arr)
// {
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if (arr[i] < arr[i - 1])
//             return false;
//     }

//     return true;
// }
int main(){
    int arr[] = {20, 21, 45, 88, 88, 90};
    int size = sizeof(arr)/sizeof(int);

    cout << isArraySorted(arr,size);
}