class UndergroundSystem {
    // {id} -> {Start Station, Start time}
    unordered_map<int, pair<string, int>> mp;
    // {startName, endName} -> {vector of time taken}
    map<pair<string, string>, vector<int>> ans;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> pr = mp[id];
        ans[{pr.first, stationName}].push_back(t - pr.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = 0;
        int n = ans[{startStation, endStation}].size();
        for(int t: ans[{startStation, endStation}]) avg += t;
        return avg/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */