class Solution {
    vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROW=heights.size();
        int COL = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac (ROW, vector<bool>(COL,false));
        vector<vector<bool>> alt (ROW, vector<bool>(COL,false));

        for(int r=0;r<ROW;r++){
            dfs(r,0,pac,heights);
            dfs(r,COL-1,alt,heights);
        }

        for(int c=0;c<COL;c++){
            dfs(0,c,pac,heights);
            dfs(ROW-1,c,alt,heights);
        }

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(pac[i][j]&&alt[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    void dfs(int r, int c,vector<vector<bool>>& ocean,vector<vector<int>>& heights){
        ocean[r][c]=true;
        for(auto dir: direction){
            int nr=r+dir.first;
            int nc=c+dir.second;
            if(nr>=0 && nc>=0&& nr<heights.size() && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>= heights[r][c] ){
                dfs(nr,nc,ocean,heights);
            }
        }
    }
};
