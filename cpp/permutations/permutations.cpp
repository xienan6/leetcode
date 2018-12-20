// Source : https://leetcode.com/problems/permutations
// Author : Nan
// Date   : 2018-12-20
// 25 / 25 test cases passed.
// Runtime: 8 ms

/*
* Recursive
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result) {
		if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}   
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
    }
};