class MyHashSet {
    vector<list<int>> m;
    int n = 10000;
public:
    MyHashSet() {
        m.resize(n);
    }
    
    void add(int key) {
        int k = key % n;
        auto it = find(m[k].begin(), m[k].end(), key);

        if (it == m[k].end())
            m[k].push_back(key);
    }
    
    void remove(int key) {
        int k = key % n;
        auto it = find(m[k].begin(), m[k].end(), key);

        if (it != m[k].end()) {
            m[k].erase(it);
        }
    }
    
    bool contains(int key) {
        int k = key % n;
        auto it = find(m[k].begin(), m[k].end(), key);
        return it != m[k].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */