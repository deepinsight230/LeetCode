class MyCalendar {
public:
    vector<pair<int, int>> arr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ans=true;
        if(arr.empty()){
            arr.push_back({start, end});
        }
        else{
            for(int i=0;i<arr.size();i++){
                int ss=arr[i].first;
                int ee=arr[i].second;
                if(!((start<ss && end<=ss) || (start>=ee && end>ee))){
                    ans=false;
                    break;
                }
            }
            if(ans==true) arr.push_back({start, end});
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */