#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// int binarysearch(vector<int> &arr, int key) {
//     // code here
// int start = 0;
// int end = arr.size() - 1;
// int result = -1;

// while(start <= end){

// int mid = start + (end - start)/2;
//     if(key == arr[mid]){
//         //return mid;
//         //For Input : 3
// 1 1 1 2 2 3 3 3 3 3 3 4 4 4 5 5 5 Your Code's output is:
//         // 8 It's Correct output is: 5 Output Difference:

//         result =  mid; //index
//     }
//     if(key > arr[mid]){
//         start = mid+1;
//     }
//     else {
//         end = mid-1;
//     }
// }
// return result;
// }

// Using recursion

class Solution
{

public:
    int binarysearch(vector<int> &arr, int key)
    {
        return bSearch(arr, key, 0, arr.size());
    }

private:
    // Recursive approach
    int bSearchFix(const vector<int> &arr, int key, int start, int end, int firstOccur)
    {
        if (start > end)
        {
            return firstOccur; // Return the first occurrence found
        }

        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            firstOccur = mid;                                     // Store the current index
            return bSearch(arr, key, start, mid - 1, firstOccur); // Continue searching left
        }
        else if (key > arr[mid])
        {
            return bSearch(arr, key, mid + 1, end, firstOccur);
        }
        else
        {
            return bSearch(arr, key, start, mid - 1, firstOccur);
        }
    }
    int bSearch(vector<int> arr, int key, int start, int end)
    {
        if (start > end)
        {
            return -1;
        }
        int mid = start + (end - start) / 2;
        cout << mid << "  ";
        cout << arr[mid] << "  " << endl;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            return bSearch(arr, key, mid + 1, end);
        }
        else
        {
            return bSearch(arr, key, start, mid - 1);
        }
    }
};
int main()
{
    // int t;
    // cin >> t;
    // while (t--) {
    //     int k;
    //     cin >> k;
    //     vector<int> arr;
    //     string input;
    //     cin.ignore();
    //     getline(cin, input);
    //     stringstream ss(input);
    //     int number;
    //     while (ss >> number) {
    //         arr.push_back(number);
    //     }
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution ob;
    int res = ob.binarysearch(arr, 10);
    cout << res << endl;
    // }
    return 0;
}
