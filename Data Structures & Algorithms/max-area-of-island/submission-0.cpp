class Solution {
    vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    area=max(area,dfs(grid,i,j));
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0 || c<0 || r>=grid.size()|| c>=grid[0].size() || grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        int res=1;
        for(int i=0;i<4;i++){
            res+=dfs(grid, r+direction[i][0], c+direction[i][1]);
        }
        return res;
    }

};
