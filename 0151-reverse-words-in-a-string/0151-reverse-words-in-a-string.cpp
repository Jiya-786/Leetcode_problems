// on time 
// on space soln
// splitting using istringstream
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        istringstream stream(s);
        string word;

        while(stream>>word){
            st.push(word);
        }

        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();

            if(st.size()>=1) ans+=" ";
        }

        return ans;
    }
};