#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(!root) return vec;
        
        stack<TreeNode*> stk;
        TreeNode* pNode = root;
        TreeNode* pre = NULL;
        TreeNode* top = NULL;
        while(!stk.empty() || pNode){

            while(pNode){
                stk.push(pNode);
                pNode = pNode->left;
            }

            top = stk.top();
            if(!top->right || pre==top->right){
                vec.push_back(top->val);
                stk.pop();
                pre = top;
            }
            else{
                pNode = top->right;
            }
        }
        
        return vec;
    }
};


// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> vec;     
//         preorder(root, vec);
//         return vec;
//     }    

//     void preorder(TreeNode* root, vector<int>& v){
//         if(!root) return;
//         v.push_back(root->val);
//         preorder(root->left,v);
//         preorder(root->right,v);
//     }
// };

int main(){
    return 0;
}