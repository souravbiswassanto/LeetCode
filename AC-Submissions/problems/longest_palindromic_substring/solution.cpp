class Solution {
#define ll long long
public:
    
    struct Manachar{
    
        int n;
        vector<int> P;
        Manachar(int _n){
            n = _n;
            P.resize(2 * n + 10, 0);
        }

        string convert(string& s){
            string nwS = "@";
            for (int i = 0; i < (int)s.size(); i++) {
                nwS += "#" + s.substr(i, 1);
            }
            nwS += "#$";
            return nwS;
        }

        void build(string& s){
            int _n = s.size();
            int l = 0, r = -1;
            for(int i = 1; i < (int)s.size() - 1; i++){
                int k;
                if(i > r){
                    k = 0;
                }
                else {
                    int j = r - i + l;
                    k = min (P[j], r - i);
                }
                while(i + k < _n and i - k >= 0 and s[i+k] == s[i-k])k++;
                if(s[i-k] != s[i+k])k--;
                P[i] = k;
                if(i + k > r){
                    r = i + k;
                    l = i - k;
                }
            }
        }
        string calculate(string& s, string original){
            int maxpal = 0;
            int idx = 0;
            for(int i = 1; i < s.size() - 1; i++){
                //cout << i <<" "<< s[i]<<" "<< P[i] << endl;
                if(P[i] > maxpal){
                    maxpal = P[i];
                    idx = i - P[i] ;
                    idx /= 2;
                }
            }
            //cout<<maxpal<<endl;
            //cout<<idx<<endl;
            string res = original.substr(idx,maxpal);
            return res;
        }

        string solve(string& s){
            string original = s;
            s = convert(s);
            build(s);
            return calculate(s, original);
        }
    };
    string longestPalindrome(string s) {
        int n = s.size();
        Manachar mchar(n);
        return mchar.solve(s);
        
    }
};