// Instead of random keys, use a hash function on the long URL to produce a fixed-length key. Java's 
// built-in hashCode() or any hash function maps the URL to an integer, which we then convert to a comp-
// act string.

// This approach is deterministic: the same URL always produces the same short URL, eliminating the need 
// for a reverse map.

// The trade-off is that hash collisions are possible (different URLs could produce the same hash). We 
// handle this by checking for collisions and incrementing the key when they occur. But for the scale of 
// this problem, collisions are extremely rare.
class Solution {
    unordered_map<size_t, string> map;

public:
    string encode(string longUrl) {
        // Use std::hash for deterministic mapping
        size_t key = hash<string>{}(longUrl);
        // Handle collision: if the key exists but maps to a different URL
        while (map.count(key) && map[key] != longUrl) {
            key++;
        }
        map[key] = longUrl;
        return "http://tinyurl.com/" + to_string(key);
    }

    string decode(string shortUrl) {
        size_t key = stoull(shortUrl.substr(shortUrl.rfind('/') + 1));
        return map[key];
    }
};