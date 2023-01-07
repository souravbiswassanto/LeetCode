class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int far = 0; int n = gas.size();
        int sum = 0;
        for (int i = 0; i < 2 * gas.size(); i++) {
            sum += (gas[i % n] - cost[i % n]);
            if (sum < 0) {
                sum = 0; far = 0;
            }
            else{
                far++;
            }
            if (far == cost.size()) {
                return (i - n + 1) % n;
            }
        }
        return -1;
    }
};