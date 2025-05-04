// C++ program to print all subsets
// of a given Set or Array
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void subsetRecur(int i, vector<int>& arr, 
       vector<vector<int>>& res, vector<int>& subset) {
    
    // add subset at end of array
    if (i == arr.size()) {
        res.push_back(subset);
        return;
    }
    
    // include the current value and 
    // recursively find all subsets
    subset.push_back(arr[i]);
    subsetRecur(i+1, arr, res, subset);
    
    // exclude the current value and 
    // recursively find all subsets.
    subset.pop_back();
    subsetRecur(i+1, arr, res, subset);
}

vector<vector<int> > subsets(vector<int>& arr) {
    
    //sort(arr.begin(),arr.end());
    vector<int> subset;
    vector<vector<int>> res;
    subsetRecur(0, arr, res, subset);
    //sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> arr = { 1, 2, 3 };
    vector<vector<int> > res = subsets(arr);
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}


// subsetRecur(0, [1,2,3], res, [])  
//     ├── Bind 1 → subset = [1]  
//     │    ├── Bind 2 → subset = [1,2]  
//     │    │    ├── Bind 3 → subset = [1,2,3] → Push to res  
//     │    │    ├── Unbind 3 → subset = [1,2]  
//     │    │    ├── Exclude 3 → subset = [1,2] → Push to res  
//     │    │    ├── Unbind 2 → subset = [1]  
//     │    │    ├── Exclude 2 → subset = [1]  
//     │    │    │    ├── Bind 3 → subset = [1,3] → Push to res  
//     │    │    │    ├── Unbind 3 → subset = [1]  
//     │    │    │    ├── Exclude 3 → subset = [1] → Push to res  
//     │    │    ├── Unbind 1 → subset = []  
//     │    │    ├── Exclude 1 → subset = []  
//     │    │    │    ├── Bind 2 → subset = [2]  
//     │    │    │    │    ├── Bind 3 → subset = [2,3] → Push to res  
//     │    │    │    │    ├── Unbind 3 → subset = [2]  
//     │    │    │    │    ├── Exclude 3 → subset = [2] → Push to res  
//     │    │    │    ├── Unbind 2 → subset = []  
//     │    │    │    ├── Exclude 2 → subset = []  
//     │    │    │    │    ├── Bind 3 → subset = [3] → Push to res  
//     │    │    │    │    ├── Unbind 3 → subset = []  
//     │    │    │    │    ├── Exclude 3 → subset = [] → Push to res  

// Final subsets stored in `res`:
// []
// [1]
// [1,2]
// [1,2,3]
// [1,3]
// [2]
// [2,3]
// [3]