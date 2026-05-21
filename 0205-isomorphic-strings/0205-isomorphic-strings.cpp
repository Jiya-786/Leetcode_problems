class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapS;
        unordered_map<char,char> mapT;

        if(s.size()!=t.size()) return false;
        
        for(int i=0;i<s.size();i++){
            char charS=s[i];
            char charT=t[i];

            if(mapS.count(charS) && mapS[charS]!=charT){
                return false;
            }
            if(mapT.count(charT) && mapT[charT]!=charS){
                return false;
            }

            mapS[charS]=charT;
            mapT[charT]=charS;
        }
        return true;
    
    }
};