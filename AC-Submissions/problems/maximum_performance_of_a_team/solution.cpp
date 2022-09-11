class Solution {
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, maxPer = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--) {
            if (pq.size() != k) {
                sum += v[i].second;
                pq.push(v[i].second);
                maxPer = max(maxPer, sum * 1LL * v[i].first);
            }
            else {
                int temp = pq.top(); pq.pop();
                sum -= temp;
                sum += v[i].second;
                pq.push(v[i].second);
                maxPer = max(maxPer, sum * 1LL * v[i].first);
                if (pq.top() < temp) {
                    sum -= pq.top(); pq.pop();
                    sum += temp; pq.push(temp);
                }
            }
        }
        return maxPer % mod;
    }
};