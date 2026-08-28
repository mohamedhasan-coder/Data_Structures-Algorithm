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
## Capacity To Ship Packages Within D Days (1101.Leetcode):

<P>
  Difficulty: Medium

  A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500
</P>

### Solution: 

```
class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int Days = 1, load =0;
        for(int i = 0;i<weights.size();i++){
            if(weights[i] + load > cap){
                Days+=1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return Days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid = (low + high) / 2;
            int numberOfDays = findDays(weights, mid);
            if(numberOfDays <= days){
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
## Kth Missing Positive Number (1539. Leetcode): 

<P>
  Difficculty: Easy

  Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
 

Follow up:

Could you solve this problem in less than O(n) complexity?
</P>

### Solution (Brute Force): 

```
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        for(int x:arr){
            if(x<=k){
                k++;
            }
            else{
                break;
            }
        }
        return k;
        
    }
};
```

### Solution (Optimal): 

```
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid+1);
            if(missing < k){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return low + k;
    }
};
```
---
## Aggressive Cows : (Geeks For Geeks): 

<P> 
Difficulty: Medium 

  Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.

Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

Examples:

Input: arr[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.
Input: arr[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.
Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 108
2 ≤ k ≤ arr.size()
</P>

### Solution: 

```
class Solution {
  public:
    bool canWePlace(vector<int> &arr, int dist, int cows){
        int cntCows = 1;
        int last = arr[0];
        for(int i =0; i<arr.size();i++){
            if(arr[i] - last >= dist){
                cntCows++;
                last = arr[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int low = 1;
        int high = arr[n-1] - arr[0];
        while (low <= high){
            int mid = (low + high) / 2;
            if(canWePlace(arr,mid,k) == true){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};
```
---
## Allocate Books (Code 360):
<P> 
Difficulty: Medium 

  Problem statement
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.


You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 2
12 34 67 90
Sample Output 1:
113
Explanation of sample input 1:
All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
Sample Input 2:
5 4
25 46 28 49 24
Sample Output 2:
71
Explanation of sample input 2:
All possible ways to allocate the ‘5’ books to '4' students are:

25 | 46 | 28 | 49 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '46', '28', and '73'. So the maximum is '73'.

25 | 46 | 28 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '46', '77', and '24'. So the maximum is '77'.

25 | 46 28 | 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '74', '49', and '24'. So the maximum is '74'.

25 46 | 28 | 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '71', '28', '49', and '24'. So the maximum is '71'.

We are getting the minimum in the last case.

Hence answer is ‘71’.
Expected time complexity:
The expected time complexity is O(n * log(s)), where ‘n’ is the number of integers in the array ‘arr’ and ‘s’ is the sum of all the elements of ‘arr’.
Constraints:
2 <= 'n' <= 10 ^ 3
1 <= 'm' <= 10 ^ 3
1 <= 'arr[i]' <= 10 ^ 9
The sum of all arr[i] does not exceed 10 ^ 9.

Where ‘n’ denotes the number of books and ‘m’ denotes the number of students. ‘arr[i]’ denotes an element at position ‘i’ in the sequence.

Time limit: 1 second
</P>

### Solution: 

```
#include<bits/stdc++.h>
int countStudents(vector<int> &arr, int pages){
    int student = 1;
    long long pagesStudent = 0;
    for(int i = 0;i<arr.size();i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
            student += 1;
            pagesStudent = arr[i];
        }
    }
    return student;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if(students > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
```
---
## Spilt Array Largest Sum (410. Leetcode): 

<P> 
Difficulty: Hard
  Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
 

</P>

### Solution: 

```
class Solution {
public:
    int countStudents(vector<int> &arr, int pages){
    int student = 1;
    long long pagesStudent = 0;
    for(int i = 0;i<arr.size();i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
            student += 1;
            pagesStudent = arr[i];
        }
    }
    return student;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if(students > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
    }
};
```
---
## Painters partion Problem (Code Chef): 

<P>
  Difficulty: Medium 

You are given 
N
N boards of varying lengths, and 
k
k painters are available to paint these boards. Each painter takes the same amount of time to paint 1 unit of board length. A painter can only paint contiguous sections of boards, and each board must be painted by exactly one painter.

Your task is to determine the minimum time required to paint all the boards such that no painter paints more than a specific amount of length. You need to divide the boards into 
k
k contiguous parts in such a way that the maximum length painted by any painter is minimized.

Input Format
The first line contains the number of test cases, T.

The first line of each test case contains two integers, 
N
N (the number of boards) and 
k
k (the number of painters).
The second line of each test case contains 
N
N space-separated integers, where the 
i
i-th integer represents the length of the 
i
i-th board
Output Format
A single integer representing the minimum time required to paint all the boards, where the time is defined as the maximum time taken by any single painter to paint their assigned section of boards.
Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
10
5
1≤N≤10 
5
 
1
≤
k
≤
N
1≤k≤N
1
≤
a
[
i
]
≤
10
5
1≤a[i]≤10 
5
 
Sample 1:
Input
Output
3
4 2
10 20 30 40
5 3
10 10 10 10 10
6 1
5 10 15 20 25 30
60
20
105
Explanation:
Test Case 1: There are 4 boards with lengths [10, 20, 30, 40] and 2 painters. Optimal division will be [10, 20, 30] for one painter and [40] for the other. Maximum length painted by a painter = 60.
Test case 2: There are 5 boards with equal lengths [10, 10, 10, 10, 10] and 3 painters. Optimal division will be [10, 10], [10, 10], and [10]. Maximum length painted by a painter = 20.
Test case 3: Only one painter is available, so they must paint all boards. Total length = 5 + 10 + 15 + 20 + 25 + 30 = 105.
</P>

### Solution: 

```
#include <bits/stdc++.h>
using namespace std;

// Implement the painter_partition method here 
int countStudents(vector<int> &arr, int pages){
    int student = 1;
    long long pagesStudent = 0;
    for(int i = 0;i<arr.size();i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
            student += 1;
            pagesStudent = arr[i];
        }
    }
    return student;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if(students > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
int painter_partition(vector<int> &boards, int k){
    return findPages(boards, boards.size(), k);
}

int main() {
    // Write your code here
    int t;
    cin>>t;
    while(t--){
    int N, k;
    cin >> N >> k;
    vector<int> boards(N);
    for (int i = 0; i < N; i++)
        cin >> boards[i];

    cout << painter_partition(boards, k) << endl;
    }
    return 0;
}
```
---

## Minimize Max Distance of Adjacent Gas Stations (Geeks For Geeks) : 

<P>
  Difficulty: Hard 

  We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations is minimized. Find the smallest possible value of d. Find the answer exactly to 6 decimal places.

Note: stations sorted is in a strictly increasing order.

Examples:

Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
Constraint:
1 ≤ stations.size() ≤ 105
0 ≤ stations[i] ≤ 106
0 ≤ k ≤ 105


</P> 

### Solution (Brute Force): 

```
#include <bits/stdc++.h>
using namespace std;

// Class to solve the gas station placement problem
class GasStationSolver {
public:
    // Function to minimize the maximum distance after placing k gas stations
    long double minimiseMaxDistance(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // howMany[i]: extra stations between arr[i] and arr[i+1]

        // Place k gas stations one at a time
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            long double maxSection = -1;
            int maxInd = -1;

            // Find the segment with the current largest section length
            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double sectionLength = diff / (howMany[i] + 1.0);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            // Add a gas station in the largest segment
            howMany[maxInd]++;
        }

        // Find the final maximum distance after placing all gas stations
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howMany[i] + 1.0);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    GasStationSolver solver;
    long double ans = solver.minimiseMaxDistance(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}

```
### Solution (Better): 

```
#include <bits/stdc++.h>
using namespace std;

// Class to solve the gas station placement problem
class Solution {
public:
    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // Tracks how many stations in each segment
        priority_queue<pair<long double, int>> pq; // Max-heap

        // Initially insert all segments into the heap with their lengths
        for (int i = 0; i < n - 1; i++) {
            long double length = arr[i + 1] - arr[i];
            pq.push({length, i});
        }

        // Place k additional gas stations
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            auto top = pq.top();
            pq.pop();
            int segmentIndex = top.second;

            // Add a station to the segment and recompute its length
            howMany[segmentIndex]++;
            long double totalDist = arr[segmentIndex + 1] - arr[segmentIndex];
            long double newLen = totalDist / (howMany[segmentIndex] + 1);
            pq.push({newLen, segmentIndex});
        }

        // Final answer is the max segment length at the top of the heap
        return pq.top().first;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    Solution obj;
    long double ans = obj.minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

```
### Solution (Optimal): 

```
class Solution {
public:
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++) {
            long double gap = arr[i] - arr[i - 1];
            cnt += (int)(gap / dist);  // number of stations needed in this gap
        }
        return cnt;
    }

    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        long double low = 1e-6;
        long double high = 0;

        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(stations[i + 1] - stations[i]));
        }

        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, stations);

            if (cnt > k) {
                low = mid;   // need larger distance
            } else {
                high = mid;  // feasible, try smaller distance
            }
        }
        return (double)high;
    }
}; 
```
---
