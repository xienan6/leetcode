// Source : https://leetcode.com/problems/shuffle-an-array
// Author : Nan
// Date   : 2019-12-07
// Runtime: 212 ms

/*
* Knuth shuffle.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = arr;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }
private:
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */