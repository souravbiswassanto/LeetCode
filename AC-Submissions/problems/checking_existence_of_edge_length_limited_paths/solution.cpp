class Solution {
public:
    struct data{
        int u, v, cost, type, id;
        data(int a, int b, int c, int d, int e) {
            u = a; v = b; cost = c; type = d; id = e;
        }
        bool operator<(data other) const{
            if (cost == other.cost) return type < other.type;
            return cost < other.cost;
        }
        
    };
    int parent[100005];
    int findPar(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }
    
    void Union(int u, int v) {
        u = findPar(u); v = findPar(v);
        if (u != v) {
            if (rand() % 2==0) swap(u, v);
            parent[u] = v;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<data> offlineData;
        int nofe = edgeList.size();
        int nofq = queries.size();
        for (int i = 0; i < nofe; i++) {
            offlineData.push_back(data(edgeList[i][0], edgeList[i][1], edgeList[i][2], 2, i));
        }
        for (int i = 0; i < nofq; i++) {
            offlineData.push_back(data(queries[i][0], queries[i][1], queries[i][2], 1, i));
        }
        sort(offlineData.begin(), offlineData.end());
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        vector<bool> res(queries.size());
        for (int i = 0; i < offlineData.size(); i++) {
            
            if (offlineData[i].type == 1) {
                if (findPar(offlineData[i].u) != findPar(offlineData[i].v)) {
                    res[offlineData[i].id] = false;
                }
                else res[offlineData[i].id] = true;
            }
            else {
                Union(offlineData[i].u, offlineData[i].v);
            }
        }
        return res;
    }
};