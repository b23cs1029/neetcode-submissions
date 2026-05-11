class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]++;
            }
            else{
               return true; 
            }
        }
        return false;
    }
};