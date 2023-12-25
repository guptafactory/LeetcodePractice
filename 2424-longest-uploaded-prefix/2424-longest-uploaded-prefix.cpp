class LUPrefix {
    int n = 0, len = 0;
    vector<bool> arr;
public:
    LUPrefix(int n) {
        arr.resize(n, 0);
        this->n = n;
    }
    
    void upload(int video) {
        arr[video - 1]  = true;
        while(len < n && arr[len]) len++;
    }
    
    int longest() {
        return len;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */