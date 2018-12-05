We can use a hashmap to check if a character is already in the substring. If a character is already in the substring, we can continue to search from its index + 1. Because all index can search twice. Time complexity is O(n). We know characters are char type, and we can use a int[128] to replace a hashmap.
Time complexity O(n), Space complexity O(n)
