class Solution {
public:

    void dfs(vector<vector<int>>& image,int i,int j,int color,int ogColor,vector<vector<int>>& visited){
        int n=image.size();
        int m=image[0].size();
        if(i<0||j<0||i>=n||j>=m||visited[i][j]==1) return;
        if(image[i][j]==ogColor){
            image[i][j]=color;
            visited[i][j]=1;

            dfs(image,i+1,j,color,ogColor,visited);
            dfs(image,i-1,j,color,ogColor,visited);
            dfs(image,i,j-1,color,ogColor,visited);
            dfs(image,i,j+1,color,ogColor,visited);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int ogColor=image[sr][sc];
        vector<vector<int>> visited(n,vector<int>(m,0));    /* Whenever you see heap-buffer-overflow
                                                               ask yourself:
                                                                    > Which line did it happen on?          (AddressSanitizer tells you.)
                                                                    > Which array/vector is being accessed on that line?
                                                                    > Can its index be invalid?
                                                                    Was the vector created with the correct size?*/
        dfs(image,sr,sc,color,ogColor,visited);

        return image;
    }
};