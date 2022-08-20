class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int minStop = 0, curFuel = startFuel;
        int curPoint = 0;
        
        for (int i = 0; i < stations.size(); ++i) {
            while (!pq.empty() and curFuel < stations[i][0]) {
                curFuel += pq.top();
                pq.pop(); minStop ++;
            }
            pq.push(stations[i][1]);
            if (curFuel < stations[i][0]) return -1;
        }
        while (!pq.empty() and curFuel < target) {
            curFuel += pq.top();
            pq.pop(); minStop++;
        }
        if (curFuel < target) return -1;
        return minStop;
        
    }
};