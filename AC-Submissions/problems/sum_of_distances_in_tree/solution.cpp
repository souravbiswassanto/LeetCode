class Solution {
public:
    vector<int> subtreeSize, dist; 
    vector<vector<int>> g;
    int dfs(int source, int par) {
        subtreeSize[source] = 1;
        int distances = 0;
        for (auto v: g[source]) {
            if (v == par) continue;
            distances += dfs(v, source);
            subtreeSize[source] += subtreeSize[v];
        }
        dist[source] = distances;
        return dist[source] + subtreeSize[source];
    }

    void dfs1(int source, int par) {
        if (source) {
            dist[source] = dist[par] - 2 * subtreeSize[source] + dist.size();
        }
        for (auto v: g[source]) {
            if (v == par) continue;
            dfs1(v, source);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        subtreeSize.resize(n, 0);
        dist.resize(n, 0);
        g.resize(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0]; int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0, -1);
        dfs1(0,-1);
        return dist;
    }
};