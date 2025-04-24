#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr){

    for(int second = 1; second < arr.size(); second++){
        int key = arr[second];
        int first = second - 1;

        while(first >= 0 && key < arr[first]){
                arr[first + 1] = arr[first]; //Shift the number toward position
                first--;
            }
            arr[first + 1] = key;
        }
    }

    int main(){
        vector<int> arr = {12,15,7,4,25,63,0,38};
        insertionSort(arr);
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }