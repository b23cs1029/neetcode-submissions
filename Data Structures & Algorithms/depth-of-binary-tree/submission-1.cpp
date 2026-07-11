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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int res=0;
        q.push({root,1});

        while(!q.empty()){
            pair<TreeNode*,int> current = q.front();
            q.pop();
            TreeNode* node= current.first;
            int depth= current.second;

            if(node!=nullptr){
                res=max(res,depth);
                q.push({node->left,depth+1});
                q.push({node->right,depth+1});
            }
        }
        return res;

    }
};
