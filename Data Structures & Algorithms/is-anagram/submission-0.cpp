class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        vector<int> pairs(m,1);
        int found=0;
        for(int i=0;i<n;i++){
            found=0;
            for(int j=0;j<m;j++){
                if(s[i]==t[j]){
                    if(pairs[j]==1){
                        found=1;
                        pairs[j]=0;
                        break;
                    }
                }
            }
            if(found==0){
                return false;
            }
        }
        return true;
    }
};
