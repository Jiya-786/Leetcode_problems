// Always remember if any question talks about minimum moves or shortest path it might be BFS
// Especially questions where we replace characters or digits
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        queue<string> q;
        unordered_set<string> visited;
        q.push("0000");
        visited.insert("0000");
        int turns = 0;

        while (!q.empty()) {
            int size = q.size();
            turns++;
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();
                // Generate all 8 neighbors
                for (int j = 0; j < 4; j++) {
                    for (int dir = -1; dir <= 1; dir += 2) {
                        string next = current;
                        next[j] = (char)(((next[j] - '0') + dir + 10) % 10 + '0');
                        if (next == target) return turns;
                        if (!visited.count(next) && !dead.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};