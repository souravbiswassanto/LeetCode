class Solution {
#define pb push_back
vector<string> vp;
vector<int> dig;
int ans[4];
vector<char> V[12];
void fun(int i, int n){
    if(i == n){
        string s ="";
        for(int j = 0; j < n; j++){
            s += V[dig[j]][ans[j]];
        
        }
        if(s.size())vp.pb(s);
        return;
    }
    
    for(int j = 0; j < V[dig[i]].size(); j++){
        ans[i] = j;
        fun(i + 1, n);
    }
}
public:
    vector<string> letterCombinations(string digits) {
        
        
        for(int i = 0; i < digits.size(); i++){
            dig.pb(digits[i] - '0');
        }
        
        int j =  2, n = digits.size();
        for(int i = 0; i < 15; i++){
            V[j + (i/3)].pb(char(i + 97));
        }
        for(int i = 15; i < 19; i++){
            V[7].pb(char(i + 97));
        }
        for(int i = 19; i < 22; i++){
            V[8].pb(char(i + 97));
        }
        for(int i = 22; i < 26; i++){
            V[9].pb(char(i + 97));
        }
        fun(0, n);
        /*
        do{
            fun(0, n);
        }
        while(next_permutation(dig.begin(), dig.end()));
        */
       
        return vp;
    }
};