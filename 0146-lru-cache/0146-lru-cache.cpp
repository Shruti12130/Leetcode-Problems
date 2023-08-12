class LRUCache {
    int capacity;
    list<pair<int, int>> q;
    unordered_map<int, list<pair<int, int>>:: iterator> mp;
      
public:
      
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            //splice() function takes the element at the mp[key] and 
            //places it at the beginning of the list
            q.splice(q.begin(), q, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //1. Check if the key exists in the queue or not
        if(mp.find(key) != mp.end()) {
            //Then erase that key from that earlier position of queue
            q.erase(mp[key]);
        } else {
             //2. If the key does not exist in q, check if the cache size is full
            if(q.size() == capacity) {
                //Delete the least recently used key from the key and map
                //to make room for adding this new key
                int lruKey = q.back().first;
                mp.erase(lruKey);
                q.pop_back();
            }
        }
        
        //Add the key & value into the queue and the queue's front value into the map
        q.push_front({key, value});
        mp[key] = q.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */