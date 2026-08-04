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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsserialize(root,res);
        return join(res,",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> val= split(data, ',');
        int i=0;
        return dfsdeserialize(val, i);
    }

    private:
        void dfsserialize(TreeNode* root, vector<string> & res){
            if(!root){
                res.push_back("N");
                return;
            }

            res.push_back(to_string(root->val));
            dfsserialize(root->left,res);
            dfsserialize(root->right,res);
        }

        TreeNode* dfsdeserialize(vector<string> val, int &i){
            if(val[i]=="N"){
                i++;
                return nullptr;
            }

            TreeNode* node = new TreeNode(stoi(val[i]));
            i++;
            node->left=dfsdeserialize(val,i);
            node->right=dfsdeserialize(val,i);
            return node;
        }

        vector<string> split(const string &s, char delim){
            vector<string> elems;
            stringstream ss(s);
            string item;
            while(getline(ss, item, delim)){
                elems.push_back(item);
            }
            return elems;
        }

        string join(const vector<string> &v, const string &delim){
            ostringstream s;
            for(const auto &i : v){
                if(&i != &v[0])
                    s << delim;
                s<<i;
            }    
            return s.str();
        }
      

};
