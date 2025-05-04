#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
      // Function to sort an array using quick sort algorithm.
      void quickSort(vector<int>& arr, int low, int high) {
          // code here
          if(low >= high){
          return;
      }
  
      int pivot = partition(arr,low,high);
      quickSort(arr,low,pivot-1);
      quickSort(arr,pivot+1, high);
          
      }
  
    public:
      // Function that takes last element as pivot, places the pivot element at
      // its correct position in sorted array, and places all smaller elements
      // to left of pivot and all greater elements to right of pivot.
      int partition(vector<int>& arr, int low, int high) {
          
          // code here
      int pivot = arr[low];
      int count{0};
      for(int i = low+1; i <= high; i++){
          if(arr[i] <= pivot){
              count++;
          }
      }
      int newPivotIndex = low + count;
      swap(arr[low],arr[newPivotIndex]);
  
      int startIndx = low;
      int endIdx = high;
  
      while(startIndx < newPivotIndex && endIdx > newPivotIndex){
          
          while(arr[startIndx] <= arr[newPivotIndex]){
              startIndx++;
          }
          while(arr[endIdx] > arr[newPivotIndex]){
              endIdx--;
          }
          if(startIndx < newPivotIndex && endIdx > newPivotIndex) {
              swap(arr[startIndx], arr[endIdx]);
              startIndx++;
              endIdx--;
          }
  
      }
  
      return newPivotIndex;
      }
  };

int main()
{
    vector<int> vArr = {24, 18, 38, 43, 14, 40, 1, 54};
    int n = vArr.size();
    for(int i = 0; i < vArr.size();i++ ){
        cout << vArr[i] << "  ";
    }
    cout << endl;
    Solution s;
    s.quickSort(vArr, 0, n-1);

    for(int i = 0; i < vArr.size();i++ ){
        cout << vArr[i] << "  ";
    }
    cout << endl;
}
