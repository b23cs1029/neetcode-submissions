class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int c=INT_MIN;
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            c=INT_MIN;
            for(int j=i;j<k+i;j++){
                if(c<nums[j]){
                    c=nums[j];
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
