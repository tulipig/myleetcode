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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int ans=0;
        vector<int> heights(matrix[0].size());
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            ans = max(ans,largestRectangleArea(heights));
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        int ans=0;
        stack<int> s;
        heights.push_back(0);
        for(int i=0;i<heights.size();++i){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                int cur = s.top();
                s.pop();
                ans = max(ans, heights[cur]*(s.empty()?i:(i-s.top()-1)));
            }

            s.push(i);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> matrix=
                    {{'0','1','1','0','1'},
                        {'1','1','0','1','0'},
                        {'0','1','1','1','0'},
                        {'1','1','1','1','0'},
                        {'1','1','1','1','1'},
                        {'0','0','0','0','0'}};

    Solution sol;
    cout << sol.maximalRectangle(matrix) << endl;
    return 0;
}

