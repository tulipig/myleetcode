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
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int ans = 0;
        std::vector<vector<int>> area(m,vector<int>(n));//perimeter

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0){
                    area[0][j] = matrix[0][j]-'0';
                }
                else if(j==0){
                    area[i][0] = matrix[i][0]-'0';
                }
                else if(area[i-1][j-1]==0 || matrix[i][j]=='0'){
                    area[i][j] = matrix[i][j]-'0';
                }
                else if(area[i-1][j-1]>0){ //matrix[i][j]=='1'
                    // int last = area[i-1][j-1];
                    // int cnt=1;
                    // for(int id=1;id<=last;++id){
                    //     if(matrix[i][j-id]!='1' || matrix[i-id][j]!='1'){
                    //         break;
                    //     }
                    //     cnt++;
                    // }
              
                    // area[i][j] = cnt;
                    area[i][j] = min(min(area[i-1][j],area[i][j-1]), area[i-1][j-1]) + 1;

                }

                cout<<"i="<<i<<", j="<<j<<", area[i][j]="<<area[i][j]<<endl;
                ans = max(ans, area[i][j]);
            }
        }

        return ans*ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid=
    {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    //{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    Solution sol;
    cout << sol.maximalSquare(grid) << endl;
    return 0;
}