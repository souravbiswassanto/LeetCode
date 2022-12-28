class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> combined;
        priority_queue<int> pq;
        for (int i = 0; i < profits.size(); i++) {
            combined.push_back({capital[i], profits[i]});
        }
        sort(combined.begin(), combined.end());
        for (int i = 0; i < combined.size(); i++) {
            if (w >= combined[i].first) {
                pq.push(combined[i].second);
            }
            else if(pq.size() and k) {
                w += pq.top(); pq.pop(); k--; i--;
            }
            else break;
        }
        while(k and pq.size()) {
            w += pq.top(); pq.pop(); k--;
        }
        
        return w;
    }
};