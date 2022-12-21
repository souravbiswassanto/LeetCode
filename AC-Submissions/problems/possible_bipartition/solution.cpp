class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n], in(n, 0), vis(n, 0), level(n, 0);
        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = 1; q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v: graph[u]) {
                    if (vis[v]) {
                        if (level[v] == level[u]) {
                            return false;
                        }
                        continue;
                    }
                    q.push(v);
                    vis[v] = 1; level[v] = level[u] ^ 1;
                }
            }
        }
        return true;
    }
};