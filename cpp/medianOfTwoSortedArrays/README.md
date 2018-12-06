In a sorted n array and a sorted m array, their median is (((m + n + 1) / 2) + ((m + n + 2) / 2)) / 2.0. We can use binary search in both two arrays.  
1.If a starting point of a array more than its size, the kth number is in another array.  
2.If k is 1, and we can find the answer is min(num1[i], num2[j])  
3.ELSE, we can find k/2th number in array1 and array2, if mid1 < mid2, the kth number is in array2 after k/2th. Vice versa.

Time complexity O(log(m+n))
