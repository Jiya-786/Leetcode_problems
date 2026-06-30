// Last updated: 30/06/2026, 19:31:08
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        
        string req="";
        for(int i=0;i<n;i++) req+='#';
        
        for(int i=0;i<m;i++){
           grid.push_back(req);
        }

        for(int i=0;i<n;i++){
            grid[0][i]='.';
        }

        for(int j=0;j<m;j++){
            grid[j][n-1]='.';
        }

        return grid;
    }
};