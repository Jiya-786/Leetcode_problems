// on time 
// on space soln
// splitting using istringstream
// istringstream inherently handles spaces in input
// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> st;
//         istringstream stream(s);
//         string word;

//         while(stream>>word){
//             st.push(word);
//         }

//         string ans="";

//         while(!st.empty()){
//             ans+=st.top();
//             st.pop();

//             if(st.size()>=1) ans+=" ";
//         }

//         return ans;
//     }
// };

// now to make it o1 space we need to use 2 pointers and do right to left traversal
// this doesnt inherently handle extra spaces like istringstream
// we need extra care for that case
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size()-1;
        
        int i=n;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;

            int end=i;
            while(i>=0 && s[i]!=' ') i--;

            if(!ans.empty()) ans+=' ';
            ans+=s.substr(i+1,end-i);   // rember the 2nd paramet is length, not end_index. 

        }
        return ans;
    }
};