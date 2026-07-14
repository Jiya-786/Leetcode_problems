// We use BFS to solve this question
// Start with the given string then keep replacing one character at a time and see if it matches the target or if it is present in the dead end. Then keep doing the same for all the new strings that we got after replacing each new character. This way we are doing a level order traversal of all the new strings that we get. And because we need the minimum number of turns BFS is the way to go. So just maintain a queue. Push the given string. Then replace each character in the string and If it is valid I eat not in dead end push it into the queue and update the count. And because The given question states that the lock can move forward and backward we need to replace every single character its successor and its predecessor one by one to check all  possibilities and find the shortest path.
class Solution {
public:

    void fillNeighbours(queue<string>& q,string& curr,unordered_set<string>& stop){
        for(char& c:curr){                    // rember to pass by referenc to make actual changes, not a copy.
            char temp=c;
            char dec= c=='0' ? '9' : c-1;
            char inc= c=='9' ? '0' : c+1;

            c=inc;
            if(!stop.count(curr)){
                q.push(curr);
                stop.insert(curr);
            } 

            c=dec;
            if(!stop.count(curr)){
                q.push(curr);
                stop.insert(curr);
            } 

            // get it back to the og c value becuase we are itereting each char c onr by one on the og curr, we have to revert back curr to its initial state.
            c=temp;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> stop(deadends.begin(),deadends.end());
        queue<string> q;
        q.push("0000");
        int level=0;

        if(stop.count("0000")) return -1;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto it=q.front();
                q.pop();

                if(it==target) return level;

                fillNeighbours(q,it,stop);
            }
            level++;
        }
        return -1;
    }
};