class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        return max(helper(vector<int>(nums.begin()+1, nums.end())),helper(vector<int>(nums.begin(), nums.end()-1)));
    }
        int helper(vector<int> nums){
            int n=nums.size();
            vector<int>dp1(n);
            dp1[0]=nums[0];
            dp1[1]=max(nums[1],nums[0]);
            for(int i=2;i<n;i++){
                dp1[i]=max(dp1[i-1],nums[i]+dp1[i-2]);
            }
            return dp1[n-1];
        }
        
        
    
};