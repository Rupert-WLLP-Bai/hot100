#include "stdcc.h"

class LFUCache {
  public:
    LFUCache(int capacity) : capacity(capacity), minFrequency(1), currentSize(0) {}

    int get(int key) {
        auto it = keyValue.find(key);
        if (it == keyValue.end()) {
            return -1;
        }
        updateFrequency(key);
        return it->second.first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        auto it = keyValue.find(key);
        if (it != keyValue.end()) {
            it->second.first = value; // Direct update without second lookup
            updateFrequency(key);
        } else {
            if (currentSize == capacity) {
                evict();
            }
            keyValue[key] = {value, 1};
            frequencyList[1].push_back(key);
            keyIterators[key] = prev(frequencyList[1].end()); // Store iterator
            keyFrequency[key] = 1;
            minFrequency = 1;
            currentSize++;
        }
    }

  private:
    int capacity;
    unordered_map<int, pair<int, int>> keyValue;
    unordered_map<int, list<int>> frequencyList;
    unordered_map<int, list<int>::iterator> keyIterators; // O(1) removal
    unordered_map<int, int> keyFrequency;
    int minFrequency;
    int currentSize;

    void updateFrequency(int key) {
        int freq = keyFrequency[key];

        // O(1) removal using stored iterator
        frequencyList[freq].erase(keyIterators[key]);

        int newFreq = ++keyFrequency[key];
        frequencyList[newFreq].push_back(key);
        keyIterators[key] = prev(frequencyList[newFreq].end());

        if (frequencyList[freq].empty()) {
            frequencyList.erase(freq);
            if (minFrequency == freq) {
                minFrequency = newFreq; // Direct increment
            }
        }
    }

    void evict() {
        int keyToEvict = frequencyList[minFrequency].front();
        frequencyList[minFrequency].pop_front();

        if (frequencyList[minFrequency].empty()) {
            frequencyList.erase(minFrequency);
        }

        keyValue.erase(keyToEvict);
        keyFrequency.erase(keyToEvict);
        keyIterators.erase(keyToEvict);
        currentSize--;
    }
};
