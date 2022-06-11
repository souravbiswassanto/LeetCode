class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = mappings.size();
        
        int A[200][200];
        for(int i = 0; i < 200; i++){
            for(int j = 0; j < 200; j++)A[i][j]= 0;
        }
        for(int i = 0; i < n; i++){
            int a = mappings[i][0]; 
            int b = mappings[i][1];
            
            A[a][b] = 1;
        }
        bool check = false;
        for(int i = 0; i <= s.size() - sub.size(); i++){
            int cntr = 0;
            for(int j = 0; j < sub.size(); j++){
                if(s[i + j] == sub[j]){
                    cntr++; continue;
                }
                int a = sub[j];
                int b = s[i + j];
                if(A[a][b])cntr++;
            }
            if(cntr == sub.size()){
                check = true; break;
            }
        }
        return check;
    }
};