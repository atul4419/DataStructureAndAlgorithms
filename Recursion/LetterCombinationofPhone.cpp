
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <iostream>
#include <vector>
using namespace std;
const vector<string> sMapKeyPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combination(string str, int indx, string subseq, vector<string> &response)
{
    if (indx >= str.length())
    {
        if (subseq.length())
        {
            response.push_back(subseq);
        }
        return;
    }

    int key = str[indx] - '0';
    string value = sMapKeyPad[key];

    for (int i = 0; i < value.length(); i++)
    {
        subseq.push_back(value[i]);
        combination(str, indx + 1, subseq, response);
        subseq.pop_back();
    }
}
vector<string> letterCombination(string str)
{
    vector<string> response;
    string subseq{""};
    combination(str, 0, subseq, response);

    return response;
}

int main()
{

    string input = "23";

    vector<string> response = letterCombination(input);

    for (auto i : response)
    {
        cout << i << " ";
    }
    cout << endl;
}