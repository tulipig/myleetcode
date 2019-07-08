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
        if(word.length()>board.size()*board[0].size()) return false;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]==word[0]){
                    if(word.length()==1) return true;
                    else if(DFS(board,word,i,j)) return true;
                }
            }
        }
        
        return false;
        
    }
    
    bool DFS(vector<vector<char>>& board, string word, int i, int j){
        int k=1;
        stack<Node*> stk;
        stk.push(new Node(i,j,0));
        while(!stk.empty()){
            Node* node=stk.top();
            i=node->i;
            j=node->j;
            //up
            if(i-1>=0 && 0==(node->d&0x1) && k<word.length() && board[i-1][j]==word[k]){
                Node* next = new Node(i-1,j,0x2);
                stk.push(next);
                node->d |= 0x1;
                k++;
            }
            //down
            else if(i+1<board.size() && 0==(node->d&0x2) && k<word.length() && board[i+1][j]==word[k]){
                Node* next = new Node(i+1,j,0x1);
                stk.push(next);
                node->d |= 0x2;
                k++;
            }
            //right
            else if(j+1<board[0].size() && 0==(node->d&0x4) && k<word.length() && board[i][j+1]==word[k]){
                Node* next = new Node(i,j+1,0x8);
                stk.push(next);
                node->d |= 0x4;
                k++;
            }
            //left
            else if(j-1>=0 && 0==(node->d&0x8) && k<word.length() && board[i][j-1]==word[k]){
                Node* next = new Node(i,j-1,0x4);
                stk.push(next);
                node->d |= 0x8;
                k++;
            }
            else{
                stk.pop();
                delete node;
                k--;
            }
            
            if(stk.size()==word.length()) return true;

        }
        
        return false;
        
    }
    
    struct Node{
        Node(int x,int y,int d):i(x),j(y),d(d){}
        int i;
        int j;
        int d;//direction
    };
};


int main(int argc, char const *argv[])
{
    vector<vector<char>> board ={{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}};
    string word="aaaa aaaa aaaa a";
    Solution sol;
    int ans=0;
    cout << sol.exist(board,word) << endl;
    return 0;
}

