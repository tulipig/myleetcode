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
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()==0) return false;
        if(board.size()==0) return false;
        vector<vector<bool>> arrived(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]==word[0]){
                    if(word.length()==1) return true;
                    else if(DFS(board,word,arrived,i,j)) return true;
                }
            }
        }
        
        return false;
        
    }
    
    bool DFS(vector<vector<char>>& board, string word, vector<vector<bool>> arrived, int i, int j){
        int k=1;
        stack<Node*> stk;
        stk.push(new Node(i,j));
        arrived[i][j]=true;
        unordered_map<Node*,std::vector<Node*>> mp;
        while(!stk.empty()){
            Node* node=stk.top();
            i=node->i;
            j=node->j;
            //up
            if(i-1>=0 && !arrived[i-1][j] && k<word.length() && board[i-1][j]==word[k]){
                Node* next = new Node(i-1,j);
                stk.push(next);
                arrived[i-1][j]=true;
                k++;
                if(!mp.count(node)){
                    std::vector<Node*> v;
                    v.push_back(next);
                    mp[node]=v;
                }
                else{
                    mp[node].push_back(next);
                }
            }
            //down
            else if(i+1<board.size() && !arrived[i+1][j] && k<word.length() && board[i+1][j]==word[k]){
                Node* next = new Node(i+1,j);
                stk.push(next);
                arrived[i+1][j]=true;
                k++;
                if(!mp.count(node)){
                    std::vector<Node*> v;
                    v.push_back(next);
                    mp[node]=v;
                }
                else{
                    mp[node].push_back(next);
                }
            }
            //right
            else if(j+1<board[0].size() && !arrived[i][j+1] && k<word.length() && board[i][j+1]==word[k]){
                Node* next = new Node(i,j+1);
                stk.push(next);
                arrived[i][j+1]=true;
                k++;
                if(!mp.count(node)){
                    std::vector<Node*> v;
                    v.push_back(next);
                    mp[node]=v;
                }
                else{
                    mp[node].push_back(next);
                }
            }
            //left
            else if(j-1>=0 && !arrived[i][j-1] && k<word.length() && board[i][j-1]==word[k]){
                Node* next = new Node(i,j-1);
                stk.push(next);
                arrived[i][j-1]=true;
                k++;
                if(!mp.count(node)){
                    std::vector<Node*> v;
                    v.push_back(next);
                    mp[node]=v;
                }
                else{
                    mp[node].push_back(next);
                }
            }
            else{
                stk.pop();
                k--;
                if(mp.count(node)){
                    for(int k=0;k<mp[node].size();++k)
                        arrived[mp[node][k]->i][mp[node][k]->j]=false;
                }
            }
            
            if(stk.size()==word.length()) return true;

        }
        
        return false;
        
    }
    
    struct Node{
        Node(int x,int y):i(x),j(y){}
        int i;
        int j;
    };
};


int main(int argc, char const *argv[])
{
    vector<vector<char>> board =
                        {
                          {'A','B','C','E'},
                          {'S','F','E','S'},
                          {'A','D','E','E'}
                        };
    string word="ABCESEEEFS";
    Solution sol;
    int ans=0;
    cout << sol.exist(board,word) << endl;
    return 0;
}

