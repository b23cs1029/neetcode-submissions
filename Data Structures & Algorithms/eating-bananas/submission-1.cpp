class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r= *max_element(piles.begin(),piles.end());
        int k;
        int res;
        while(l<=r){
            k=(l+r)/2;
            long long totaltime=0;
            for(int pile : piles){
                totaltime+= ceil(((double)(pile))/k);
            }
            if(totaltime<=h){
                res=k;
                r=k-1;
            }
            else{
                l=k+1;
            }
        }
        return res;
    }
};
