// // classic BRUTE FORCE
// // check notes to udnerstand approach
// // convert into house robber-1 by breaking into 2 separate cases and solve
// but time o(2^n): exponential
// gives TLE
// hence memoize

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();

//         if(n==1) return nums[0];

//         int a=solve(nums,0,n-2);
//         int b=solve(nums,1,n-1);

//         return max(a,b);
//     }
// private:
//     int solve(vector<int>& nums,int i,int n){

//         if(i>n) return 0;

//         int steal=nums[i]+solve(nums,i+2,n);
//         int skip=solve(nums,i+1,n);

//         return max(steal,skip);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t1(n+1,-1);
        vector<int> t2(n+1,-1);
        // t[0]=0;
        // t[1]=nums[0];

        if(n==0) return 0;  // not rlly req
        if(n==1) return nums[0];

        int a=solve(nums,0,n-2,t1);
        int b=solve(nums,1,n-1,t2);

        return max(a,b);
    }
private:
    int solve(vector<int>& nums,int i,int n,vector<int>& t){       // we will have to use 2 diff t vectors for both 
                                                                   // a and b, ow will mix up repeating 
                                                                   // sub-problems of both a and b.        

        if(i>n) return 0;

        if(t[i]!=-1) return t[i];

        int steal=nums[i]+solve(nums,i+2,n,t);
        int skip=solve(nums,i+1,n,t);

        return t[i]=max(steal,skip);
    }
};