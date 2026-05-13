class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> sortedv(mp.begin(),mp.end());
        sort(sortedv.begin(), sortedv.end(), 
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        int m=sortedv.size();
        vector<int> res;
        for(int i=m-k;i<m;i++){
            res.push_back(sortedv[i].first);
        }
        return res;
    }
};
