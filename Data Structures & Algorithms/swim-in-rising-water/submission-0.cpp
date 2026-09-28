class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int maxh;
        int minh;
        int n=grid.size();
        vector<vector<bool>> visit (n, vector<bool> (n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                minh=min(minh, grid[i][j]);
                maxh=max(maxh, grid[i][j]);
            }
        }
        int l=minh;
        int r=maxh;

        while(l<r){
            int m=(l+r)/2;
            if(dfs(grid,visit,0,0,m)){ //
                r=m;
            }
            else{
                l=m+1;
            }
            for(int row=0;row<n;row++){
                fill(visit[row].begin(),visit[row].end(), false);
            }
        }
        // for(int t=minh;t<maxh;t++){
        //     if(dfs(grid,visit,0,0,t)){
        //         return t;
        //         }
        //     for(int r=0;r<n;r++){
        //         fill(visit[r].begin(),visit[r].end(), false);
        //     }
        // }
        return r;

    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit,int r, int c, int t){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || visit[r][c] || grid[r][c] > t){
            return false;
        }
        if(r==grid.size()-1 && c==grid[0].size()-1){
            return true;
        }
        visit[r][c]=true;

        return dfs(grid,visit,r-1,c,t)||
                dfs(grid,visit,r+1,c,t)||
                dfs(grid,visit,r,c-1,t)||
                dfs(grid,visit,r,c+1,t);
    }
};
