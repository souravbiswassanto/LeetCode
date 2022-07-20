class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int> q;
        q.push(-1);
        int last = -1, n = intervals.size();
        vector<int> v;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            if(a <= q.top()){
                if(b > q.top()){
                    q.pop();
                    q.push(b);
                }
            }
            else{
                //cout << i << endl;
                int c = q.top();
                q.pop();
                if(c != -1){
                    v.push_back(last);
                    v.push_back(c);
                    ans.push_back(v); v.clear();
                }
                last = a;
                q.push(b);
            }
        }
        if(!q.empty()){
            v.push_back(last);
            v.push_back(q.top());
            ans.push_back(v);
        }
        return ans;
    }
};