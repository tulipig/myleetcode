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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_1 {
public:
    int maxPath(TreeNode* root, int& ans) {
        if(!root) return 0;

        int sumLeft=max(maxPath(root->left, ans),0);
        int sumRight=max(maxPath(root->right, ans),0);

        ans=max(ans, sumLeft+sumRight+root->val);

        return max(sumLeft,sumRight)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MIN;

        maxPath(root, ans);

        return ans;
    }
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MIN;

        //post order
        TreeNode* curr = root;
        unordered_map<TreeNode*,int> mp;
        stack<TreeNode*> stk;
        TreeNode* pre = NULL;
        while(!stk.empty() || curr){ 
            while(curr){
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();   
            if(!curr->right || pre==curr->right){
                stk.pop();
                pre = curr;
                curr = NULL;

                //handle max sum path
                int sumLeft= mp.count(pre->left) ? max(mp[pre->left],0) : 0;
                int sumRight= mp.count(pre->right) ? max(mp[pre->right],0) : 0;

                //mp存储以pre为跟节点的子树的最大路径和
                mp[pre]=max(sumLeft,sumRight)+pre->val;
                
                ans = max(ans,sumLeft+sumRight+pre->val);
            }
            else{
                curr = curr->right; 
            }               
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* root;
    Solution sol;
    int ans=0;
    cout << sol.maxPathSum(root) << endl;
    return 0;
}

