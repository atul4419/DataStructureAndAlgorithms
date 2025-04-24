#include<iostream>
using namespace std;

class Solution {
    public:
      int chechpalindrome(int num, int rnum){
          if(num == 0){
              return rnum;
          }
          
          return chechpalindrome(num/10, rnum*10 + num%10);
      }
      bool isPalindrome(int n) {
          // Code here.
          if(n == chechpalindrome(n,0) ){
                  return true;    
          }
          else {
              return false;
          }
      }
  };

  int main(){
    int num = 1234321;
    Solution sln;
    cout << sln.isPalindrome(num) << endl;
  }