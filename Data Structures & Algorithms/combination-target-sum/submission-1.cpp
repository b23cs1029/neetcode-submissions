class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        dfs(nums,target,cur,0,0);
        return res;
    }
    void dfs(vector<int>& nums, int target, vector<int> &cur, int i, int total){
        if(target==total){
            res.push_back(cur);
            return;
        }
        if(target<total  || i>=nums.size() ){
            return;
        }
        cur.push_back(nums[i]);
        dfs(nums,target,cur,i, nums[i]+total);
        cur.pop_back();
        while(i+1 <nums.size()  &&nums[i]==nums[i+1]){
            i++;
        }
        dfs(nums,target,cur,i+1,total);
    }
};
