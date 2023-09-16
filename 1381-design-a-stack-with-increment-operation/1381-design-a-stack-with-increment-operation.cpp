class CustomStack {
private:
    vector<int> arr;
    int sz;
public:
    CustomStack(int maxSize) {
        sz = maxSize;
    }
    
    void push(int x) {
        if(sz != arr.size()) arr.push_back(x);
    }
    
    int pop() {
        int n = arr.size();
        if(n == 0) return -1;
        int x = arr[n - 1];
        arr.pop_back();
        n--;
        return x;
    }
    
    void increment(int k, int val) {
        if(k > arr.size()) k = arr.size();
        for(int i = 0; i < k; i++) arr[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */