class LFUCache {
private:
    unordered_map<int, int> key_val;
    unordered_map<int, int> key_use;
    unordered_map<int, deque<int>> uses;
    int min_uses;
    int capacity;

    // Remove stale values from the uses[min_uses] deque
    void refreshCache() {
        while (!uses[min_uses].empty()) {
            int tmp_key = uses[min_uses].front();
            // Found a non-stale value, so refreshing done
            if (key_use[tmp_key] == min_uses) break;

            // This is a stale value - remove it from the deque
            uses[min_uses].pop_front();

            // uses[min_uses] was populated only by stale values, so remove it
            if (uses[min_uses].empty()) {
                uses.erase(min_uses);
                // Find the next candidate min_uses
                while (!uses.count(min_uses)) ++min_uses;
            }
        }
    }

public:
    LFUCache(int capacity): min_uses(INT_MAX), capacity(capacity) {}
    
    int get(int key) {
        // Key doesn't exist in cache
        if (!key_val.count(key)) return -1;

        ++key_use[key];
        uses[key_use[key]].push_back(key);

        return key_val[key];
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        // Prune the cache if at capacity and inserting a new value
        if (key_val.size() == capacity && !key_val.count(key)) {
            refreshCache();

            // Finished removing all stale values from the cache
            // We now know this value must be valid. Erase the value
            // With the minimum number of uses that was used last
            int to_remove = uses[min_uses].front();
            uses[min_uses].pop_front();
            key_val.erase(to_remove);
            key_use.erase(to_remove);
        }

        ++key_use[key];
        uses[key_use[key]].push_back(key);

        // If the number of uses of this newly insert key is a new minimum, update
        min_uses = min(min_uses, key_use[key]);

        key_val[key] = value;
    }
};
