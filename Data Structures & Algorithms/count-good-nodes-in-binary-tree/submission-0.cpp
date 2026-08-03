/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
    int dfs(TreeNode* root,int maxval){
        if(!root) return 0;
        int res;
        if(maxval<=root->val){
            res=1;
            maxval=root->val;
        }
        else{
            res=0;
        }
        res+=dfs(root->left,maxval);
        res+=dfs(root->right,maxval);
        return res;

    }
};
