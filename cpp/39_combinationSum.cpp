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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size()==0) return ans;
        sort(candidates.begin(),candidates.end());
        for(auto num:candidates) mp.insert(num);

        SubCombinationSum(candidates,target,ans);

        // //去重
        unordered_map<string,vector<int>> uniq;
        for(auto v:ans){
            sort(v.begin(),v.end());
            string key;
            for(auto num:v){
                key.append(1,num+'0');
            }
            uniq[key]=v;
        }
        vector<vector<int>> ret;
        for(auto it:uniq){
            ret.push_back(it.second);
        }

        return ret;
    }

    void SubCombinationSum(vector<int>& candidates, int target, vector<vector<int>>& ans){
        if(target<candidates[0]) return;
        if(mp.count(target)){
            std::vector<int> v;
            v.push_back(target);
            ans.push_back(v);
        }

        for(int i=0;i<candidates.size();++i){
            if(target-candidates[i]>=candidates[0]){
                vector<vector<int>> vv;
                // if(hasCalc.count(target-candidates[i])) continue;
                // hasCalc.insert(target - candidates[i]);
                SubCombinationSum(candidates, target - candidates[i], vv );
                for(int k=0;k<vv.size();++k){
                    vv[k].push_back(candidates[i]);
                    ans.push_back(vv[k]);
                }
            }

            else{
                break;
            }
        }
    }

    unordered_set<int> mp;
    //unordered_set<int> hasCalc;
};

int main(int argc, char const *argv[])
{
    vector<int> candidates ={2,3,6,7};
    int target=7;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(candidates,target);
    for(auto v:ans){
        for(auto num:v){
            cout<<num<<",";
        }
        cout<<endl;
    }
    return 0;
}


