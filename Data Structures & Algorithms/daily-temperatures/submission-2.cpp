class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int count=1;
            while(temperatures[i]>=temperatures[j]){
                j++;
                if(j>=n){
                    count=0;
                    break;
                }
                count++;
            }
            res.push_back(count);

        }
        res.push_back(0);
        return res;

    }
};
