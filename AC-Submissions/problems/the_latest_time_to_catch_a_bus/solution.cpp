class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size();
        int m = passengers.size();
        int time  ;
        int cntr = 0, cnt = 0;
        int res = -1;
        for(int i = 0; i < n; i++){
            cnt = 0;
            while(cntr < m and cnt < capacity and buses[i] >= passengers[cntr]){
                cntr++; cnt++;
            }
            if(i == n - 1 and cnt != capacity and cntr < m and passengers[cntr] - 1 == buses[i])cntr++;
            if(i == n - 1 and cnt != capacity){
                res = buses[n - 1];
                while(binary_search(passengers.begin(), passengers.end(), res))res--;
            }
            //cout << i <<" " << cntr << endl;
        }
        if(res != -1)return res;
        //cout << cntr << endl;
        for(int i = 0; i < cntr; i++){
            if(!binary_search(passengers.begin(), passengers.end(), passengers[i] - 1)){
                time = passengers[i] - 1;
            }
        }
        if(cntr == 0){
            time = buses[n - 1];
        }
        return time;
    }
};