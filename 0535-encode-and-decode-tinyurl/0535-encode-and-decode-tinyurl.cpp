// time o(1)
// space o(n)
// this is the most basic version
// it gives duplicate short url for same long url
// since we are not checking if we have shortened the url already
// this can be improved using randomizing the counter aka key and maintaing a hash to chek if we 
// have already shortened the url
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