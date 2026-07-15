// we start at 1 and explore all its possible neighbours from die roll include snake,ladder
// keep marking visited
// keep visiting neighbours of those neighbours
// and becuase of bfs we will definitely find n^2 by the shortest path
class Solution {
public:
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