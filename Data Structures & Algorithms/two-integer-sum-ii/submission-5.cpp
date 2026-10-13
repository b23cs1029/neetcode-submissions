class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0; int r=n-1;
        while(l<r){
            int currsum= numbers[l]+numbers[r];
            if(currsum>target){
                r--;
            }
            else if(currsum<target){
                l++;
            }
            else{
                return {l+1,r+1};
            }
            
        }
        return {0,0};
    }
};
