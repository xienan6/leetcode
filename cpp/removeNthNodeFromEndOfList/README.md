You can sort the array firstly. Then traverse the array, and use two pointer from start and end. Because of sorted already, you can find all answer in O(n^3) time. You can use some tricks to reduce time.  
Notice that nSum questions only need O(n-1) Time complexity. [2Sum](https://github.com/xienan6/leetcode/tree/master/cpp/twoSum/twoSum.cpp) and [3Sum](https://github.com/xienan6/leetcode/tree/master/cpp/3Sum/3Sum.cpp)  
Time complexity O(n^3), Space complexity O(1)
