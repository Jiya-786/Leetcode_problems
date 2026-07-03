// algebraic soln
// time o(nlogn)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> rem1;
        vector<int> rem2;
        int sum=0;

        for(int& a:nums){
            sum+=a;

            if(a%3==1) rem1.push_back(a);
            if(a%3==2) rem2.push_back(a);
        }
        sort(rem1.begin(),rem1.end());
        sort(rem2.begin(),rem2.end());

        if(sum%3==0) return sum;
        
        // if tot sum has remainder 1:
        // either remove one no with rem 1
        // or remove 2nors with rem 2
        else if(sum%3==1){
            int d= rem1.size()>=1 ? rem1[0] : INT_MAX;
            int e= rem2.size()>=2 ? rem2[0]+rem2[1] : INT_MAX;
            sum-=min(d,e);
        }

        // if tot sum has rem 2
        // either remove 1 no with rem 2
        // or remove 2 nores with rem 1 
        else if(sum%3==2){
            int d= rem2.size()>=1 ? rem2[0] : INT_MAX;
            int e= rem1.size()>=2 ? rem1[0]+rem1[1] : INT_MAX;
            sum-=min(d,e);
        }
        return sum;
    }
};