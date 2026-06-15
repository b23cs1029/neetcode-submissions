class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int bottom=m-1;

        while(top<=bottom){
            int row=(top+bottom)/2;
            if(target>matrix[row][n-1]){
                top=row+1;
            }
            else if(target<matrix[row][0]){
                bottom=row-1;
            }
            else{
                break;
            }
        }

        int l=0;
        int r=n-1;

        int row=(top+bottom)/2;

        while(l<=r){
            int mid=(l+r)/2;
            if(target>matrix[row][mid]){
                l=mid+1;
            }
            else if(target<matrix[row][mid]){
                r=mid-1;
            }
            else{
                return true;
            }
        }

        
        return false;

    }
};
