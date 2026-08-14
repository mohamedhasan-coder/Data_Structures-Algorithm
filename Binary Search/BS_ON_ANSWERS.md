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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to calculate total hours at given speed
    long long calculateTotalHours(vector<int>& piles, long long speed) {
        long long totalH = 0;
        for (int bananas : piles) {
            // integer ceil: (bananas + speed - 1) / speed
            totalH += (bananas + speed - 1) / speed;
        }
        return totalH;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxPile = *max_element(piles.begin(), piles.end());
        long long low = 1, high = maxPile;
        long long ans = maxPile;

        // Binary search on answer space
        while (low <= high) {
            // Safe mid calculation with long long
            long long mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                ans = mid;        // feasible speed
                high = mid - 1;   // try smaller speed
            } else {
                low = mid + 1;    // need larger speed
            }
        }
        return (int)ans; // final answer fits in int
    }
};

```
---
## 1482. Minimum Number of Days to Make m Bouquets (Leetcode): 

<P> 
Difficulty: Medium 

  You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
 

Constraints:

bloomDay.length == n
1 <= n <= 105
1 <= bloomDay[i] <= 109
1 <= m <= 106
1 <= k <= n
</P>

### Solution: 

```
class Solution {
public:
    bool possible(vector <int> &nums, int day, int m, int k){
        int n = nums.size();
        int cnt = 0;
        int noOfB = 0;
        for(int i = 0; i<n;i++){
            if(nums[i] <= day){
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1L;
        if(val > bloomDay.size()) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<bloomDay.size();i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low <= high){
            int mid = (low + high) / 2;
            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};
```
---
## 1283. Find the Smallest Divisor Given a Threshold (Leetcode): 

<P> 
Difficulty : Medium

  Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106
</P>

### Solution:

```
class Solution {
public:
     int sumByD(vector <int> &nums, int div){
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum = sum + ceil((double) (nums[i]) / (double) (div));
        }
        return sum;
     }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high) {
            int mid = (low  + high) / 2;
            if (sumByD(nums,mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
}; 
```
---
## 1283. Find the Smallest Divisor Given a Threshold (Leetcccode): 

<P>
  Difficculty: Medium

  Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106
</P>

### Solution: 

```
class Solution {
public:
     int sumByD(vector <int> &nums, int div){
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum = sum + ceil((double) (nums[i]) / (double) (div));
        }
        return sum;
     }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high) {
            int mid = (low  + high) / 2;
            if (sumByD(nums,mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
}; 
```
---
