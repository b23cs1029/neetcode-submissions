class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int left=0;
        int res=0;
        int count=0;

        for(int i=0;i<n;i++){
            
            if(mp[s[i]]>0){
                while(s[left]!=s[i]){
                    left++;
                }
                left++;
                for(auto& pair:mp){
                    pair.second=0;
                }
                i=left-1;
                res=max(res,count);
                count=0;
            }
            else{
                mp[s[i]]++;
                count++;
            }
        }
        res=max(res,count);
        return res;
    }
};
