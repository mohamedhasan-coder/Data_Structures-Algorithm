# BS ON 1D Arrays: 
---
## Binary Search: (704. Leetcode): 

<p>
  Difficulty: Easy

  Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
</p>

### Solution: (Iterative Code): 

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target>nums[mid]){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
};
```

### Solution (Recursive Code) : 

```
class Solution {
public:
    int bs(vector<int>& nums, int low, int high, int target){
        if(low>high){
            return -1;
        }
        int mid = (low+high)/2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(target>nums[mid]){
            return bs(nums,mid+1,high,target);
        }
        return bs(nums,low,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return bs(nums,0,n-1,target);
    }
};
```
---
## Implement Lower Bound: (Geeks For Geeks): 

<P>
  Difficulty: Easy

  Given a sorted array arr[] (following 0-based indexing) and a number target, find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

Examples :

Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 4
Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7
Explanation: As no element in arr[] is greater than 100, return the length of array.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106
</P>

### Solution: 

```
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high) / 2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return ans;
    }
};
```
---
## Implement Upper Bound (Geeks For Geeks): 

<P>
  Difficulty: Easy

  Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

Examples :

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 6
Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7
Explanation: As no element in arr[] is greater than 100, return the length of array.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106
</P>

### Solution: 

```
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high) / 2;
            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return ans;
    }
};

```
---
## Search Insert Position: (35. Leetcode): 

<P>
  Difficulty: Easy

  Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
</P>

### Solution: 

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return ans;
    }
};
```
---
## Floor in sorted array (Geeks For Geeks): 

<P> 
Difficculty: Easy

  Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of floor of x, return the index of the last occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.
Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 11
Output: 4
Explanation: Largest Number less than or equal to 11 is 10, whose indices are 3 and 4. The index of last occurrence is 4.
Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
Output: -1
Explanation: No element less than or equal to 0 is found. So, output is -1.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
0 ≤ x ≤ arr[n-1]
</P>

### Solution:

```
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int ans = -1;
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] <= x){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

```
---
## Ceil in sorted array (Geeks For Geeks): 

<P> 
Difficculty: Easy

Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
Output: 2
Explanation: Smallest number greater than 5 is 8, whose index is 2.
Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 20
Output: -1
Explanation: No element greater than 20 is found. So output is -1.
Input: arr[] = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output: 0
Explanation: Smallest number greater than 0 is 1, whose indices are 0 and 1. The index of the first occurrence is 0.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
0 ≤ x ≤ arr[n-1]


</P>

### Solution:

```
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high) / 2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return ans;
    }
};
```
---
## 34. Find First and Last Position of Element in Sorted Array (Leetcode): 

<P> 
Difficculty: Medium

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
</P>

### Solution:

```
class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high) / 2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return ans;
    }
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high) / 2;
            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,target);
        int n = nums.size();
        if(lb == n || nums[lb] != target) return {-1,-1};
        return {lb, upperBound(nums,target) - 1};      
    }
};
```

### Solution: (Using Binary Search):

```
class Solution {
public:
    int firstOccuracne(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int first = -1;
        while(low<=high){
            int mid = (low+high) / 2;
            if(arr[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target){  
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
    return first;
    }
    int lastOccurance(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int last = -1;
        while(low<=high){
            int mid = (low+high) / 2;
            if(arr[mid] == target){
                last = mid;
                low = mid+1;
            }
            else if (arr[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
    return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccuracne(nums,target);
        if(first == -1) return {-1,-1};    
        int last = lastOccurance(nums,target);
        return{first,last};
    }
};
```
---
## Number of Occurance (Code 360): 

<P> 
difficulty: Moderate

  Problem statement
You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.



Find the total number of occurrences of 'x' in the array/list.



Example:
Input: 'n' = 7, 'x' = 3
'arr' = [1, 1, 1, 2, 2, 3, 3]

Output: 2

Explanation: Total occurrences of '3' in the array 'arr' is 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7 3
1 1 1 2 2 3 3


Sample Output 1:
2


Explanation For Sample Input 1:
In the given list, there are 2 occurrences of integer 3.


Sample Input 2:
 5 6
 1 2 4 4 5


Sample Output 2:
 0


Explanation For Sample Input 2:
In the given list, there are 0 occurrences of integer 6.


Expected time complexity:
The expected time complexity is O(log 'n').


Constraints:
1 <= n <= 10^4
1 <= arr[i] <= 10^9
1 <= x <= 10^9
Where arr[i] represents the element i-th element in the array/list.

Time Limit: 1sec
</P>

### Solution: 

```
#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1);
}
```
---
## Search in Roatated Sorted Array: 

<P> 
Difficulty: medium

  There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
</P>

### Solution: 

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target<=nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
}; 
```
---
## Search in Roated SOrted ARray (81. Leetcode): 

<P> 
Difficulty: Medium 

  There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
</P>

### Solution: 

```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high) / 2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++, high--;
                continue;
            }

            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                } 
                else{ 
                    low = mid+1;
                }
            }
            else{ 
                if(nums[mid]  <= target && target <= nums[high]){
                    low = mid+1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
```
---
## 153. Find Minimum in Rotated Sorted Array (Leetcode): 

<P> 
Diifculty: Medium 

  Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
</P>

### Solution:
```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            }
            else{
                high = mid-1; 
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
    }
};
```
### Solution: (Optimize): 

```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            }
            else{
                high = mid-1; 
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
    }
};
```
---
