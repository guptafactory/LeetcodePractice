class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> mp; // val -> ind
    int sz = 0, ind = 0, last_val;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        nums.push_back(val);
        sz++;
        mp[val] = sz - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        ind = mp[val];
        last_val = nums[sz - 1];
        nums[ind] = last_val;
        mp[last_val] = ind;
        mp.erase(val);
        nums.pop_back();
        sz--;
        return true;
    }
    
    int getRandom() {
        return nums[rand() % sz];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */