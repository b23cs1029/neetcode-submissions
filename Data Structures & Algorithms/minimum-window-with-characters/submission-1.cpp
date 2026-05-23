class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m ||s.empty()||t.empty()) return "";
        string str="";
        string res;
        int rsize=n+1;
        int k=0;
        int count=0;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(char c:t){
            mp1[c]++;
            mp2[c]++;
        }
        for(int i=0;i<=n-m;i++){
            str="";
            k=0; count=0;
            for(int j=i;j<n;j++){
                if(mp2[s[j]]>0){
                    mp2[s[j]]--;
                    k=1;
                    count++;
                }
                if(k==0) break;
                str=str+s[j];
                if(count==m){
                    if(rsize>str.size()){
                    res=str;
                    rsize=res.size();
                    }
                    break;
                }                 
            }
            if(k==1){
                mp2=mp1;
            }
        }
        return res;
    }
};
