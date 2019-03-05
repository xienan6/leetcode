DP. If two characters are not same, then think about insert = dp[i+1][j] + 1, delete = dp[i][j+1] + 1, replace = dp[i][j] + 1. And take minimum of them.  
Time complexity O(nm), Space complexity O(nm)