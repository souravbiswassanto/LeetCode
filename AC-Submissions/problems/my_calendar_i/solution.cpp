class MyCalendar {
public:
    set<pair<int, int>> S;
    MyCalendar() {
        S.insert({-1e9, -1e9});
        S.insert({2e9, 2e9});
    }
    
    bool book(int start, int end) {
        end--;
        auto it = S.upper_bound({start, end});
        auto it1 = --it;
        auto it2 = ++it;
        int upright = it1->second;
        int downleft = it2->first;
        
        if(start > upright and end < downleft){
            S.insert({start, end});
            return true;
        }
        vector<pair<int, int>> v;
        int mx = INT_MIN;
        int mn = INT_MAX;
        
        if(it1->second >= start)it = it1;
        mx = it->second;
        mn = it->first;
        for(auto iter = it; iter != S.end(); ++iter){
            if(mx >= iter->first){
                mn = min(mn, iter->first);
                mx = max(mx, iter->second);
            }
            else break;
            v.push_back({iter->first, iter->second});
        }
        for (auto pr: v){
            S.erase(pr);
        }
        S.insert({mn, mx});
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */