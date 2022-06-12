class Solution {
public:
    int integerReplacement(int n) {
        map<long long, int> level;
        map<long long, bool> vis;
        
        function <long long(long long)> bfs = [&](long long source){
            level[source] = 0;
            queue<long long> Q;
            vis[source] = 1;
            Q.push(source);
            
            while(!Q.empty()){
                long u = Q.front();
                Q.pop();
                //cout << u <<" "<<level[u]<< endl;
                if(u == 1){
                    return level[u];
                }
                if(u % 2 == 0){
                    if(vis[u / 2])continue;
                    Q.push(u / 2);
                    vis[u / 2] = true;
                    level[u / 2] = level[u] + 1;
                }
                else{
                    if(vis.find(u + 1) == vis.end()){
                        Q.push(u + 1);
                        vis[u + 1] = true;
                        level[u + 1] = level[u] + 1;
                    }
                    if(vis.find(u - 1) == vis.end()){
                        Q.push(u - 1);
                        vis[u - 1] = true;
                        level[u - 1] = level[u] + 1;
                    }
                }
            }
            return level[1];
        };
        int ans = bfs(n);
        return ans;
    }
};