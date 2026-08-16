class Solution {
public:
    int ROW;
    int COL;
    vector<vector<bool>>visited;
    bool exist(vector<vector<char>>& board, string word) {
        ROW= board.size();
        COL= board[0].size();
        visited= vector<vector<bool>>(ROW, vector<bool>(COL, false));
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(dfs(board,word,i,j,0))
                    {return true;}
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i==word.size()){
            return true;
        }
        if(r<0||c<0||r>=ROW||c>=COL||board[r][c]!= word[i] ||visited[r][c]){
            return false;
        }


        visited[r][c]=true;
        bool res=dfs(board,word,r-1,c,i+1)||dfs(board,word,r+1,c,i+1)|| dfs(board,word,r,c-1,i+1)|| dfs(board,word,r,c+1,i+1);
        visited[r][c]=false;
        return res;
    }
};
