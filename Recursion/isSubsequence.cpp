
#include<iostream>
using namespace std;

bool isSubsequence(string s, string t) {

        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;  // Move forward in `s` if characters match
            }
            j++;  // Always move forward in `t`
        }
        return i == s.length();  // If we traversed all `s`, it's a subsequence
    }

    int main()
    {
        string s = "abs";
        string t = "ahbgdc";
        cout << isSubsequence(s, t);

        s = "rjufvjafbxnbgriwgokdgqdqewn";
        t = "mjmqqjrmzkvhxlyruonekhhofpzzslupzojfuoztvzmmqvmlhgqxehojfowtrinbatjujaxekbcydldglkbxsqbbnrkhfdnpfbuaktupfftiljwpgglkjqunvithzlzpgikixqeuimmtbiskemplcvljqgvlzvnqxgedxqnznddkiujwhdefziydtquoudzxstpjjitmiimbjfgfjikkjycwgnpdxpeppsturjwkgnifinccvqzwlbmgpdaodzptyrjjkbqmgdrftfbwgimsmjpknuqtijrsnwvtytqqvookinzmkkkrkgwafohflvuedssukjgipgmypakhlckvizmqvycvbxhlljzejcaijqnfgobuhuiahtmxfzoplmmjfxtggwwxliplntkfuxjcnzcqsaagahbbneugiocexcfpszzomumfqpaiydssmihdoewahoswhlnpctjmkyufsvjlrflfiktndubnymenlmpyrhjxfdcq";
        //cout << isSubsequence(s, t);
            return 0;
    }