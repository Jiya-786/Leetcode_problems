class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int i){
        if(parent[i]==i){
            return i;
        }
        // else statement. but not writing else because it makes return statement complex.
        return parent[i]=findParent(parent[i]);
        // the parent[i]=findParent() is an extension from the path compression idea.
        // although fo the first call it would follow the same thing as without path compression,
        // but for later calls it would only req 1 extra call istead of many. becuase we can directly
        // jump to parent, instead of jumping all nodes above the given node.
    }

    void Union(int u,int v){
        int u_parent=findParent(u);
        int v_parent=findParent(v);                        

        if(rank[u_parent]<rank[v_parent]){
            parent[u_parent]=v_parent;
        }
        else if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
        }
        else{
            parent[u_parent]=v_parent;
            rank[v_parent]++;
        }
    } 

    int countComponents(int n, vector<vector<int>>& edges){
        parent.resize(n,0);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int components=n;

        for(auto& it:edges){
            int u=it[0];
            int v=it[1];

            if(findParent(u)!=findParent(v)){
                Union(u,v);
                components--;
            }
        }
        return components;
    }
};
