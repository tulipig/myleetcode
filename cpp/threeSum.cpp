#include <string>  
#include <vector>
#include <iostream>  
#include <unordered_map>  
#include <list>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std; 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=2) return ans;
        
        sort(nums.begin(),nums.end());
        
        int pre=INT_MAX;
        for(int idx=0;idx<nums.size()-2;++idx){
            if(pre==nums[idx]) continue;
            pre = nums[idx];
            // vector<vector<int>> tmp = twoSum(nums,0-nums[idx],idx+1);
            // for(auto item : tmp){
            //     item.push_back(nums[idx]);
            //     ans.push_back(item);
            // }
            
            twoSum(nums,0-nums[idx],idx+1,ans);
        }
        
        return ans;   
    }
    
    //nums should be ordered, find from pos to end
    void twoSum(vector<int>& nums, int target,int pos, vector<vector<int>>& ans) {
        if (nums.size() == 0)  return;

        //sort(nums.begin(), nums.end());

        int start = pos;
        int end = nums.size() - 1;
        int pre = INT_MAX; //去重
        while(start < end)
        {
            if(pre==nums[start]){
                start++;
                continue;
            }
            
            if (nums[start] + nums[end] == target)
            {
                vector<int> vec;
                vec.push_back(nums[start]);
                vec.push_back(nums[end]);
                vec.push_back(-target);
                ans.push_back(vec);
                
                pre = nums[start];
                start++;
                end--;
            }
            else if (nums[start] + nums[end] < target)
            {
                start++;
                continue;
            }
            else
            {
                end--;
                continue;
            } 
        }

        return;
    }
};

int main()
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    auto vv = sol.threeSum(vec);
    for(int idx=0;idx<vv.size();++idx){
        for(int k=0;k<vv[idx].size();++k){
            cout<<vv[idx][k]<<" ";
        }
        cout<<endl;    
    }

    return 0;
}