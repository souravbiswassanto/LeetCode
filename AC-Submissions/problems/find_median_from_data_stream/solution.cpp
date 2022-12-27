class MedianFinder {
public:
    priority_queue<int> desc;
    priority_queue<int, vector<int>, greater<int>> asc;
    MedianFinder() {
        asc.push(INT_MAX);
        desc.push(INT_MIN);
    }
    
    void addNum(int num) {
        int mn = desc.top();
        int mx = asc.top();
        if (asc.size() == desc.size()) {
            if (num <= mx) desc.push(num);
            else {
                desc.push(asc.top());
                asc.pop();
                asc.push(num);
            }
        }
        else {
            if (mn <= num) asc.push(num);
            else {
                asc.push(desc.top());
                desc.pop();
                desc.push(num);
            }
        }
    }
    
    double findMedian() {
        if (desc.size() == asc.size()) return (double)(asc.top() + desc.top())/2.0;
        else return desc.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */