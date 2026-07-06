// prime number hashing 
// time complexity was already at best, but this is just an extra clever math trick
// this will give us an int key instead of string key
// just assign prime numbers to all letters and multiply letters in the word to get its key
// then group acc to this key
// no sorting or string building or delimiter handling
// but does not work most of the times since long long might also overflow
// but req since sometimes asked
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        unordered_map<long long,vector<string>> groups;

        for(string s:strs){
            long long key=1;
            for(char c:s){
                key*=primes[c-'a'];
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& it:groups){
            result.push_back(move(it.second));
        }
        return result;
    }
};
