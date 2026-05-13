class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n = strs.size();
       unordered_map<string, vector<string>>mp;
       vector<vector<string>> res;
       string temp;
       
       for(auto& s:strs){
        vector<int>count(26,0);
        for(auto& c: s){
            count[c-'a']++;
        }
        // we generate code of 26 for angram **
        string key =to_string(count[0]);
        for(int i=1;i<26;i++){
            key += ','+ to_string(count[i]);
        }

        mp[key].push_back(s);
       }
       for( auto& c:mp){
        res.push_back(c.second);
       }
       return res;


    }
};
