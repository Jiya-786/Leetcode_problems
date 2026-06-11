//insertion sort
// there are 2 arrays left sorted array and right unsorted array so we start form the 2nd elt and keep checking for the correct elts in the unsorted array
//to implement it by code we will use 2 variable i for finding out key elt and j for finding the correct position


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         for(int i=1;i<=nums.size()-1;i++){
//             int key=nums[i];
//             int j=i-1;
//             while(j>=0 && nums[j]>=key){
//                 nums[j+1]=nums[j];
//                 j--;
//             }
//             nums[j+1]=key;
//         }
//         return nums[nums.size()/2];
//     }
// };

//moores voting algorithm
//we use the fact that if an elt is in majority then it will never get cancelled by any other terms of we run the loop for the entire array
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=0;
        int vote=0;
        for(int i=0;i<nums.size();i++){
            if(vote==0){
                winner=nums[i];
                vote++;
            }
            else if(nums[i]==winner){
                vote++;
            }
            else{
                vote--;
            }
        }
        return winner;
    }
};
