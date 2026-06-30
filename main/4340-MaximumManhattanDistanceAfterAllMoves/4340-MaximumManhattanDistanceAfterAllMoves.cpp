// Last updated: 30/06/2026, 19:31:10
class Solution {
public:
    int maxDistance(string moves) {
        int xc=0; int yc=0;

        for(char c:moves){
            if(c=='L') xc--;
            else if(c=='R') xc++;
            else if(c=='U') yc++; else if(c=='D') yc--;
            else continue;
        }

        int dist=abs(xc)+abs(yc);
        
        for(char c: moves){
            if(c=='_') dist++;
        }
        return dist;
    }
};