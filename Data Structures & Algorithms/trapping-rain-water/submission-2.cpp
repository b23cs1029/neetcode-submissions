class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        int left=0;
        int lmax=height[left];
        int right=n-1;
        int res=0;
        int rmax=height[right];
        while(left<right){
            if(lmax<rmax){
                left++;
                lmax=max(lmax,height[left]);
                res+=lmax-height[left];
            }
            
            else{
                right--;
                rmax=max(rmax,height[right]);
                res+=rmax-height[right];
            }
        }
        return res;
    }
};
