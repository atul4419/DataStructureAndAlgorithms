// C++ program to implement
// the above approach
#include <iostream>
using namespace std;
 
void preserveSpace(string &str)
{
    int n = str.length();
 
    // Initialize two pointers as two corners
    int start = 0;
    int end = n - 1;
 
    // Move both pointers toward each other
    while (start < end) {
 
        // If character at start or end is space,
        // ignore it
        if (str[start] == ' ') {
            start++;
            continue;
        }
        else if (str[end] == ' ') {
            end--;
            continue;
        }
 
        // If both are not spaces, do swap
        else {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }
}
 
// Driver code
int main()
{
    string str = "My name is Atul Tiwari";
    preserveSpace(str);
    cout << str;
    return 0;
}