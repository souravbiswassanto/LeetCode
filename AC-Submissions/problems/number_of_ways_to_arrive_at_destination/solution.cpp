class Solution {
public:
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll , ll>> g[n];
        int mod = 1e9 + 7;
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0], v = roads[i][1], w = roads[i][2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        long long dist[n];
        map<pair<ll, ll>, ll> M;
        function <void(int, int)> dijkstra = [&] (int source, int idx){
            for(int i = 0; i < n; i++)dist[i] = 1e14;
            priority_queue<pair<ll, ll>,vector<pair<ll, ll>>, greater<pair<ll, ll>> >pq;
            pq.push({0, source}); M[{source, 0}] = 1;
            dist[source] = 0;
            while(!pq.empty()){
                auto u = pq.top();
                pq.pop();
                if(u.first != dist[u.second])continue;
                for(auto v: g[u.second]){
                    if(u.first + v.second < dist[v.first]){
                        dist[v.first] = u.first + v.second;
                        pq.push({dist[v.first], v.first});
                        M[{v.first, dist[v.first]}] = (M[{v.first, dist[v.first]}] + M[{u.second, u.first}]) % mod;
                    }
                    else if(u.first + v.second == dist[v.first]){
                        M[{v.first ,dist[v.first]}] = (M[{v.first ,dist[v.first]}] + M[{u.second, u.first}]) % mod;
                    }
                    
                }
            }
        };
        
        dijkstra(0, 0);
        ll totcost = dist[n - 1];
        return M[{n - 1, totcost}];
        
        
    }
};