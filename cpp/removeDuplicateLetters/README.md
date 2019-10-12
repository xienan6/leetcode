1) Skip this round directly when the current character is already on the stack  
2) When the stack is empty or the current character is larger than the top character of the stack, it is directly pushed onto the stack.  
3) When the top character of the stack is larger than the current character, and the hash table knows that there is a character at the top of the stack, the condition 2 is continuously pushed out of the stack, and then the current character is pushed onto the stack.  
Time complexity O(n), Space complexity O(n)