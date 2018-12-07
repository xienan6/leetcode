Brute force use O(n^3) time complexity.
We can traverse each point to search both sides until they are not equal. We can also use a dp, dp[i][j] = s[i]==s[j] && dp[i+1][j-1]. Time complexity is O(n^2)
The best algorithm is O(n) called Manacher's algorithm. Time complexity is O(n). [Here in detail](https://articles.leetcode.com/longest-palindromic-substring-part-ii/)
Here I use Manacher's algorithm.

Time complexity O(n), Space complexity O(n)
