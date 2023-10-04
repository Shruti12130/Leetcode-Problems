class MyHashMap {
public:
    unordered_map<int, int> mp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        mp[key]=value;
    }
    
    int get(int key) {
        int value;
        if(mp.find(key)==mp.end()) {
            value=-1;
        } else {
            value = mp[key];
        }
        return value;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */