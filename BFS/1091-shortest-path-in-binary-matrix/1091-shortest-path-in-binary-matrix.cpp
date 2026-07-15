// We use BFS because every move costs 1.
// BFS guarantees that the first time we reach the bottom-right cell,
// it is with the minimum possible path length.
//
// Start BFS from the source cell (0,0).
// At every step, try moving in all 8 directions.
// If a neighbouring cell is inside the grid, unvisited and not blocked,
// push it into the queue and update its distance.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        dist[0][0] = 1;
        q.push({0,0});

        vector<pair<int,int>> dir{
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},           {0,1},
            {1,-1},  {1,0},   {1,1}
        };

        while(!q.empty()){

            auto [i,j] = q.front();
            q.pop();

            if(i == n-1 && j == n-1) return dist[i][j];

            for(auto d : dir){

                int I = i + d.first;
                int J = j + d.second;

                // dist = -1 also acts as the visited array.
                // Any visited cell will already have its shortest distance.
                if(I >= 0 && J >= 0 && I < n && J < n &&
                   grid[I][J] == 0 && dist[I][J] == -1){

                    dist[I][J] = dist[i][j] + 1;
                    q.push({I,J});
                }
            }
        }

        return -1;
    }
};