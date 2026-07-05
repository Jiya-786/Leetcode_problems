// sorting + greedy
// most optimized
// time o(nlogn)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b){return a[1]<b[1];});

        int prev=pairs[0][1];
        int count=1;
        for(int i=1;i<n;i++){
            if(pairs[i][0]>prev){
                count+=1;
                prev=pairs[i][1];
            }
        }
        return count;
    }
};