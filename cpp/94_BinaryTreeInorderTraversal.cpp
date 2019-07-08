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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(!root) return vec;
        
        stack<TreeNode*> stk;
        TreeNode* pNode = root;
        TreeNode* top = NULL;
        while(!stk.empty() || pNode){

            while(pNode){
                stk.push(pNode);
                pNode = pNode->left;
            }

            top = stk.top();
            vec.push_back(top->val);
            stk.pop();

            pNode = top->right;
        }
        
        return vec;
    }
};


// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> vec;     
//         preorder(root, vec);
//         return vec;
//     }    

//     void preorder(TreeNode* root, vector<int>& v){
//         if(!root) return;
//         preorder(root->left,v);
//         v.push_back(root->val);
//         preorder(root->right,v);
//     }
// };

int main(){
    return 0;
}