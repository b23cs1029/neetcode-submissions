class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        int ans=1;
        int total=1;
        int zerocount=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) total*=nums[i];
            else zerocount++;
        }
        if(zerocount>1){
            vector<int>res(n,0);
            return res;
        }
        else if (zerocount==1) {
            vector<int>res(n,0);
            for(int i=0;i<n;i++){
            if(nums[i]==0){
                res[i]=total;
            }
            }
            return res;
        }
        vector<int>res;
            for(int i=0;i<n;i++){
                res.push_back(total/nums[i]);
            }
            
    
        

        return res;
    }
};
