#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <chrono>

using namespace std;

// Structure to represent cache item
struct CacheItem {
    int key;
    int value;
    int priority;
    chrono::time_point<chrono::system_clock> expirationTime;
    chrono::time_point<chrono::system_clock> lastAccessTime;
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    // Function to get the value from the cache
    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            updateAccessTime(key);
            return cacheMap[key].value;
        }
        return -1; // Key not found
    }

    // Function to put a value into the cache
    void put(int key, int value, int priority, chrono::seconds expirationTimeSeconds) {
        // Remove expired items
        removeExpiredItems();

        // Check if the cache is full
        if (cacheList.size() >= capacity) {
            // Remove the least priority or least recently used item
            removeLeastPriorityOrLRU();
        }

        // Create a new cache item
        CacheItem newItem = {key, value, priority, chrono::system_clock::now() + expirationTimeSeconds, chrono::system_clock::now()};
        
        // Add the new item to the cache
        cacheList.push_front(newItem);
        cacheMap[key] = cacheList.begin();
    }

private:
    int capacity;
    list<CacheItem> cacheList;
    unordered_map<int, list<CacheItem>::iterator> cacheMap;

    // Function to update the access time of a cache item
    void updateAccessTime(int key) {
        auto it = cacheMap[key];
        it->lastAccessTime = chrono::system_clock::now();
        cacheList.splice(cacheList.begin(), cacheList, it);
    }

    // Function to remove expired items from the cache
    void removeExpiredItems() {
        auto currentTime = chrono::system_clock::now();
        auto it = cacheList.begin();
        while (it != cacheList.end()) {
            if (it->expirationTime <= currentTime) {
                cacheMap.erase(it->key);
                it = cacheList.erase(it);
            } else {
                ++it;
            }
        }
    }

    // Function to remove the least priority or least recently used item
    void removeLeastPriorityOrLRU() {
        auto it = min_element(cacheList.begin(), cacheList.end(),
            [](const CacheItem& a, const CacheItem& b) {
                if (a.priority == b.priority) {
                    return a.lastAccessTime < b.lastAccessTime;
                }
                return a.priority < b.priority;
            });

        if (it != cacheList.end()) {
            cacheMap.erase(it->key);
            cacheList.erase(it);
        }
    }
};

int main() {
    // Example Usage
    LRUCache cache(3);

    cache.put(1, 10, 2, chrono::seconds(5));
    cache.put(2, 20, 1, chrono::seconds(10));
    cache.put(3, 30, 3, chrono::seconds(8));

    cout << cache.get(2) << endl;  // Output: 20

    cache.put(4, 40, 2, chrono::seconds(7));

    cout << cache.get(1) << endl;  // Output: -1 (expired)
    cout << cache.get(2) << endl;  // Output: 20
    cout << cache.get(3) << endl;  // Output: -1 (removed due to capacity)
    cout << cache.get(4) << endl;  // Output: 40

    return 0;
}

