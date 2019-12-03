// Source : https://leetcode.com/problems/insert-delete-getrandom-o1
// Author : Nan
// Date   : 2019-12-03
// Runtime: 52 ms

/*
* Use a hashmap and a vector. Swap the target val and the last val when delete.
*
* Time complexity O(1), Space complexity O(n)
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        m[v[v.size() - 1]] = m[val];
        v[m[val]] = v[v.size() - 1];
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    unordered_map<int, int> m;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */