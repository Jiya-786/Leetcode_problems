// // BRUTE FORCE 
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         int maxAr=0;

//         for(int i=0;i<n;i++){
//             int minHt=heights[i];
//             for(int j=i;j<n;j++){
//                 minHt=min(heights[j],minHt);   // IMP LINE
//                 int currAr=minHt*(j-i+1);
//                 maxAr=max(maxAr,currAr);
//             }
//         }
//         return maxAr;
//     }
// };

// USING STACK
// the area of rectangle is bounded on both sides for a given ith rectangle by the smaller bar on the left and the smaller ber on the right
// precompute arrays with index of smaller bar on left and right using stack
// for left 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left=previousSmaller(heights);
        vector<int> right=nextSmaller(heights);

        int maxAr=0;
        for(int i=0;i<n;i++){
            int currAr=heights[i]*(right[i]-left[i]-1);
            maxAr=max(maxAr,currAr);
        }
        return maxAr;
    }

private:
    vector<int> previousSmaller(vector<int>& heights){
        stack<int> st;
        int n=heights.size();
        vector<int> left(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }

    vector<int> nextSmaller(vector<int>& heights){
        stack<int> st;
        int n=heights.size();
        vector<int> right(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }

};