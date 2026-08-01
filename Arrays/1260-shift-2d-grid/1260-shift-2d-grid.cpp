// for a flattened 2d-grid from 0 to n-1, corresponding row and cols are given by-
// assuming tot_col is known
// row=i/tot_col
// col=i%tot_col
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        int n=row*col;

        k=k%n;
        // if(k==0) return grid;

        // The lambda is created inside the same function, so [&] captures the surrounding local variables like row and col by reference.
        // can write a separate fxn also but we will have to pass many variables into it
        auto reverse=[&](int i,int j){
            while(i<j){
                swap(grid[i/col][i%col],grid[j/col][j%col]);
                i++;
                j--;
            }
        };
        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);

        return grid;
    }
};