// same as Number of Connected Components in an Undirected Graph 
// except here instead of vector arr for edges, we have 2d grid (matrix rep)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=findParent(parent[i]);
    }

    void Union(int u,int v){
        int parent_u=findParent(u);
        int parent_v=findParent(v);

        if(rank[parent_u]<rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else if(rank[parent_u]>rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else{
            parent[parent_v]=parent_u;
            rank[parent_u]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int provinces=n;
        parent.resize(n,0);    // don't forget to resize after declaring as global var
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // if(isConnected[i][j]==1 && parent[i]!=parent[j]){    note the diff bw parent[i] and       
                //                                                      findParent(). its crucial
                if(isConnected[i][j]==1 && findParent(i)!=findParent(j)){
                    Union(i,j);
                    provinces--; 
                }
            }
        }
        return provinces;
    }
};