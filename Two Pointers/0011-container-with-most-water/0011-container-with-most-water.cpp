// // brute force
// // check every pair (nC2) and find area
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxxArea=0;

//         for(int i=0;i<height.size();i++){
//             for(int j=i+1;j<height.size();j++){
//                 int currArea=(min(height[i],height[j]))*(j-i);
//                 maxxArea=max(maxxArea,currArea);
//             }
//         }
//         return maxxArea;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxAr=0;

        while(left<right){
            int width=right-left;
            int ht=min(height[left],height[right]);
            maxAr=max(maxAr,ht*width);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxAr;
    }
};