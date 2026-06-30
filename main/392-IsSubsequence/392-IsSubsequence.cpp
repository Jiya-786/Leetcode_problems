// Last updated: 30/06/2026, 19:33:12
// Approach 2: Binary Search with Preprocessing

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,vector<int>> mp;
        for(int j=0;j<t.size();j++){
            mp[t[j]].push_back(j);
        }
        int prevIndex=-1;

        for(char c:s){
            if(mp.find(c)==mp.end()) return false;

            vector<int>& indices=mp[c];
            auto it=lower_bound(indices.begin(),indices.end(),prevIndex+1);    // The lower bound function finds the opposition of the element
                                                                               // which is greater than or equal to the target value. Internally, the lower bound function uses binary search
            if(it==indices.end()) return false;

            prevIndex=*it;   // It is a pointer so we need to use the dereferencing operator to get the
                             // previous index value

        }
        return true;
    }
};