// We use BFS to solve this question
// similar to open the lock
// go through its comments
// rember in these typq of qs it will go in infinte loop if we forget to mark visited
// and rember to skip the same character in a given stae. if char in curr is a do not replace by a again, replace by remaing 3 chars ow also it will get stuck in infinite loop
class Solution {
public:
    
    vector<char> valid{'A','C','G','T'};
    
    // always rember to pass by ref
    void fillNeighbours(queue<string>& q,string& curr,unordered_set<string>& allowed){
        for(char& c:curr){
            for(int i=0;i<=3;i++){
                if(c==valid[i]) continue;
                char temp=c;
                c=valid[i];
                if(allowed.count(curr)){
                    q.push(curr);
                    allowed.erase(curr);
                } 

                c=temp;
            }
        }
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> allowed(bank.begin(),bank.end());
        queue<string> q;
        q.push(startGene);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto it=q.front();
                q.pop();

                if(it==endGene) return level;

                fillNeighbours(q,it,allowed);
            }
            level++;
        }
        return -1;
    }
};