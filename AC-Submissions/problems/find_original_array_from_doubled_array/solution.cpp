class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        priority_queue<int> pq;
        int n = changed.size();
        vector<int> res;
        sort(changed.rbegin(), changed.rend());
        for (int i = 0; i < n; ++i) {
            if (pq.size() == 0) {
                pq.push(changed[i]);
            }
            else {
                if (pq.top() == changed[i] * 2) {
                    res.push_back(changed[i]);
                    pq.pop();
                }
                else pq.push(changed[i]);
            }
        }
        if (pq.size()) res.clear();
        return res;
    }
};