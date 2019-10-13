first situation: There are only two frequencies( A and B) of numbers appearing in prefixes,where A=B+1 and only one digit's frequency is A.  
in this situation, we can remove one of the digits whose frequency is A.  
  
second situation: There are only two frequencies( A and B) of numbers appearing in prefixes,where A=1 and B≠1 and only one digit's frequency is A.  
in this situation, we can remove the digit whose frequency is 1.  
  
third situation: All digits in nums appear only one.  
in this situation, we can remove any of digit to get the ans.  
  
fourth situation: All digits in nums are the same.  
in this situation, we can remove any of digit to get the ans.  
Time complexity O(n), Space complexity O(1)