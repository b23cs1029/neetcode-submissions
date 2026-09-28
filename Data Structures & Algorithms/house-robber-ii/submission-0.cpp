class Solution {
public:
    vector<vector<int>> cache;
    int rob(vector<int>& nums) {
        cache.resize(nums.size(),vector<int>(2,-1));
        if(nums.size()==1) return nums[0];
        return max(dfs(nums, 1, 0), dfs(nums, 0, 1));
    }
    int dfs(vector<int>& nums, int flag, int i){
        if(i>=nums.size() || (flag==1 && i == nums.size()-1)){
            return 0;
        }
        if(cache[i][flag]!=-1) return cache[i][flag];
        return cache[i][flag]=max(dfs(nums, flag , i+1), nums[i]+dfs(nums, flag || i==0, i+2));
    }
};