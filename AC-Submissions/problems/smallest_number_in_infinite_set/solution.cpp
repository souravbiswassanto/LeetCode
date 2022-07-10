class SmallestInfiniteSet {
public:
    int cntr = 1;
    set<int> S;
    SmallestInfiniteSet() {
        cntr = 1;
        S.clear();
    }
    
    int popSmallest() {
        int a;
        if(S.size()){
            a = *S.begin();
            S.erase(a);
            return a;
        };
        return cntr++;
    }
    
    void addBack(int num) {
        if(num < cntr)S.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */