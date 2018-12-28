// Source : https://leetcode.com/problems/valid-number/
// Author : Nan
// Date   : 2018-12-27
// 1481 / 1481 test cases passed.
// Runtime: 16 ms

/*
* DFA. 
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
	bool isNumber(string s) {
		enum InputType {
			INVALID,		// 0 非法字符
			SPACE,		    // 1 空格
			SIGN,		    // 2 +-
			DIGIT,		    // 3 0-9
			DOT,			// 4 .
			EXPONENT,		// 5 eE
		};
		int transTable[][6] = {
		   //0,  1,  2,  3,  4,  5,
			-1,  0,  1,  2,  3, -1,//0初始无输入或者只有space的状态
			-1, -1, -1,  2,  3, -1,//1输入了符号状态
			-1,  4, -1,  2,  6,  5,//2输入了数字之后的状态
			-1, -1, -1,  6, -1, -1,//3前面无数字，只输入了Dot的状态
			-1,  4, -1, -1, -1, -1,//4前面有有效数输入之后，输入space的状态
			-1, -1,  8,  7, -1, -1,//5'e' or 'E'输入后的状态
			-1,  4, -1,  6, -1,  5,//6前面有dot和数字的状态（注意3.也是一个合法状态）
			-1,  4, -1,  7, -1, -1,//7输入e后输入数字的状态
			-1, -1, -1,  7, -1, -1,//8输入e之后输入Sign的状态
		};
		int state = 0, i = 0;
		while (i < s.length()) {
			InputType input = INVALID;
			if(s[i] == ' ') {
                input = SPACE;
            }
			else if(s[i] == '+' || s[i] == '-') {
                input = SIGN;
            }
			else if(isdigit(s[i])) {
                input = DIGIT;
            }
			else if(s[i] == '.') {
                input = DOT;
            }
			else if(s[i] == 'e' || s[i] == 'E') {
                input = EXPONENT;
            }
			state = transTable[state][input];
			if (state == -1) {
                return false;
            }
			i++;
		}
		return state == 2 || state == 4 || state == 6 || state == 7;
	}
};