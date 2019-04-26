// Source : https://leetcode.com/problems/gas-station/
// Author : Nan
// Date   : 2019-04-26
// Runtime: 8 ms

/*
* Because of unique anwser, we can traverse once and find anwser.   
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};