#include<iostream>
using namespace std;

void subSequences(string inpstr, int indx, string output){
    if(indx >= inpstr.length()){
        cout << output << endl;
        return;
    }

    output+= inpstr[indx];
    subSequences(inpstr,indx+1, output);
    output.pop_back();
    subSequences(inpstr,indx+1, output);

}

void printSubs(string s)
{
    string curr = ""; 
    subSequences(s,0, curr);
}

// Driver code
int main()
{
    string s = "abxcy";
    printSubs(s); 
    return 0;
}