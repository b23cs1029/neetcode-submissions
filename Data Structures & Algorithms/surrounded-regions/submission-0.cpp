class Solution {
    vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int ROW= board.size();
        int COL = board[0].size();
        vector<vector<bool>> grid(ROW, vector<bool>(COL,false));

        for(int r=0;r<ROW;r++){
            if(board[r][0]!='X')
                dfs(r,0,board,grid);
            
            if(board[r][COL-1]!='X')
                dfs(r,COL-1,board,grid);

        }
        for(int c=0;c<COL;c++){
            if(board[0][c]!='X')
                dfs(0,c,board,grid);
            if(board[ROW-1][c]!='X')
                dfs(ROW-1,c,board,grid);
        }

        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                if(!grid[r][c]){
                    board[r][c]='X';
                }
            }
        }
    }

    void dfs(int r,int c, vector<vector<char>>& board, vector<vector<bool>>& grid){

        grid[r][c]=true;
        for(auto dir : direction){
            int nr=r+dir.first;
            int nc=c+dir.second;
            if(nr>=0 && nc>=0&& nr<board.size() && nc<board[0].size()&&!grid[nr][nc] && board[nr][nc]!='X'){
                dfs(nr,nc,board,grid);
            }
        }
    }
};
