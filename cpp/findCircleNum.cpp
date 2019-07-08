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

class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size()==0) return 0;
        int ans = M.size();
        vector<unordered_set<int>> arr(M.size());
        for(int i=0;i<M.size();++i){
            for(int j=i;j<M.size();++j){
                if(M[i][j]==1){
                    arr[i].insert(j);
                    arr[j].insert(i);
                }    
            }
        }

        // for(int i=0;i<arr.size();++i){
        //     cout<<i<<" === ";
        //     for(unordered_set<int>::iterator it=arr[i].begin(); it!=arr[i].end(); ++it){
        //         cout<<*it<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl<<endl;

        for(int i=0;i<arr.size();++i){
            unordered_set<int>& circle = arr[i];
            bool found=false;
            int mergelevel=INT_MAX;
            for(unordered_set<int>::iterator it=circle.begin(); it!=circle.end(); ++it){
                if(*it>i){
                    mergelevel = min(mergelevel, *it);
                    found = true;
                }
            }
            if(found){
                merge(arr[mergelevel], circle);
                ans--;
                //circle.clear();
            } 
        }

        // int ans=0;
        // for(int i=0;i<arr.size();++i){
        //     if(!arr[i].empty()) ans++;
        //     cout<<i<<" === ";
        //     for(unordered_set<int>::iterator it=arr[i].begin(); it!=arr[i].end(); ++it){
        //         cout<<*it<<" ";
        //     }
        //     cout<<endl;
        // }

        return ans;
        
    }

    //merge b to a
    void merge(unordered_set<int>& a,const unordered_set<int>& b){
        for(auto item:b)
            a.insert(item);
        return;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size()==0) return 0;
        const int m = M.size();
        const int n = M[0].size();
        int ans = 0;
        std::vector<vector<int>> av(m,vector<int>(n));

        for(int i=0;i<m;++i){
            for(int j=i;j<n;++j){//只需要在对角线的一侧DFS
                if(M[i][j]==1 && av[i][j]==0){
                    av[i][j] = 1;
                    DFS(i,j,M,av);
                    ++ans;
                }
            }
        }

        return ans;
    }

    void DFS(int row,int cloumn,vector<vector<int>>& grid, vector<vector<int>>& av){
        const int m = grid.size();
        const int n = grid[0].size();
        stack<pair<int,int>> stk;
        stk.push(make_pair(row,cloumn));
        int i=0;
        int j=0;
        while(!stk.empty())
        {
            //direction: up,left,right,down
            //up
            pair<int,int> pr = stk.top();
            i = pr.first;
            j = pr.second;
            bool bPush = false;
            //up
            for(int k=i;k>0;k--){
                if(j<k) break; //只需要在对角线的一侧DFS
                if(av[k-1][j]){
                    av[k-1][j]=1;
                    break;  
                } 
                if(grid[k-1][j]==1 && !av[k-1][j]){
                    stk.push(make_pair(k-1,j));
                    av[k-1][j] = 1;
                    bPush = true;
                }
            }
            if(bPush) continue;

            //left
            for(int k=j;k>0;k--){
                if(k<i) break;
                if(av[i][k-1]){
                    av[i][k-1]=1;
                    break;  
                } 
                if(grid[i][k-1]==1 && !av[i][k-1]){
                    stk.push(make_pair(i,k-1));
                    av[i][k-1] = 1;
                    bPush = true;
                }
            }
            if(bPush) continue;

            //right
            for(int k=j;k<n-1;k++){
                if(k<i) break;
                if(av[i][k+1]){
                    av[i][k+1]=1;
                    break;  
                } 
                if(grid[i][k+1]==1 && !av[i][k+1]){
                    stk.push(make_pair(i,k+1));
                    av[i][k+1] = 1;
                    bPush = true;
                }
            }
            if(bPush) continue;

            //down
            for(int k=i;k<m-1;k++){
                if(j<k) break;
                if(av[k+1][j]){
                    av[k+1][j]=1;
                    break;  
                } 
                if(grid[k+1][j]==1 && !av[k+1][j]){
                    stk.push(make_pair(k+1,j));
                    av[k+1][j] = 1;
                    bPush = true;
                }
            }
            if(bPush) continue;

            stk.pop();
        }

        return;
    }

};

int main(int argc, char const *argv[])
{//[[4,5],[4,6],[6,7],[2,3],[1,1]]
    //vector<vector<int>> M={{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    //{{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    vector<vector<int>> M={{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                           {0,1,1,0,0,0,0,0,0,0,0,0,0,1,0},
                           {0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},
                           {0,0,0,1,0,1,0,0,1,0,0,0,0,1,0},
                           {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
                           {0,0,0,1,0,1,0,0,0,0,0,1,0,0,0},
                           {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                           {1,0,0,1,0,0,0,0,1,1,1,0,0,1,0},
                           {0,0,0,0,0,0,0,0,1,1,0,1,1,0,0},
                           {0,0,0,0,0,0,0,0,1,0,1,1,0,0,0},
                           {0,0,1,0,1,1,0,0,0,1,1,1,0,0,0},
                           {0,0,0,0,0,0,0,0,0,1,0,0,1,0,1},
                           {0,1,0,1,0,0,0,0,1,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,0,0,0,0,1,0,1}};

    Solution sol;
    cout << sol.findCircleNum(M) << endl;
    return 0;
}