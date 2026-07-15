// We use BFS because every dice roll costs 1 move.
// BFS guarantees that the first time we reach square n*n,
// it is using the minimum number of moves.
//
// Start from square 1.
// From every square, generate all possible neighbours by
// rolling the dice (1 to 6).
//
// If we land on a snake or ladder, we MUST immediately move
// to its destination before continuing the BFS.
//
// Remember to mark the landing square (nxt) as visited,
// NOT the destination of the snake/ladder.
// Example:
// 1 --die--> 2 --ladder--> 15
// We push 15 into the queue because that's where we finally
// stand, but we mark 2 as visited because we've already
// explored the move of landing on square 2. Otherwise, every
// time we return to 1 we'll generate the same ladder again.

class Solution {
public:

    // Converts a square number (1...n²) into its corresponding
    // (row, col) on the board. Remember that every alternate row
    // is numbered in reverse direction.
    vector<int> getCoords(int x,int n){
        int rt=(x-1)/n;
        int rb=(n-1)-rt;

        int c=0;
        if((rb%2==0 && (n-1)%2==0)||(rb%2==1 && (n-1)%2==1)){
            if(x%n==0) c=n-1;
            else c=(x%n)-1;
        }
        else{
            if(x%n==0) c=0;
            else c=n-(x%n);
        } 
        vector<int> v;
        return v={rb,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        q.push(1);
        int moves=0;
        unordered_set<int> visited;
        visited.insert(1);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int x=q.front();
                q.pop();

                if (x==n*n) return moves;

                int nxt=0;
                for(int i=1;i<=6 && x+i<=n*n;i++){
                    nxt=x+i;
                    if(!visited.count(nxt)){
                        visited.insert(nxt);
                        auto it=getCoords(nxt,n);
                        int I=it[0];
                        int J=it[1];
                        if(board[I][J]==-1){
                            q.push(nxt);
                            // visited.insert(nxt);
                        }
                        else{
                            q.push(board[I][J]);
                            // visited.insert(board[I][J]);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};