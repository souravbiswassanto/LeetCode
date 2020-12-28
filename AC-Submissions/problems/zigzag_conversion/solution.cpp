class Solution {
public:
    string convert(string s, int numRows) {
        string S[numRows];
        int cntr = 0, cnt, n = s.size();
        for(int i = 0; i < numRows; i++)S[i] = "";
        for(int i = 1;cntr < n ; i++){
            
            if(i%2){
                cnt = 0;
                while(cntr < n and cnt < numRows){
                    S[cnt++]+=s[cntr++];
                    //cout<<s[cntr-1]<<" ";
                }
               // cout<<endl;
            }
            else{
                    cnt = numRows - 2;
                    while(cntr < n and cnt >= 1){
                         S[cnt--]+=s[cntr++];
                        //cout<<s[cntr-1]<<" ";
                     }
               // cout<<endl;
                }
        }
        s ="";
        for(int i = 0; i < numRows; i++) s+=S[i];
        return s;
    }
};