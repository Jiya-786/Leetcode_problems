// 0 1 2 3 4 5 6 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        unordered_map<char,int> pmap,smap;
        for(char c:p){
            pmap[c]++;
        }

        vector<int> ans;
        for(int i=0;i<m;i++){
            if(m>n) return {};
            smap[s[i]]++;
            if(smap==pmap) ans.push_back(0);
                // ans.push_back(i-2);  this 2 is hardcoded, it depends on the window size m, need not be 2 always
        }
        int left=0;
        for(int i=m;i<n;i++){
            smap[s[left]]--;   // if it is like {e:0} and pmap in 'abc' case has no e, equality still won't hold, hence, we should erase characters with 0 freq.
            if(smap[s[left]]==0) smap.erase(s[left]);
            smap[s[i]]++;
            left++;
            if(smap==pmap) ans.push_back(left);  // or ans.push_back(i-m+1)
        }
        return ans;
    }
};