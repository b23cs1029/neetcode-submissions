class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(v[i].first+v[j].first==target){
                    if(v[i].second<v[j].second) return {v[i].second,v[j].second};
                    else return {v[j].second,v[i].second};
                }
                else if(v[i].first+v[j].first>target){
                    break;
                }
                else continue;
            }  
        }
        return {0,0};
    }
};
