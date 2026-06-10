class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int res=0;

        // we do this by leftmost and rightmost

        int rightmost;
        int leftmost;
        int height;

        for(int i=0;i<n;i++){
            height=heights[i];

            rightmost=i+1;
            while(rightmost<n && heights[rightmost]>=height){
                rightmost++;
            }

            leftmost=i-1;
            while(leftmost>=0&& heights[leftmost]>=height){
                leftmost--;
            }

            rightmost--;
            leftmost++;
            res=max(res,height*(rightmost-leftmost+1));
        }
        return res;
        

        

        
    }
};
