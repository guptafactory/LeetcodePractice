class SmallestInfiniteSet {
    set<int> st;
    void fill() {
        for(int i = 1; i <= 1000; i++) st.insert(i);
    }
public:
    SmallestInfiniteSet() {
        fill();
    }
    
    int popSmallest() {
        int x = *st.begin();
        st.erase(x);
        return x;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */