// using multisouce bfs to find shortest path
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int time=0; int fruits=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fruits++;
                }
            }
        }
        if(fruits==0) return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            int N=q.size();
            while(N--){          // make sure to not use the same 'n' cuz we are using it as size of 
                                 // grid inside the same loop
                auto it=q.front();
                q.pop();

                int i=it.first;
                int j=it.second;

                for(auto d:dir){
                    int i_new=d.first+i;
                    int j_new=d.second+j;

                    if(i_new>=0 && j_new>=0 && i_new<n && j_new<m && visited[i_new][j_new]==0 && grid[i_new][j_new]==1){
                        grid[i_new][j_new]=2;     // make sure you're using the same i_new,j_new coords inside 
                                                  // this if statements, its easy to miss out, and difficult //
                                                  // to track
                        fruits--;
                        visited[i_new][j_new]=1;
                        q.push({i_new,j_new});
                    }
                }
            }
            time++;
        }
        return fruits==0 ? time-1 : -1;
    }
};