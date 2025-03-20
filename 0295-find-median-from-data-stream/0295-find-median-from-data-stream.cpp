class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    MedianFinder() {
    }
    
    void addNum(int num) {
        max.push(num);
        min.push(max.top());
        max.pop();
        if(min.size()>max.size()){
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        double ans=0;
        if(max.size()>min.size()) return (double)max.top();
        else return (double)(max.top()+min.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */