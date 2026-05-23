class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        int count=0;
        int k=0;
        for(char c:s1){
            mp1[c]++;
            mp2[c]++;
        }
        //we slide the wondow of size n by one step until end
        for(int i=0;i<=m-n;i++){
            count=0;
            k=0;
            for(int j=i;j<n+i;j++){
                if(mp2[s2[j]]>0){
                    mp2[s2[j]]--;
                    count++;
                    k=1;
                }
                else{
                    break;
                }
            }
            if(count==n){
                return true;
            }
            if(k==1){
                mp2=mp1;
            }
        }
        
        return false;
    }
};
