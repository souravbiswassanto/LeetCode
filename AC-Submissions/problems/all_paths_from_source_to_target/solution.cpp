class Solution {
public:
    vector<vector<int>> result;
    vector<int> v;
    void backtrack(int source, int destination, vector<vector<int>>& graph) {
        if(source == destination) {
            result.push_back(v);return;
        }
        for (auto u: graph[source]) {
            v.push_back(u);
            backtrack(u, destination, graph);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        v.push_back(0);
        backtrack(0, graph.size() - 1, graph);
        return result;
    }
};