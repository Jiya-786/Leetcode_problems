// We use BFS because every knight move costs 1.
// BFS guarantees that the first time we reach a cell,
// it is with the minimum number of moves.
// So start from (0,0) and keep exploring all 8 possible
// knight moves level by level until we reach the target.

// but it will TLE on LeetCode because the chessboard is infinite 
// and BFS will expand forever in all directions.
class Solution {
public:
    int minKnightMoves(int x, int y) {

        vector<pair<int,int>> dir{
            {2,1},{2,-1},{-2,1},{-2,-1},
            {1,2},{1,-2},{-1,2},{-1,-2}
        };

        queue<pair<int,int>> q;
        set<pair<int,int>> visited;

        q.push({0,0});
        visited.insert({0,0});

        int level = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                auto [i,j] = q.front();
                q.pop();

                if(i==x && j==y) return level;

                for(auto d : dir){
                    int I = i + d.first;
                    int J = j + d.second;

                    if(!visited.count({I,J})){
                        visited.insert({I,J});
                        q.push({I,J});
                    }
                }
            }

            level++;
        }

        return -1;
    }
};

// We use BFS because every knight move costs 1.
// BFS guarantees that the first time we reach a cell,
// it is with the minimum number of moves.
//
// Since the chessboard is infinite, a normal BFS would
// explore infinitely many unnecessary cells.
//
// Observation 1:
// The board is symmetric, so the answer for (x,y) is the
// same as (-x,y), (x,-y) and (-x,-y).
// Hence convert the target to the first quadrant.
//
// Observation 2:
// We still allow coordinates down to -2 because the
// shortest path to points near the axes may temporarily
// move slightly into the negative side.
// A knight's maximum backward jump is 2, so a buffer of
// -2 is sufficient.

class Solution {
public:
    int minKnightMoves(int x, int y) {

        x = abs(x);
        y = abs(y);

        vector<pair<int,int>> dir{
            {2,1}, {2,-1}, {-2,1}, {-2,-1},
            {1,2}, {1,-2}, {-1,2}, {-1,-2}
        };

        queue<pair<int,int>> q;
        set<pair<int,int>> visited;

        q.push({0,0});
        visited.insert({0,0});

        int level = 0;

        while(!q.empty()){

            int n = q.size();

            while(n--){

                auto [i,j] = q.front();
                q.pop();

                if(i == x && j == y) return level;

                for(auto d : dir){

                    int I = i + d.first;
                    int J = j + d.second;

                    // Don't explore far into the negative side.
                    if(I >= -2 && J >= -2 &&
                       !visited.count({I,J})){

                        visited.insert({I,J});
                        q.push({I,J});
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
