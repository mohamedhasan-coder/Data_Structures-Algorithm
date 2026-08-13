# BS ON ANSWERS:
---
## Square Root (Geeks For Geeks): 

<P>
  Difficulty: Easy

  Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number.

Examples:

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
Input: n = 1
Output: 1
Explanation: 1 is a perfect square, so its square root is 1.
Constraints:

1 ≤ n ≤ 3*104

</P>

### Solution: 

```
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int low = 0, high = n;
        int ans = 1;
        while(low <= high){
            int mid = (low + high) / 2;
            long long val = (mid*mid);
            if(val <= n){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};
```
---

## SQRT(X) (69.Leetcode): 

<P> 
Difficutly: Easy

  Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
</P>

### Solution: 

```
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1, high = x, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Use division instead of multiplication to avoid overflow
            if (mid <= x / mid) {
                ans = mid;       // mid is a valid candidate
                low = mid + 1;   // try to find a larger one
            } else {
                high = mid - 1;  // mid^2 > x, shrink the range
            }
        }
        return ans;
    }
};
```
---

