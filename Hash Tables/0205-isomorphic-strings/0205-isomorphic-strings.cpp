class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lastSeenS[256],lastSeenT[256];
        fill(lastSeenS,lastSeenS+256,-1);
        fill(lastSeenT,lastSeenT+256,-1);

        for(int i=0;i<s.size();i++){
            if(lastSeenS[s[i]]!=lastSeenT[t[i]]){
                return false;
            }

            lastSeenS[s[i]]=i;
            lastSeenT[t[i]]=i;
        }
        return true;

    }
};