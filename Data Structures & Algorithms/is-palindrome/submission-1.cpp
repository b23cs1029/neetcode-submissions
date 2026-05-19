class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int left=0;
        int right=n-1;
        while(left<right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            
            if((s[left])!=(s[right])){
                if((s[left])!=(s[right] ^32)){
                    return false;
                }
            }
                
            
            left++;
            right--;
        }
        return true;
    }
};
