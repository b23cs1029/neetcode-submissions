class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=prices[j]-prices[i];
                res=max(res,diff);
            }
        }
        return res;
    }
};
