class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        vector<int>res;
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            ans=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    ans*=nums[j];
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
