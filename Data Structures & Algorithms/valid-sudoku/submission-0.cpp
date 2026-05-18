class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<char,int>mp(10);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(mp[board[i][j]]>0){
                    return false;
                }
                mp[board[i][j]]++;
            }
            mp.clear();
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(mp[board[j][i]]>0){
                    return false;
                }
                mp[board[j][i]]++;
            }
            mp.clear();
        }

        

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){

                for(int k=j;k<j+3;k++){
                    for(int l=i;l<i+3;l++){
                        if(board[l][k]=='.') continue;
                        if(mp[board[l][k]]>0){
                        return false;
                        }
                        mp[board[l][k]]++;
                    }
                }
                mp.clear();
            }
        }
        return true;
    }
};
