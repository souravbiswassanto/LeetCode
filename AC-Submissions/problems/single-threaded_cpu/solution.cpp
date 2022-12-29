class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        vector<int> ans;
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        int cputime = 0, curtime = 0;
        for (int i = 0; i < n; i++) {
            if (cputime >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
            }
            else {
                if(pq.size()) {
                    cputime += pq.top().first;
                    ans.push_back(pq.top().second);
                    pq.pop();
                    i--; continue;
                }
                cputime = tasks[i][0] + tasks[i][1]; ans.push_back(tasks[i][2]);
            }
            
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
        
    }
};