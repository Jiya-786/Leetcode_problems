// Last updated: 30/06/2026, 19:33:10
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string result="";
        int n=num.length();

        if(k>=num.length()){
                return "0";
        }
        for(char c:num){
            // if(k>=num.length()){
            //     return "0";
            // }
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        // if k is still left after the number has completed remove from end
        while(k){
            st.pop();
            k--;
        }  
        // build result
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());          // because stack is LIFO

        // remove leading zeroes
        int i=0;
        while(i<result.size() && result[i]=='0'){
            i++;
        }

        result.erase(0,i);
        if(result=="") return "0";

        return result;

    }
};