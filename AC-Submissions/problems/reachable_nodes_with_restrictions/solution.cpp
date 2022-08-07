class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int rest[n + 3];
        vector<int> g[n + 1];
        memset(rest, 0, sizeof rest);
        for(int i = 0; i < edges.size(); ++i){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0; i < restricted.size(); ++i) {
            rest[restricted[i]] = 1;
        }
        
        function<int(int, int)> dfs = [&] (int source, int par) {
            int sz = 1;
            
            for(auto v: g[source]){
                if(v == par)continue;
                sz += dfs(v, source);
            }
            if(rest[source]) return 0;
            return sz;
        };
        int ans = dfs(0, -1);
        return ans;
    }
};