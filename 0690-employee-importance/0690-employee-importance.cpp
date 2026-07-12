/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int ans=0;
    void dfs(int id,unordered_map<int,vector<int>>& mp){
        ans+=mp[id][0];
        for(int i=1;i<mp[id].size();i++){
            dfs(mp[id][i],mp);
        }
    }

    int getImportance(vector<Employee*> employees, int id) {
        // making adj list
        unordered_map<int,vector<int>> mp;
        for(auto it:employees){
            vector<int> temp;
            temp.push_back(it->importance);
            for(int x:it->subordinates){
                temp.push_back(x);
            }
            mp[it->id]=temp;
        }
        dfs(id,mp);
        return ans;
    }
};