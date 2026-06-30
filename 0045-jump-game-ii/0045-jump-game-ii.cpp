// GREEDY soln
// BFS-like
               /* 1. Why do we initialize r = 0 and not r = nums[0]?

Think of Jump Game II as BFS on an implicit graph.
Before taking any jumps, we are only at index 0.
Therefore, the initial BFS layer is:
Layer 0 = [0, 0]
So we initialize:
l = 0;
r = 0;
jumps = 0;

If we instead write:
r = nums[0];
we are incorrectly assuming that we have already taken one jump and can reach all indices from 0 to nums[0].

Memory trick:
r represents the right boundary of the positions reachable with the current number of jumps.
With 0 jumps, only index 0 is reachable. */

                  /*   2. Why do we iterate only until n - 1?

The goal is to reach the last index, not to process it.
Once the last index becomes reachable, we have already found the minimum number of jumps.
If we continue processing index n-1, we may count an extra jump.

Therefore, we use:
for (int i = 0; i < n - 1; i++)
instead of:
for (int i = 0; i < n; i++)

Memory trick:
We never jump from the destination, so we never need to process the destination. */ 

// Jump Game II can be thought of as a BFS problem where each range [l, r] represents all positions reachable using the current number of jumps. Starting with [0,0] because with 0 jumps we can only be at index 0, we scan every index in the current range and compute the farthest position that can be reached from any of them. Once the entire range is processed, we increment the jump count and make the next range [r+1, farthest]. We do not need to remember which index gave the farthest reach; only the farthest reachable position matters. We iterate only until n-1 because once the last index is reachable, no further jumps are needed.

class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;   // not int r=nums[0]
        int count=0; int maxJ=0; int n=nums.size();

        for(int i=0;i<n-1;i++){     // n-1, not n
            if(n==1) return 0;

            // if(i<=r){
            //    maxJ=max(maxJ,i+nums[i]);
            // }

            maxJ=max(maxJ,i+nums[i]);
            
//          if(maxJ>=n-1){
//               if(l!=i) count++;
//               count++;
//               return count;
//          }

            if(i==r){
                l=r+1; r=maxJ;                        // l=maxJ; r=nums[l]+l;
                count++;
            }
            
        }
        return count;
    }
};