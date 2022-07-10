class Solution {
public:
    int fillCups(vector<int>& amount) {
        multiset<int, greater<int>> S;
        for(auto it: amount)if(it)S.insert(it);
        int sum = 0;
        while(S.size() > 1){
            auto it = S.begin();
            auto it1 = ++S.begin();
            sum++;
            int a = *it - 1;
            int b = *it1 - 1;
            S.erase(it);
            S.erase(it1);
            if(a)S.insert(a);
            if(b)S.insert(b);
        }
        
        if(S.size() == 1){
            sum += *S.begin();
        }
        return sum;
    }
};