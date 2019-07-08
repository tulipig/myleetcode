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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        std::vector<vector<int>> av(m,vector<int>(n));

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1 && av[i][j]==0){
                    av[i][j] = 1;
                    ans = max(ans,DFS(i,j,grid,av));
                }
            }
        }

        return ans;
    }

    int DFS(int row,int cloumn,vector<vector<int>>& grid, vector<vector<int>>& av){
        const int m = grid.size();
        const int n = grid[0].size();
        stack<pair<int,int>> stk;
        stk.push(make_pair(row,cloumn));
        int ans=0;
        int i=0;
        int j=0;
        while(!stk.empty())
        {
            //direction: up,left,right,down
            //up
            pair<int,int> pr = stk.top();
            i = pr.first;
            j = pr.second;

            if(i>0 && grid[i-1][j]==1 && !av[i-1][j]){
                stk.push(make_pair(i-1,j));
                av[i-1][j] = 1;
                continue;
            }

            //left
            if(j>0 && grid[i][j-1]==1 && !av[i][j-1]){
                stk.push(make_pair(i,j-1));
                av[i][j-1] = 1;
                continue;
            }

            //right
            if(j<n-1 && grid[i][j+1]==1 && !av[i][j+1]){
                stk.push(make_pair(i,j+1));
                av[i][j+1] = 1;
                continue;
            }

            //down
            if(i<m-1 && grid[i+1][j]==1 && !av[i+1][j]){
                stk.push(make_pair(i+1,j));
                av[i+1][j] = 1;
                continue;
            }

            stk.pop();
            ans++;
            //cout<<"i="<<i<<", j="<<j<<", ans="<<ans<<endl;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid=
    {{0,0,1,0,0,0,0,1,0,0,0,0,0},
     {0,0,0,0,0,0,0,1,1,1,0,0,0},
     {0,1,1,0,1,0,0,0,0,0,0,0,0},
     {0,1,0,0,1,1,0,0,1,0,1,0,0},
     {0,1,0,0,1,1,0,0,1,1,1,0,0},
     {0,0,0,0,0,0,0,0,0,0,1,0,0},
     {0,0,0,0,0,0,0,1,1,1,0,0,0},
     {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}