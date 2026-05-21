// time o(1)
// space o(n)
class Solution {
    unordered_map<int,string> map;
    int counter=0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        map[counter]=longUrl;
        return "http://tinyurl.com/"+ to_string(counter++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id=stoi(shortUrl.substr(shortUrl.rfind('/')+1));
        return map[id];
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));