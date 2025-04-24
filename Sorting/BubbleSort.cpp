#include<iostream>
#include<vector>
using namespace std;
static int count{0};
void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// void bubbleSort(int arr[], int start, int end){
//     //optimize this code.
//     count++;
//     if(start >= end-1){
//         return;
//     }
//     cout << start <<":" << arr[start]<<" " << start + 1<< ":" << arr[start + 1] << endl;
//     if(arr[start]> arr[start + 1]){
//         swap(arr[start], arr[start + 1]);
//     }
//     bubbleSort(arr,start+1, end);
//     bubbleSort(arr,start, end-1);

// }
void bubbleSort(int arr[], int size){
    if(size == 0){
        return;
    }
    //count++;
    bool clkrecursion{false};

    for(int itr = 0; itr < size-1; itr++){
        count++;
        if(arr[itr] > arr[itr+1]){
            swap(arr[itr], arr[itr+1]);
            clkrecursion = true;
        }
    }
    if(clkrecursion){
        bubbleSort(arr,size-1); 
    }
    else {
        return;
    }
}
int main(){
    int arr[8] = {12,15,7,4,25,63,0,38};
    bubbleSort(arr,8);
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << count << endl;

}

