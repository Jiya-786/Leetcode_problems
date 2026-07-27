// bute force is checking every pair

// one pass soln-
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;

        for(int x:prices){
            if(x<minPrice){
                minPrice=x;
            }
            maxProfit=max(maxProfit,x-minPrice);
        }        
        return maxProfit;
    }
};

// kadanes algo
