// basically Replace every 'O' that is not connected to an edge 'O' with 'X'.

// Problem with this solution is that using an unordered set is not preferred because unordered set does not process input parameters of the type pair<int,int> Because  The compiler does not know how to hash them. It only processes string etc. And it is also not as fast as using grids. Hence always use a grid for DFS problems and we can also use two different grids one for visited and another for marking which 0 is safe but in this case we can use just one grid in place of both. Because we're always starting DFS from Edge zeros that means any cell we will visit through that path will always be safe hence and safe and visited can be replaced by a single grid For this particular problem. or, we can use no grids at all by temporarily changing the given board grid. That is for any 0 you meet through DFS from the edges replace with with a temporary character like hashtag and then in the end Hashtag characters with 'X' and replace all the hashtags with 0s'

// class Solution {
// public:
    
//     // vector<vector<int>> visited(n,vector<int>(m,0));

//     void dfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>& visited,unordered_set<pair<int,int>>& loc){
//         int n=board.size();
//         int m=board[0].size();
//         if(i<0||j<0||i>=n||j>=m||board[i][j]=='X'||visited[i][j]) return;
//         if(board[i][j]==0){
//             loc.insert({i,j});
//             visited[i][j]=1;

//             dfs(board,i+1,j,visited,loc);
//             dfs(board,i-1,j,visited,loc);
//             dfs(board,i,j+1,visited,loc);
//             dfs(board,i,j-1,visited,loc);
//         }
//     }

//     void solve(vector<vector<char>>& board) {
//         int n=board.size();
//         int m=board[0].size();
//         vector<vector<int>> visited(n,vector<int>(m,0));
//         unordered_set<pair<int,int>> loc;

//         //first col
//         for(int i=0;i<n;i++){
//             if(board[i][0]==0){
//                 dfs(board,i,0,visited,loc);}
//         }
//         //first row
//         for(int i=0;i<m;i++){
//             if(board[0][i]==0){
//                 dfs(board,0,i,visited,loc);}
            
//         }
//         //lat col
//         for(int i=0;i<n;i++){
//             if(board[i][m-1]==0){
//                 dfs(board,i,m-1,visited,loc);}
            
//         }
//         //last row
//         for(int i=0;i<m;i++){
//             if(board[n-1][i]==0){
//                 dfs(board,n-1,i,visited,loc);}
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(loc.find({i,j})==loc.end()) board[i][j]='X';
//             }
//         }
//     }
// };

// in this problem we can use safe and visited as one arrya becuase any cell we will end us visiting by calling dfs on edge 0's will definitely be safe ie no need to replace with X and we will mark safe for every 0 cell we visit through dfs from edge. And when we reach an we immediately return from there so we don't need a visited or safe array fort that. its only for or 0's and we use th same fact in our final line in the main function also

// NOTE ITS NOT '0' ITS 'O'
class Solution {
public:
    
    // vector<vector<int>> visited(n,vector<int>(m,0));

    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>& safe){
        int n=board.size();
        int m=board[0].size();
        if(i<0||j<0||i>=n||j>=m||board[i][j]=='X'||safe[i][j]) return;

        
        safe[i][j]=1;
        if(board[i][j]=='O'){
            dfs(board,i+1,j,safe);
            dfs(board,i-1,j,safe);
            dfs(board,i,j+1,safe);
            dfs(board,i,j-1,safe);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> safe(n,vector<int>(m,0));

        //first col
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,safe);}
        }
        //first row
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i,safe);}
            
        }
        //lat col
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,safe);}
            
        }
        //last row
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                dfs(board,n-1,i,safe);}
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !safe[i][j]) board[i][j]='X';
            }
        }
    }
};