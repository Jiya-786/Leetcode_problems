class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tot=0;
        int aTot=0;
        for(int a:apple) aTot+=a;

        sort(capacity.begin(),capacity.end(),greater<int>());

        for(int i=0;i<capacity.size();i++){
            tot+=capacity[i];
            if(tot>=aTot) return i+1;
        }
        return capacity.size();
    }
};