#include <string>  
#include <vector>
#include <iostream>  
#include <unordered_map>  
#include <unordered_set> 
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        
        int i=0;
        int j=s.length()-1;
        while(i<j){
            while (i<s.length() && !((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) i++;
            while (j>=0 && !((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9'))) j--;
            if(i<j){
                if(s[i]>='A' && s[i]<='Z') s[i] += ('a'-'A');
                if(s[j]>='A' && s[j]<='Z') s[j] += ('a'-'A');
                if(s[i]!=s[j]) return false;
                i++;
                j--;
            }
            else{
                break;
            }
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string word="A man, a plan, a canal: Panama";
    Solution sol;
    cout<< sol.isPalindrome(word)<<endl;

    return 0;
}