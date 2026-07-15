// we do multisource bfs from sll zeroes
// multisource bfs guarantees shortest path
// so the nearest 0 will always find its nearest 1
// hence initialize all 0's with dist=0
// then start multisource bfs so that all 0's find their 1's
// and keep updating their distances
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dir {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto it=q.front();
                q.pop();

                int i=it.first;
                int j=it.second;

                for(auto d:dir){
                    int I=d.first+i;
                    int J=d.second+j;

                    if(I>=0 && J>=0 && I<n && J<m && dist[I][J]==-1){    // the dist arr elt=-1 also means its 
                                                                         //an unvisited elt in iteself because 
                                                                         // we have marked all 0's dists as 0 a
                                                                         // nd every visited 1 would atleast  /
                                                                         // have 1 as its dist grid elt, bit 
                                                                         // every unvisited elt would still 
                                                                         // have -1
                        dist[I][J]=dist[i][j]+1;
                        q.push({I,J});
                    }
                }
            }
        }
        return dist;
    }
};