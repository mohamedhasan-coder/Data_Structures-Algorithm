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
## Find Nth Root of M (Geeks For Geeks): 

<P> 
Diifculty: Medium 

You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

Examples :

Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16
Constraints:
1 ≤ n ≤ 9
0 ≤ m ≤ 20
</P>

### Solution: 

```
class Solution {
public:
    int func(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid;
            if (ans > m) return -1; // too large
        }
        if (ans == m) return 0;     // exact match
        return 1;                   // too small
    }

    int nthRoot(int n, int m) {
        // Special case: m = 0 → root is 0
        if (m == 0) return 0;
        // Special case: m = 1 → root is 1
        if (m == 1) return 1;

        int low = 1, high = m;
        while (low <= high) {
            int mid = (low + high) / 2;
            int res = func(mid, n, m);

            if (res == 0) return mid;       // found exact root
            else if (res == 1) low = mid + 1; // need bigger mid
            else high = mid - 1;              // need smaller mid
        }
        return -1; // no integer root exists
    }
};

```
---
## Koko Eating Bananas (875. Leetcode): 

<P>
  Difficulty: medium

  Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
</P>

### Solution: 

```
 class Solution {
public:
int calculateTotalHours(vector<int>& piles, int speed) {
        int totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas / speed);
        }
        return totalH;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find maximum element
        int maxPile = *max_element(piles.begin(), piles.end());

        // Initialize low and high pointers
        int low = 1, high = maxPile;
        int ans = maxPile;

        // Binary search on answer space
        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(piles, mid);

            // If possible, try smaller speed
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, try larger speed
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```
---
