// Source : https://leetcode.com/problems/restore-ip-addresses/
// Author : Nan
// Date   : 2019-03-21
// Runtime: 4 ms

/*
* Recursion.           
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> index;
        generateIP(s, 0, res, index);
        return res;
    }
    void generateIP(string s, int pos, vector<string> &res, vector<int> index) {
        index.push_back(pos);
        int l = s.length();
        int ll = index.size();
        if (ll == 4 && isValid(s.substr(pos, l - pos))) {
            string r = "";
            for (int i = 0; i < 3; i++) {
                r = r + s.substr(index[i], index[i + 1] - index[i]) + ".";
            }
            r += s.substr(index[3], l - index[3]);
            res.push_back(r);
            return;
        }
        for (int j = 1; j <= 3 && pos + j < l && (5 - ll) * 3 >= l - pos; j++) {
            if (isValid(s.substr(pos, j))) {
                generateIP(s, pos + j, res, index);
            }
        }
    }
    bool isValid(string ip) {
        if (ip.length() > 1 && ip[0] == '0') return false;
        int a = atoi(ip.c_str());
        if(a >=0 && a <= 255) return true;
        return false;
    }
};