class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, set<int>> mp; // val -> ind
    int sz = 0, ind = 0, last_val = 0, flag = 0;
public:
    RandomizedCollection () {
        
    }
    
    bool insert(int val) {
        flag = 0;
        if(mp.find(val) == mp.end() || mp[val].size() == 0) flag = 1;
        nums.push_back(val);
        sz++;
        mp[val].insert(sz - 1);
        return flag;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end() || mp[val].size() == 0) return false;
        ind = *(--mp[val].end());
        last_val = nums[sz - 1];
        if(val == last_val) {
            mp[val].erase(--mp[val].end());
            nums.pop_back();
            sz--;
            return true;
        }
        nums[ind] = last_val;
        mp[val].erase(--mp[val].end());
        auto it = prev(mp[last_val].end());
        mp[last_val].erase(it);
        mp[last_val].insert(ind);
        nums.pop_back();
        sz--;
        return true;
    }
    
    int getRandom() {
        cout << sz << endl;
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

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */