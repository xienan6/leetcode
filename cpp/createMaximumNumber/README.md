Step1: pick out k numbers from an array to form the largest number.  
Step2: compare two arrays until they compare size.  
Step3: divide the k numbers into two parts, i and k-i, and we can use the function in the first step to find the maximum lengths of i and k-i in the two arrays. Then use the second step to fuse them. Finally we find the maximum from all the results.  
Time complexity O(nk^2), Space complexity O(k^2)