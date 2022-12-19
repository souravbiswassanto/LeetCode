class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        bool vis[n + 1];
        memset(vis, 0, sizeof vis);
        queue<int> Q; Q.push(source);
        vis[source] = true;
        vector<int> g[n + 1];
        for (auto it: edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            if (u == destination) return true;
            for (auto v: g[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                Q.push(v);
                
            }
        }
        return false;
    }
};