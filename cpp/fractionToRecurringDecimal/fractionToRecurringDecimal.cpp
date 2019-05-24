// Source : https://leetcode.com/problems/fraction-to-recurring-decimal/
// Author : Nan
// Date   : 2019-05-24
// Runtime: 0 ms

/*
* Use a hashmap to store remainder that has appeared.  
*
* Time complexity O(-), Space complexity O(-)
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result;
        if (numerator < 0 ^ denominator < 0) result = '-';
        long long n = numerator, d = denominator;
        n = abs(n);
        d = abs(d);
        result += to_string(n / d);
        long long r = n % d;
        if (r == 0) return result;
        else result += '.';
        unordered_map<int, int> map;
        while (r) {
            if (map.find(r) != map.end()) {
                result.insert(map[r], 1, '(');
                result += ')';
                break;
            }
            map[r] = result.size();
            r *= 10;
            result += to_string(r / d);
            r %= d;
        }
        return result;
    }
};