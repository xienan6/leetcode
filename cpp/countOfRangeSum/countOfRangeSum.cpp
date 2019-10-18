// Source : https://leetcode.com/problems/count-of-range-sum
// Author : Nan
// Date   : 2019-10-18
// Runtime: 36 ms

/*
* S(i,j)=sum(i)-sum(j). Use a stack to sort S(i,j) to S(i,0) and find the lower_bound and the upper_bound.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long>sums;//注意使用long long防止溢出
        long long sum = 0L;
        int result = 0;
        sums.insert(0);//插入第0个和
        for (size_t i = 0; i < nums.size(); i++){
            sum += nums[i];
            result += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));//找到满足sum[i]-upper=< sum[j]<= sum[i]-lower的范围
            sums.insert(sum);
        }
        return result;
    }
};