class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0,0,part,s);
        return res;
    }

    void dfs(int j, int i, vector<string>& part, string &s){
        if(i>=s.size()){
            if(i==j){
                res.push_back(part);
            }
            return;
        }

        if(ispali(s,j,i)){
            part.push_back(s.substr(j,i-j+1));
            dfs(i+1,i+1,part,s);
            part.pop_back();
        }

        dfs(j,i+1,part,s);
    }

    bool ispali(string s, int l, int k){
        while(l<k){
            if(s[l]!=s[k]){
                return false;
            }
            l++;
            k--;
        }
        return true;
    }
};
