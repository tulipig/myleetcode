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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0) return 0;
        sort(envelopes.begin(),envelopes.end(),cmp);
        for(auto x:envelopes){
            cout<<"{";
            for(auto y:x)
                cout<<y<<",";
            cout<<"},";
        }
        cout<<endl;

        std::vector<int> nums;
        for(int i=0;i<envelopes.size();++i){
            nums.push_back(envelopes[i][1]);
        }

        return lengthOfLIS(nums);
    }

    //{{5,4},{6,4},{6,7},{2,3},{2,4}}
    //reurn {{2,4},{2,3},{5,4},{6,7},{6,4}}
    static bool cmp(vector<int> left,vector<int> right) {
        if(left[0]==right[0]) {return left[1]>right[1];}
        return left[0] < right[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        const int sz=nums.size();
        vector<int> dp(sz,1);
        int ans=1;

        for(int i=0;i<sz;++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                } 
            }
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }

};

int main(int argc, char const *argv[])
{//[[4,5],[4,6],[6,7],[2,3],[1,1]]
    vector<vector<int>> envelopes={{4,5},{4,6},{6,7},{2,3},{1,1}};

    Solution sol;
    cout << sol.maxEnvelopes(envelopes) << endl;
    return 0;
}