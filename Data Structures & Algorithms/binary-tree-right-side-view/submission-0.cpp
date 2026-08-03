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
    vector<vector<int>> arr;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            res.push_back(arr[i][(arr[i].size())-1]);
        }
        return res;
    }
    void dfs(TreeNode* root,int depth){
        if(!root) return;
        if(arr.size()==depth){
            arr.push_back(vector<int>());
        }
        arr[depth].push_back(root->val);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
};
