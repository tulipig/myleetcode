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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> ans;
        if(matrix.size()==0) return ans;
        const int m=matrix.size();
        const int n=matrix[0].size();
        const int sz=m*n;

        std::vector<int> dirc={n-1,m-1,0,1};//right->down->left->up
        int i=-1;//row loop
        int j=-1;//column loop
        while(ans.size()<sz){
            //right
            i++;
            j++;
            while(j<=dirc[0] && ans.size()<sz){
                ans.push_back(matrix[i][j]);
                j++;
            }

            //down
            i++;
            j--;
            while(i<=dirc[1] && ans.size()<sz){
                ans.push_back(matrix[i][j]);
                i++;
            }

            //left
            i--;
            j--;
            while(j>=dirc[2] && ans.size()<sz){
                ans.push_back(matrix[i][j]);
                j--;
            }

            //up
            j++;
            i--;
            while(i>=dirc[3] && ans.size()<sz){
                ans.push_back(matrix[i][j]);
                i--;
            }

            dirc[0]-=1;
            dirc[1]-=1;
            dirc[2]+=1;
            dirc[3]+=1;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid={
                             { 1,   2,  3 },
                             { 4,   5,  6 },
                             { 7,   8,  9 },
                             { 17, 18, 19 },
                             { 27, 28, 29 },
                             };
    Solution sol;
    vector<int> ans =  sol.spiralOrder(grid);
    for(auto item:ans)
        cout<<item<<" ";
    cout<<endl;
    return 0;
}

