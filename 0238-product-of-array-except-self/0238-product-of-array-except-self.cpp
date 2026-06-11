// optimized techniqe
//     store prefix products directly in result array
//     in a single right to left pass, keep multiplying the prefix values with the suffixProduct
//     values
//     where suffixProduct is a running variable
//     this gives us o(1) space becuase per qs result array should be not considred in space
//     complexity 
// time o(n)
// space o(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);     // to declare result[0]=1 we need to write result(n), just
                                   // result won't work
        result[0]=1;
        for(int i=1;i<n;i++){
            result[i]=result[i-1]*nums[i-1];
        }
        int suffixProd=1;
        for(int i=n-1;i>=0;i--){
            result[i]=result[i]*suffixProd;
            suffixProd*=nums[i];
        }
        return result;
    }
};