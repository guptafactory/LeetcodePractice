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
private:
    void dfs(int node_ind, int &ans, vector<Employee*> &employees, unordered_map<int, int> &ind) {
        ans += employees[node_ind]->importance;
        for(auto it: employees[node_ind]->subordinates) {
            dfs(ind[it], ans, employees, ind);
        }
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size(), ans = 0;
        unordered_map<int, int> ind;
        for(int i = 0; i < n; i++) ind[employees[i]->id] = i;
        dfs(ind[id], ans, employees, ind);
        return ans;
    }
};