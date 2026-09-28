class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap;
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        minheap.push({grid[0][0],0,0});
        visit.insert({0,0});

        while(!minheap.empty()){
            auto curr= minheap.top();
            minheap.pop();
            int t=curr[0]; int r=curr[1]; int c=curr[2];
            if(r==n-1&& c==n-1){
                return t;
            }
            for(auto dir: directions){
                int neir=r+dir[0]; int neic=c+dir[1];
                if(neir<0 || neic<0 || neir==n || neic==n || visit.count({neir,neic})){
                    continue;
                }
                minheap.push({max(t,grid[neir][neic]),neir,neic});
                visit.insert({neir,neic});
            }
        }
        return n*n;
    }
};
