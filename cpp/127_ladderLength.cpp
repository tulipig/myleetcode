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

class Solution_2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> mp;

        for(int i=0;i<wordList.size();++i){
            mp.insert(wordList[i]);
        }
        if(!mp.count(endWord)) return false;

        int ans=1;
        int ret=INT_MAX;
        if(mp.count(beginWord)){mp.erase(beginWord);}
        SubLadderLength(beginWord, endWord, mp, ans, ret);
        return (ret==INT_MAX) ? 0 : ret;

    }

    void SubLadderLength(string& beginWord, string& endWord, unordered_set<string>& wordList, int& ans, int& ret) {
        if(wordList.size()==0) return;
        if(ans>=ret) return;
        if(!wordList.count(endWord)) return;
        if(ret==1) return;

        for(auto word:wordList){
            if(isNeigbor(beginWord,word)){
                int cnt=ans;
                cnt++;
                //cout<<"==="<<beginWord<<", "<<word<<", "<<cnt<<", "<<ret<<endl;
                if(word==endWord) {
                    //cout<<"have found: "<<beginWord<<", "<<endWord<<", "<<cnt<<", "<<ret<<endl;
                    ret=min(ret,cnt);
                    return;
                }

                unordered_set<string> words(wordList.begin(),wordList.end());
                words.erase(word);
                if(words.size()>0 && cnt<ret){
                    SubLadderLength(word,endWord,words,cnt,ret);
                }
            }
        }

        return;
    }

    bool isNeigbor(string& a, string& b){
        if(a.length()!=b.length()) return false;
        string key=a+"_"+b;
        if(isMatch.count(key)) return isMatch[key];
        int i=0;
        int diff=0;
        while(i<a.length()){
            if(a[i]!=b[i]) diff++;
            if(diff>1)  {isMatch[key]=false; return false;}
            i++;
        }

        isMatch[key]= (diff==1) ? true: false;
        return diff==1;
    }

    unordered_map<string,bool> isMatch;
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> mp;
        for(int i=0;i<wordList.size();++i){
            for(int j=0;j<wordList.size();++j){
                if(i!=j){
                    if(isNeigbor(wordList[i],wordList[j])){
                        mp[wordList[i]].insert(wordList[j]);
                    }
                }
            }
        }

        if(!mp.count(endWord)) return 0;
        if(!mp.count(beginWord)){
            for(int i=0;i<wordList.size();++i){
                if(isNeigbor(beginWord,wordList[i])){
                    mp[beginWord].insert(wordList[i]);
                }
            }
        }
        if(beginWord==endWord) return 1;

        int ans=1;
        unordered_set<string> arrived;
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;++i){
                string word=q.front();
                q.pop();
                if(mp.count(word)){
                    for(auto s:mp[word]){
                        if(arrived.count(s)) continue;
                        if(s==endWord) return ++ans;
                        q.push(s);
                        arrived.insert(s);
                    }
                }
            }
            ++ans;
        }

        return ans;
    }

    bool isNeigbor(string& a, string& b){
        if(a.length()!=b.length()) return false;
        string key=a+"_"+b;
        if(isMatch.count(key)) return isMatch[key];
        int i=0;
        int diff=0;
        while(i<a.length()){
            if(a[i]!=b[i]) diff++;
            if(diff>1)  {isMatch[key]=false; return false;}
            i++;
        }

        isMatch[key]= (diff==1) ? true: false;
        return diff==1;
    }

    unordered_map<string,bool> isMatch;

};

int main(int argc, char const *argv[])
{
    // vector<string> wordList={"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm",
    // "ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn",
    // "au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li",
    // "ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn",
    // "mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    vector<string> wordList={"hot","cog","dog","tot","hog","hop","pot","dot"};
    string beginWord="hot";
    string endWord="dog";

    Solution sol;
    cout<< sol.ladderLength(beginWord,endWord,wordList)<<endl;

    return 0;
}