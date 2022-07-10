class Solution {
public:
    bool canChange(string start, string target) {
        int cntr = 0, cnt = 0;
        int n = start.size();
        string ns ="", ns2 = "";
        for(int i = 0; i < n; i++){
            if(start[i] != '_')ns += start[i];
            if(target[i] != '_')ns2 += target[i];
        }
        if(ns != ns2)return false;
        int pos[n + 4];
        for(int i = 0; i < n; i++){
            if(start[i] != '_'){
                pos[cntr++] = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(target[i] == 'L'){
                if(pos[cnt] < i)return false;
                cnt++;
            }
            if(target[i] == 'R'){
                if(pos[cnt] > i)return false;
                cnt++;
            }
        }
        return true;
    }
};