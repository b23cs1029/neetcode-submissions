class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        if(t.size()!=s.size()){
            return false;
        }
        int n=t.size();
        for(int i=0;i<n;i++){
            mp1[t[i]]++;
            mp2[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp1[s[i]] != mp2[s[i]]){
                return false;                
            }
        }
        return true;



    }
};
