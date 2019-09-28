// Source : https://leetcode.com/problems/range-sum-query-mutable/
// Author : Nan
// Date   : 2019-09-28
// Runtime: 32 ms

/*
* Segment Tree.  
*
* Time complexity O(logn), Space complexity O(n)
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(n * 2);
        for (int i = n; i < n * 2; ++i) {
            tree[i] = nums[i - n];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    void update(int i, int val) {
        int diff = val - tree[i += n]; 
        tree[i] = val;
        while (i > 0) {
            tree[i / 2] = tree[i / 2] + diff;
            i /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (i += n, j += n; i <= j; i /= 2, j /= 2) {
            if (i % 2 == 1) sum += tree[i++];
            if (j % 2 == 0) sum += tree[j--];
        }
        return sum;
    }
    
private:
    int n;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */