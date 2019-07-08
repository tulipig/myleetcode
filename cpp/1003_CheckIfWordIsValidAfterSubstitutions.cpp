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
    bool isValid(string S) {
        if(S.length()<3) return false;
        stack<string> stk;
        int i=0;
        while(i < S.length()-2){
            if(S[i]=='a' && S[i+1]=='b' && S[i+2]=='c'){
                i=i+3;
            }
            else if(S[i]=='a' && S[i+1]=='b' && S[i+2]!='c'){
                stk.push("ab");
                i=i+2;
            }
            else if(S[i]=='a' && S[i+1]!='b'){
                stk.push("a");
                i=i+1;
            }
            else if(S[i]=='b' && S[i+1]=='c'){
                if(stk.empty() || stk.top()!="a") return false;
                stk.pop();
                i=i+2;
            }
            else if(S[i]=='b' && S[i+1]!='c'){
                if(stk.empty() || stk.top()!="a") return false;
                stk.pop();
                stk.push("ab");
                i=i+1;
            }
            else if(S[i]=='c'){
                if(stk.empty() || stk.top()!="ab") return false;
                stk.pop();
                i=i+1;
            }
        }
        
        if(i==S.length()-2){
            if(!stk.empty() && stk.top()=="a" && S[i]=='b' && S[i+1]=='c') return true;
            else if(S[i]=='c' && S[i+1]=='c'){
                while(!stk.empty()){
                    if(stk.top()!="ab") return false;
                    stk.pop();
                }
                return true;
            }
            else return false;
        }
        else if(i==S.length()-1){
            if(!stk.empty() && stk.top()=="ab" && S[i]=='c') return true;
            else return false;
        }
        else if(i==S.length() && stk.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    string s="abababccc";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}