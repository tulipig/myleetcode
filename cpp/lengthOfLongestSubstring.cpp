#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int ans = 0;
        int begin = 0;
        string laststr(s,0,1);
        for(int idx=1;idx<s.length();++idx){
            laststr = isAppendCharToString(laststr,s[idx]);            
            if(laststr.length()>ans) ans=laststr.length(); 
            cout<<"output idx="<<idx<<"; laststr="<<laststr<<"; ans="<<ans<<endl;      
        }
        
        return ans;
    }
    
    string isAppendCharToString(string s, char ch){
        string ans(1,ch);
        for(int idx=s.length()-1;idx>=0;--idx){
            if(s[idx]!=ch) ans.append(1,s[idx]);
            else break;
        }
        
        string ret(ans.rbegin(),ans.rend());
        return ret;
    }
};

int main()
{
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("abcabcbb")<<endl;

    return 0;
}