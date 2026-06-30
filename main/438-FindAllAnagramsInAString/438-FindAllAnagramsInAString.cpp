// Last updated: 30/06/2026, 19:33:00
// M-3 maintaining array instead of hash-map
// faster run time
// although theoretically both are o(n)
// but hash-map has more over-head
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int> phash(26,0),shash(26,0);

        if(n<m) return {};

        vector<int> ans;
        for(int i=0;i<m;i++){
            phash[p[i]-'a']++;
            shash[s[i]-'a']++;
        }
        if(phash==shash) ans.push_back(0);

        for(int i=m;i<n;i++){
            shash[s[i]-'a']++;
            shash[s[i-m]-'a']--;

            if(shash==phash) ans.push_back(i-m+1);
        }
        return ans;
    }
};