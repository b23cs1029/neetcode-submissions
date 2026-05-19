class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        //int mid=0;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            left=i+1;right=n-1;
            while(left<right){
                if(nums[left]+nums[i]+nums[right]==0){
                    res.push_back({nums[left],nums[i],nums[right]});
                    // remove duplicate
                    while(left<right&&nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(nums[left]+nums[i]+nums[right]<0){
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};
