class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> storage;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (storage.find(key) == storage.end()) return "";

        int l = 0;
        int r = storage[key].size() - 1;
        int s = -1;

        while (r >= l) {
            int m = l + (r-l)/2;
            int midTimestamp = storage[key][m].first;
            if (midTimestamp == timestamp) return storage[key][m].second;
            else if (midTimestamp > timestamp) r=m-1;
            else {
                l=m+1;
                s = m;
            }
        }

        if (s == -1) return "";

        return storage[key][s].second;
    }
};
