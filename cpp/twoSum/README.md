The easy solution is use a O(n^2) run-time complexity method. However, we can use a map or a hashmap to store numbers and reduce run-time complexity to O(nlogn) or O(n) because a hashmap or a map can find the number = target - number[0] in O(logn) or O(1).  
Notice that nSum questions only need O(n-1) Time complexity. [3Sum](https://github.com/xienan6/leetcode/tree/master/cpp/3Sum/3Sum.cpp) and [4Sum](https://github.com/xienan6/leetcode/tree/master/cpp/4Sum/4Sum.cpp)  
Time complexity O(n), Space complexity O(n)
