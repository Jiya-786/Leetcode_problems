// using freq as key using delimiter
// avoids sorting entirely and brings per-string cost down from o(klogk) to o(k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;

        for(const string& s:strs){
            int freq[26]={0};
            for(char c:s){
                freq[c-'a']++;
            }

            // build a unique key from freq array
            string key;
            for(int i=0;i<26;i++){
                key+='#';
                key+=to_string(freq[i]);
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