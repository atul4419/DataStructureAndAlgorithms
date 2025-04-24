#include<iostream>
#include<vector>
using namespace std;

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
// void  selectionSort(int arr[], int start, int end){
//     //needs to optimize using DP
//         if(start > end ){
//             return;
//         }
//         if(arr[0] > arr[start + 1]){
//             swap(arr[0] , arr[start + 1]);
//         }
//         selectionSort(arr, start + 1, end);
//         selectionSort(arr+1, start, end-1);
// }

int minIndex(int arr[], int start, int end){
    cout << start << " " << end -1 << endl;
    int minIndex{start};
    for(int i = start; i < end; i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i; 
        }
    }
    return minIndex;
}

void selectionSort(int arr[], int start, int end){
    if(start == end){
        return;
    }
    int index = minIndex(arr,start, end);
   // cout << index << " ";
    swap(arr[start], arr[index]);
    selectionSort(arr,start+1, end);
}
int main(){
    int arr[8] = {12,15,7,4,25,63,0,38};
    selectionSort(arr,0,8);
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}

