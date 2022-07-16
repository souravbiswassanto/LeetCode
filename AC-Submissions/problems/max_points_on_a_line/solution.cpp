class Solution {
public:
    bool isdegenrated_triangle(int ax,int ay, int bx, int by, int cx, int cy){
        int res = ax*(by-cy)+bx*(cy-ay) + cx*(ay-by);
        //cout<<res<<" res"<<endl;
        return res == 0?1:0;
    }
    int maxPoints(vector<vector<int>>& points) {
        int mx = 2;
        if(points.size() == 1)return 1;
        for(int i = 0; i < points.size(); i++){
           map<pair<int, int>, int> M;
           for(int j = 0; j < points.size(); j++){
               int cntr = 0; if(i == j)continue;
               
               int x = points[i][0];
               int y = points[i][1];
               
               int x1 = points[j][0];
               int y1 = points[j][1];
               
               int g = __gcd(x - x1, y - y1);
               int a = (y - y1)/g;
               int b = (x - x1)/g;
               M[{a,b}]++;
           }
            for(auto it: M){
                mx = max(mx, it.second + 1);
            }
        }
        
        return mx;
    }
};