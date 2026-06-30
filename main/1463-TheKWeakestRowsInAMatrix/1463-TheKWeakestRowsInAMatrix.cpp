// Last updated: 30/06/2026, 19:31:14
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<pair<int,int>> rows;

        for(int i=0;i<n;i++){
            int soldiers=0;
            for(int x:mat[i]) soldiers+=x;
            rows.push_back({soldiers,i});
        }

        // sort by soldiers ascending, then index
        // ascending
        sort(rows.begin(),rows.end());

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(rows[i].second);
        }

        return ans;

    }
};