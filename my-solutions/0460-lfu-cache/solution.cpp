class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyVal; // key -> {value, frequency}
    unordered_map<int, list<int>> freqList; // frequency -> list of keys
    unordered_map<int, list<int>::iterator> pos; // key -> position in freqList
public:
    LFUCache(int capacity) {
        this->capacity = capacity; // Initialize capacity
        this->minFreq = 0; 
    }
    
    int get(int key) {
        if (keyVal.find(key) == keyVal.end()) {
            return -1;
        }
        // Update frequency
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        // Update minFreq
        if (freqList[minFreq].empty()) {
            minFreq++;
        }
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyVal.find(key) != keyVal.end()) {
            // Key exists, update its value and frequency
            keyVal[key].first = value;
            get(key); // Reuse get to handle frequency update
            return;
        }

        if (keyVal.size() == capacity) {
            // Evict least frequently used key
            int delKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyVal.erase(delKey);
            pos.erase(delKey);
        }

        // Add new key
        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1; // Reset minFreq to 1
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
