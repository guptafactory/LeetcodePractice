class Solution {
private:
    void buildMap(map<string, vector<pair<string, double>>> &mp, vector<vector<string>>& equations, vector<double>& values) {
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string src = equations[i][0];
            string dest = equations[i][1];
            mp[src].push_back({dest, values[i]});
            mp[dest].push_back({src, 1.0 / values[i]});
        }
    }
    void dfs(string src, string &dest, double &res, double calc, unordered_map<string, bool> &vis, map<string, vector<pair<string, double>>> &mp) {
        vis[src] = true;
        for (auto &arr : mp[src]) {
            if (res != -1) return;
            string inter_node = arr.first;
            if (vis[inter_node]) continue;
            double temp = calc;
            calc *= arr.second;
            if (inter_node == dest) {
                res = calc;
                return;
            }
            else dfs(inter_node, dest, res, calc, vis, mp);
            calc = temp;
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> mp;
        vector<double> ans;
        buildMap(mp, equations, values);
        for (auto &arr : queries) {
            string src = arr[0];
            string dest = arr[1];
            if (!mp[src].size() || !mp[dest].size()) { ans.push_back(-1.0); continue; }
            if(src == dest) { ans.push_back(1.0); continue; }
            unordered_map<string, bool> vis;
            double res = -1, calc = 1;
            dfs(src, dest, res, calc, vis, mp);
            ans.push_back(res);
        }
        return ans;
    }
};