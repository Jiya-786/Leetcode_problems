// We use BFS to solve this question.
// Similar to Open the Lock and Minimum Genetic Mutation.
// Go through their comments.
//
// Remember: in these state-space BFS problems, always mark a state as
// visited after pushing it into the queue. Otherwise, the same state
// will keep getting generated, leading to an infinite loop/TLE.
//
// Also remember to skip replacing a character with itself.
// If the current character is 'a', don't replace it with 'a' again.
// Only try the remaining 25 letters.
//
// The only real changes from Minimum Genetic Mutation are:
// 1. Instead of trying {'A','C','G','T'}, try every lowercase letter 'a' to 'z'.
// 2. The set 'allowed' is now called 'words' because every valid word in the
//    dictionary is a valid state.
// 3. Start level = 1 instead of 0 because beginWord itself is counted as the
//    first word in the transformation sequence.
//
// Everything else remains exactly the same.
class Solution {
public:

    // always remember to pass by reference
    void fillNeighbours(queue<string>& q, string& curr,
                        unordered_set<string>& words){

        for(char &c : curr){

            char temp = c;

            for(char ch = 'a'; ch <= 'z'; ch++){

                if(ch == c) continue;

                c = ch;

                if(words.count(curr)){
                    q.push(curr);
                    words.erase(curr);
                }
            }

            c = temp;
        }
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if(!words.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while(!q.empty()){

            int n = q.size();

            while(n--){

                auto it = q.front();
                q.pop();

                if(it == endWord) return level;

                fillNeighbours(q, it, words);
            }

            level++;
        }

        return 0;
    }
};