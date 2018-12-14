You only need to check the filled cells if they are valid. So we can design a hash to check in O(n^2) time. Notice that (i, j) cell is in No.(i / 3 * 3 + j / 3) 3x3 box, so we can use three hash refereed each 3x3 box, each row and each row.
Time complexity O(n^2), Space complexity O(n^2)
