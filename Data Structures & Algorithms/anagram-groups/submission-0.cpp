class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n = strs.size();
       unordered_map<string, vector<string>>mp;
       vector<vector<string>> res;
       string temp;
       for(auto& c:strs){
        temp=c;
        sort(temp.begin(),temp.end());
        mp[temp].push_back(c);
       }
       for( auto& c:mp){
        res.push_back(c.second);
       }
       return res;


    }
};
