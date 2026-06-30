// Last updated: 30/06/2026, 19:32:54
// optimal
// greedy + 2pointers
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int count=0;
        int i=0; int j=0;

        while(i<g.size() && j<s.size()){     // not for obvio
            if(s[j]>=g[i]){
                i++; count++;
            }
            j++;
        }
        return count;
    }
};