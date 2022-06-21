
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int> , greater<int>> pq; int cntr = 0;
       
        for(int i = 1; i < n; i++){
            if(heights[i] <= heights[i - 1])continue;

            if(pq.size() == ladders){
                int diff = heights[i] - heights[i - 1];
                int a ;
                if(ladders == 0)a = diff;
                else a = pq.top();
                if(a < diff){
                    bricks -= a;
                    pq.pop();
                    pq.push(diff);
                }
                else bricks -= diff;
            }
            else pq.push(heights[i] - heights[i - 1]);
            if(bricks < 0)return i - 1;
        }
        return n - 1;
    }
};