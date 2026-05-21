// random key generation
// instead of predictable sequential IDs, generate a random alphanumeric string for each URL
// and also maintain a hash to avoid duplicate short urls for same long url
// ie we want a bijection
// and for a bijection, like in isomorphic string, we need 2 hash-maps

// The random approach is excellent for most purposes, but it's non-deterministic. Two different 
// instances of the class will produce different short URLs for the same input. What if we want a 
// deterministic approach where the same URL always maps to the same short URL, without needing 
// the url2code dedup map?
class Solution {
    unordered_map<string,string> code2url;
    unordered_map<string,string> url2code;
    string chars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string prefix="http://tinyurl.com/";

    string generateKey(){
        string key;
        for(int i=0;i<6;i++){
            key+=chars[rand()%chars.size()];
        }
        return key;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // if(url2code.count[longUrl]){
        if(url2code.count(longUrl)){
            return prefix+url2code[longUrl];
        }
        string key=generateKey();
        while(code2url.count(key)){
            key=generateKey();
        }
        code2url[key]=longUrl;
        url2code[longUrl]=key;
        return prefix+key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key=shortUrl.substr(prefix.size());
        return code2url[key];
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));