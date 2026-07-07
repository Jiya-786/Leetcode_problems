// DFS+backtracking (only 1 method)
class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word,int i,int j,int idx){
        if(idx==word.length()) return true;
        int n=board.size();
        int m=board[0].size();
        if(i<0||j<0||i>=n||j>=m||board[i][j]=='$'||board[i][j]!=word[idx]) return false;

        char temp=board[i][j];
        board[i][j]='$';
        if (dfs(board,word,i+1,j,idx+1)) return true;
        if (dfs(board,word,i-1,j,idx+1)) return true;
        if (dfs(board,word,i,j+1,idx+1)) return true;
        if (dfs(board,word,i,j-1,idx+1)) return true;

        board[i][j]=temp;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if (dfs(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};