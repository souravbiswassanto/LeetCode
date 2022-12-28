class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq; int sum = 0, rem = 0;
        for (int i = 0; i < piles.size(); i++) {
            pq.push(piles[i]); sum += piles[i];
        }
        int steps = 0;
        while(steps < k and !pq.empty()) {
            int a = pq.top();
            pq.pop();
            if (a == 1) break;
            rem += a / 2;
            pq.push(a - a/2);
            steps++;
        }
        return sum - rem;
    }
};