// simple running counter
// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

//         nums.erase(unique(nums.begin(),nums.end()),nums.end());

//         int n=nums.size();
//         if(n<3) return nums[n-1];

//         return nums[n-3];
//     }
// };

// one pass soln- optimal
// it mgiht be possible somethimes that the 3rd largets is int_min itself, so to be able to conclude it(third largest) exists or not we use llong min
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first,second,third;
        first=second=third=LLONG_MIN;

        for(int n:nums){
            if(n==first||n==second||n==third) continue;

            else if(n>first){
                third=second;
                second=first;
                first=n;
            }
            else if(n>second){
                third=second;
                second=n;
            }
            else if(n>third){
                third=n;
            }
        }
        return third==LLONG_MIN ? first : third;
    }
};