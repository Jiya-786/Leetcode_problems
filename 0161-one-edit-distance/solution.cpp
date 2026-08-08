// if we can delete and make both strings equal, that means we can also insert in the otehr string and make both equal
// hence to avoid that confusion and compress insert and delete into one case, let's always make the longer string as s
// this is oN time
// on space becase substr creates new strings and in worst case it can be proportional to n
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(abs(n-m)>1) return false;

        else{
            if(n-m<1) swap(s,t);
            // so now s is the longer string

            for(int i=0;i<t.length();i++){
                if(s[i]!=t[i]){
                    if(s.size()==t.size()){
                        return s.substr(i+1)==t.substr(i+1);
                    }
                    else{
                        return s.substr(i+1)==t.substr(i);
                    }
                }
            }
            return s.length()==t.length()+1;
        }
    }
};
