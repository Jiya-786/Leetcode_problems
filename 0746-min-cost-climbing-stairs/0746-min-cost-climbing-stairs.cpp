// // brute force soln
// // basic recursion
// // time o(2^n): exponential, v. bad
// //space o(n)
// // gives TLE, hence memoize
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(solve(0,cost),solve(1,cost));
//     }
// private:
//     int solve(int i, vector<int>& cost){
//         if(i>=cost.size()) return 0;

//         int a=cost[i]+solve(i+1,cost);
//         int b=cost[i]+solve(i+2,cost);

//         return min(a,b);

//     }
// };

// brute force soln
// basic recursion
// time o(2^n): exponential, v. bad
//space o(n)
// gives TLE, hence memoize
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> t(cost.size()+1,-1);
        return min(solve(0,cost,t),solve(1,cost,t));
    }
private:
    int solve(int i, vector<int>& cost,vector<int>& t){
        int n=cost.size();
        // vector<int> t(n+1,-1);   if we define it here, it will call a fresh vector everytime,     
        //                          useless

        if(i>=cost.size()) return 0;     // base case first

        if(t[i]!=-1) return t[i];

        // if(i>=cost.size()) return 0;

        int a=cost[i]+solve(i+1,cost,t);
        int b=cost[i]+solve(i+2,cost,t);

        return t[i]=min(a,b);

    }
};