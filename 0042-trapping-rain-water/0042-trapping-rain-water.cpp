// // BRUTE FORCE
// // keep note of bar of max length on the right and on the left of a given bar
// // time o(n2)
// // space o(1)
// // Redundant Work. The algorithm recomputes the left and right maximums from scratch for every single bar.
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         unordered_map<int,int> left;
//         unordered_map<int,int> right;
//         int n=height.size();
//         for(int i=0;i<n-1;i++){
//             int maxLeft=0;
//             for(int j=i-1;j>=0;j--){
//                 maxLeft=max(maxLeft,height[j]);
//             }   
            
//             left[i]=maxLeft;

//             int maxRight=0;
//             for(int j=i+1;j<n;j++){
//             //    if(height[j]>height[i]){
//             //         maxRight=max(maxRight,height[j]);
//             //     }            the max left/right need not necessarily be taller than the ith height
//             maxRight=max(maxRight,height[j]);
//             }
//             right[i]=maxRight;
            
//         }
//         // left[0]=0;
//         // left[n-1]=0;

//         // right[0]=0;
//         // right[n-1]=0;
        
//         int totWater=0;
//         for(int i=0;i<n;i++){
//             if(left[i]==0 || right[i]==0){
//                 continue;
//             }
//             // else{
//             //     totWater+=max(0,(min(left[i],right[i])-height[i]));
//             // }
//             // totWater+=(min(left[i],right[i])-height[i]);
//             totWater+=max(0,(min(left[i],right[i])-height[i]));   
//         }
//         return totWater;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0; int right=n-1;
        int leftMax=0, rightMax=0;
        int totalWater=0;

        while(left<right){

            if(height[left]<height[right]){
                if(height[left]>=leftMax){
                    leftMax=height[left];
                }
                else{
                    totalWater+=leftMax-height[left];
                }
                left++;
            }

            else{
                if(height[right]>=rightMax){
                    rightMax=height[right];
                }
                else{
                    totalWater+=rightMax-height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};