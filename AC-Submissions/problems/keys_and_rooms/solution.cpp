class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        bool vis[n]; 
        memset(vis, 0, sizeof vis);
        vis[0] = 1; q.push(0);
        while(!q.empty() ) {
            int u = q.front(); q.pop();
            for (auto v: rooms[u]) {
                if (vis[v]) continue;
                q.push(v);
                vis[v] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) return false;
        }
        return true;
    }
};