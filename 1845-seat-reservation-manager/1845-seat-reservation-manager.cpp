class SeatManager {
    set<int> unreserved;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) unreserved.insert(i);
    }

    int reserve() {
        int smallestSeatNumber = *unreserved.begin();
        unreserved.erase(unreserved.begin());
        return smallestSeatNumber;
    }

    void unreserve(int seatNumber) {
        unreserved.insert(seatNumber);
    }
};


/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */