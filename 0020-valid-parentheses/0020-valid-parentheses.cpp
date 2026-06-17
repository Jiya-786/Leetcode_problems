class Solution {
    public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> match={{')','('},{']','['},{'}','{'}};

        for(char c:s){
            if(match.count(c)){
                if(stk.empty()||stk.top()!=match[c]){
                    return false;
                }
                else stk.pop();
            }
            else stk.push(c);
        }
        return stk.empty();
    }
};