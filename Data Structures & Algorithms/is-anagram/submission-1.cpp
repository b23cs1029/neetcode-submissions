class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(char c : s){
            mp1[c]++;
        }
        for(char c : t){
            mp2[c]++;
            
        }
        n=mp1.size();
        m=mp2.size();
        if(n!=m) return false;
        for(char c : s){
            if(mp1[c]!=mp2[c]){
                return false;
            }
        }
        return true;

    }
};
