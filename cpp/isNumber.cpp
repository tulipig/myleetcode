#include <string>  
#include <vector>
#include <iostream>  
#include <unordered_map>  
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std; 


class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        int i=0;
        int len=s.length();
        
        //leading ' '
        int backPlaceNum=0;
        while(s[i]==' ') {backPlaceNum++; i++;}
        if(i>=len) return false;

        
        bool first=true;
        bool hasdot=false;
        bool hasNum=false;
        while(i<len){
            if((s[i]>='0' && s[i]<='9')) hasNum=true;
            
            //+ -
            if(s[i]!='.' && s[i]!=' ' && s[i]!='+' && s[i]!='-' && s[i]!='e' 
                && (s[i]<'0' || s[i]>'9')){
                return false;
            }

            if(hasdot && s[i]=='.') return false;
            
            if(!hasdot && !first && s[i]=='.' && i==len-1 && hasNum) return true;
            
            if (first && !(s[i]=='+' || s[i]=='-' || s[i]=='.' || (s[i]<='9' && s[i]>='0'))) return false;
            //else first=false;
            
            //finish ' '
            if(s[i]==' '){
                i++;
                while(i<len){
                    if(s[i]!=' ') return false;
                    i++;
                }
                return hasNum ? true : false;
            }
            else if(!hasdot && s[i]=='.'){
                if(i+1==len) return false;
                hasdot=true;
            }
            else if(s[i]=='e'){
                int tmp=i+1;
                if(tmp==len) return false;
                if(!(s[tmp]=='+' || s[tmp]=='-' || (s[tmp]<='9' && s[tmp]>='0'))) return false;
                else tmp++;
                while(tmp<len){
                    if(s[tmp]==' '){
                        int k=tmp+1;
                        while(k<len){
                            if(s[k]!=' ') return false;
                            k++;
                        }
                        if(!hasNum) return false;
                        return hasNum ? true : false;
                    }
                    else if(s[tmp]<'0'||s[tmp]>'9') return false;
                    tmp++;
                }
                return hasNum ? true : false;
            }
            else if(i>backPlaceNum && (s[i-1]<'0' || s[i-1]>'9') && (s[i]<'0' || s[i]>'9')) return false;
            else if(!first && (s[i]<'0' || s[i]>'9')) return false;
            
            first=false;
            i++;
        }

        return hasNum ? true : false;
    }
};


int main(int argc, char const *argv[])
{
    string s="-1.";

    Solution sol;
    cout << sol.isNumber(s) << endl;
    return 0;
}