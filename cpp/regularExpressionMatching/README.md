If you are stuck, recursion is your friend.  
But we can use a dp to solve this problem. There are three conditions. Assume that dp[i][j] is if s[0:i-1] and p[0:j-1] match.  
1.If p[j]!='*'  
    dp[i+1][j+1] = dp[i][j] && (s[i]==p[j] || p[j] == '.')  
2.If p[j]=='*' and match 0 character (like "aab" and "ac*ab")   
    dp[i+1][j+1] = dp[i+1][j-1]   
3.If p[j]=='*' and match at least 1 character (like "aaccb" and "ac*b")  
    dp[i+1][j+1] = dp[i][j+1] && (s[i]==p[j-1] || p[j-1] == '.')  
Notice that dp[0][0] = true and dp[0][j] = false.    
Time complexity O(mn), Space complexity O(mn). m, n are length of s and p.
