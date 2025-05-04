// Input:  s = “ABC”
// Output: “ABC”, “ACB”, “BAC”, “BCA”, “CAB”, “CBA”

// Input: s = “XY”
// Output: “XY”, “YX”

// Input: s = “AAA”
// Output: “AAA”, “AAA”, “AAA”, “AAA”, “AAA”, “AAA” 

//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void permutationUsingSet(string str, int indx, set<string> &response){
    if(indx >= str.length()){
        response.insert(str);
        return;
    }

    for(int i = indx; i < str.length(); i++){
        swap(str[i],str[indx]);
        permutationUsingSet(str,indx+1, response);
        swap(str[i],str[indx]);
    }
}
    //Here above logic fails use  set rather than vector.
    // s = "AAA";
void permutation(string str, int indx, vector<string> &response){
    if(indx >= str.length()){
        response.push_back(str);
        return;
    }

    for(int i = indx; i < str.length(); i++){
        swap(str[i],str[indx]);
        permutation(str,indx+1, response);
        swap(str[i],str[indx]);
    }
}

// Function to find all unique permutations
vector<string> findPermutation(string &s) {

    // Stores the final answer
    vector<string> ans;

    permutation(s, 0, ans);

    // sort the resultant vector
    sort(ans.begin(), ans.end());

    return ans;
}


// Function to find all unique permutations
set<string> findPermutationUsingSet(string &s) {

    // Stores the final answer
    set<string> ans;

    permutationUsingSet(s, 0, ans);

    // sort the resultant vector
   // sort(ans.begin(), ans.end());

    return ans;
}
int main() {
    string s = "ABC";
    vector<string> vres = findPermutation(s);
    for(auto x: vres) {
        cout << x << " ";
    }

    //Here above logic fails use  set rather than vector.
     s = "AAA";

    set<string> res = findPermutationUsingSet(s);
    for(auto x: res) {
        cout << x << " ";
    }
    return 0;
}