class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.empty()){
            maxh.push(num);
        }
        else if(minh.empty()){
            int mx=maxh.top();
            if(num>=mx) minh.push(num);
            else{
                maxh.pop();
                minh.push(mx);
                maxh.push(num);
            }
        }
        else{
            int mn=minh.top(), mx=maxh.top();
            if(minh.size()==maxh.size()){
                if(num<=mn) maxh.push(num);
                else{
                    minh.pop();
                    maxh.push(mn);
                    minh.push(num);
                }
            }
            else{
                if(num<mx){
                    maxh.pop();
                    minh.push(mx);
                    maxh.push(num);
                }
                else minh.push(num);
            }
        }
    }
    
    double findMedian() {
        if(minh.size()==maxh.size()){
            double ans=0.0;
            int mn=minh.top(), mx=maxh.top();
            ans=(double)(mn+mx)/2;
            return ans;
        }
        else{
            return (double)maxh.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */