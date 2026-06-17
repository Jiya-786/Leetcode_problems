// BRUTE FORCE
// time o(n2)
// space o(n) since each replacement creates a new strong of size upto o(n)
class Solution {
public:
    bool isValid(string s) {
        string prev="";
        while(s!=prev){
            prev=s;
            size_t pos;
            while((pos=s.find("()"))!=string::npos) s.erase(pos,2);
            while((pos=s.find("[]"))!=string::npos) s.erase(pos,2);
            while((pos=s.find("{}"))!=string::npos) s.erase(pos,2);
        }
        return s.empty();
    }
};