# Easy Problems on Array: 
---
## Largest in Array (GFG): 

  Difficulty: Basic  

  Given an array arr[]. The task is to find the largest element and return it.  

Examples: 

Input: arr[] = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.
Input: arr[] = [5, 5, 5, 5]
Output: 5
Explanation: The largest element of the given array is 5.
Input: arr[] = [10]
Output: 10
Explanation: There is only one element which is the largest.
Constraints:
1 <= arr.size()<= 106
0 <= arr[i] <= 106

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

### Solution: 

```
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int largest = arr[0];
        int n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] > largest)
            {
                largest = arr[i];
            }
        }
        return largest;
    }
};
```

---
## Second Largest (GFG): 

<P>
  Difficulty: Easy

  Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
</P>

### Solution: 

```
class Solution {
  public:
  
    int secondLargest(vector<int> &arr, int n){
        int largest = arr[0];
        int slargest = -1;
        for(int i=1;i<n;i++)
        {
            if(arr[i] > largest)
            {
            slargest = largest;
            largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > slargest)
            {
                slargest = arr[i];
            }
        }
        return slargest;
    }
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int slargest = secondLargest(arr, n);
    } 
};

```
---
## Check if Array Is Sorted and Roated (1752.Leetcode):

<P>
  Difficulty: Easy

  Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
</P>

### Solution: 

```
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};
```
---
## Remove Duplicates From Sorted Array (26.Leetcode): 

<P>
  Difficulty: Easy

  Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
</P>

### Solution: 

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for(int j=1;j<n;j++)
        {
            if(nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i+1;
    }
};
```
---
## Left Roatate Array By One (Code Ninja): 

<P>
  Difficulty: Easy
  Problem statement
Given an array 'arr' containing 'n' elements, rotate this array left once and return it.



Rotating the array left by one means shifting all elements by one place to the left and moving the first element to the last position in the array.



Example:
Input: 'a' = 5, 'arr' = [1, 2, 3, 4, 5]

Output: [2, 3, 4, 5, 1]

Explanation: We moved the 2nd element to the 1st position, and 3rd element to the 2nd position, and 4th element to the 3rd position, and the 5th element to the 4th position, and move the 1st element to the 5th position.
Detailed explanation ( Input/output format, Notes, Images )
Sample input 1:
4
5 7 3 2 
Sample output 1:
7 3 2 5
Explanation of sample input 1:
Move the first element to the last and rest all the elements to the left.
Sample input 2:
5
4 0 3 2 5 
Sample output 2:
0 3 2 5 4
Explanation of sample input 2:
Same as sample input 1, Move the first element to the last and rest all the elements to the left
Expected time complexity:
O( n ), Where ‘n’ is the size of an input array ‘arr’.
Constraints :
1 <= 'n' <= 10^5
1 <= 'arr[i] <= 10^9

Time Limit: 1 sec
</P>

### Solution: 

```
#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int temp = arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}

```
---
## Left Rotate Array by K Places(Code Ninja): 

<P>
  Difficulty: Easy
  Problem statement
Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.



Example:
'arr '= [1,2,3,4,5]
'k' = 1  rotated array = [2,3,4,5,1]
'k' = 2  rotated array = [3,4,5,1,2]
'k' = 3  rotated array = [4,5,1,2,3] and so on.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
8
7 5 2 11 2 43 1 1
2
Sample Output 1:
2 11 2 43 1 1 7 5
Explanation of Sample Input 1:
Rotate 1 steps to the left: 5 2 11 2 43 1 1 7
Rotate 2 steps to the left: 2 11 2 43 1 1 7 5
Sample Input 2:
4
5 6 7 8
3
Sample Output 2:
8 5 6 7
Explanation of Sample Input 2:
Rotate 1 steps to the left: 6 7 8 5
Rotate 2 steps to the left: 7 8 5 6
Rotate 2 steps to the left: 8 5 6 7
Expected Time Complexity:
O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.
Constraints:
1 <= 'n' <= 10^3
1 <= 'arr'[i] <= 10^9
1 <= 'k' < 'n'


Hints:
1. For an index ‘i’, find where it lands after k swaps.
2. When performing rotation once observe how the positions of all elements change.
</P>

### Solution: 

#### Brute Force Approach: 
```
class Solution {
public:
    void rotateLeft(int arr[], int n, int k) {
        if (n == 0) return;

        k = k % n;

        int temp[k];
        for (int i = 0; i < k; i++) {
            temp[i] = arr[i];
        }

        for (int i = k; i < n; i++) {
            arr[i - k] = arr[i];
        }

        for (int i = 0; i < k; i++) {
            arr[n - k + i] = temp[i];
        }
    }
};

```
#### Optimal Approach: 

```
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();
    
    k = k % n; 
    
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
    
    return arr;
}
```
---
## Move Zeroes (258.Leetcode):

<P>
  Diffculty: Easy
  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 
</P>

### Solution: 

#### Brute Force Solution: 

```
class Solution {
public:
    vector<int> moveZeroes(vector<int>& arr) {
        vector<int> temp(arr.size(), 0);

        int index = 0;

        for (int i = 0; i < arr.size(); i++) {
            // If non-zero, add to temp
            if (arr[i] != 0) {
                temp[index] = arr[i];
                index++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        }

        return arr;
    }
};
```
#### Optimal Approach: 

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;

        for (int i =0; i<n;i++)
        {
            if(nums[i] == 0)
            {
                j=i;
                break;
            }
        }

        if(j == -1) return;

        for(int i = j+1; i<n;i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return;
    }
};
```
---
## Linear Search: (GFG): 

<P>
  Difficulty: Basic
  Given an array, arr[] of n integers, and an integer element x, find whether element x is present in the array. Return the index of the first occurrence of x in the array, or -1 if it doesn't exist.

Examples:

Input: arr[] = [1, 2, 3, 4], x = 3
Output: 2
Explanation: For array [1, 2, 3, 4], the element to be searched is 3. Since 3 is present at index 2, the output is 2.
Input: arr[] = [10, 8, 30, 4, 5], x = 5
Output: 4
Explanation: For array [10, 8, 30, 4, 5], the element to be searched is 5 and it is at index 4. So, the output is 4.
Input: arr[] = [10, 8, 30], x = 6
Output: -1
Explanation: The element to be searched is 6 and it is not present, so we return -1.
Constraints:
1 ≤ arr.size ≤ 106
0 ≤ arr[i] ≤ 106
0 ≤ x ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
</P>

### Solution: 

```
class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
};
```
---
## Union of Two Sorted Arrays (GFG): 

<P>
  Difficulty: Medium

  Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: [1, 2, 3, 4, 5]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  ≤  a.size(), b.size()  ≤  105
-109 ≤ a[i], b[i] ≤109

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(1)
</P>

### Solution:

```
class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0, j = 0;
        vector<int> unionArr;

        while (i < n1 && j < n2)
        {
            if (a[i] <= b[j])
            {
                if (unionArr.size() == 0 || unionArr.back() != a[i])
                    unionArr.push_back(a[i]);
                i++;
            }
            else
            {
                if (unionArr.size() == 0 || unionArr.back() != b[j])
                    unionArr.push_back(b[j]);
                j++;
            }
        }

        while (i < n1)
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
                unionArr.push_back(a[i]);
            i++;
        }

        while (j < n2)
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
                unionArr.push_back(b[j]);
            j++;
        }

        return unionArr;
    }
};
```
---
## Intersection of Two Sorted Arrays: 

<P>
  Difficulty: Medium

  Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the intersection of the two arrays in sorted order.

Intersection of two arrays can be defined as the set containing distinct common elements that are present in both of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3
Explanation: Distinct elements in both the arrays are: 1 2 3.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: 2 3 4
Explanation: Distinct elements in both the arrays are: 2 3 4.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: []
Explanation: No common elements.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(n)

</P>

### Solution: 

```
class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int n1 = a.size();
        int n2 = b.size();
        
        int i = 0, j = 0;
        vector<int> ans;
        
        while(i < n1 && j < n2) {
            
            if(a[i] < b[j]) {
                i++;
            }
            else if(a[i] > b[j]) {
                j++;
            }
            else {
                if(ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};
```
---
## Sort an Array (912.Leetcode): 

<P>
  Difficulty: Medium 

  Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
</P>

### Solution: 

```
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(int, int)> quick_sort = [&](int l, int r) {
            if (l >= r) {
                return;
            }
            int i = l - 1, j = r + 1;
            int x = nums[(l + r) >> 1];
            while (i < j) {
                while (nums[++i] < x) {
                }
                while (nums[--j] > x) {
                }
                if (i < j) {
                    swap(nums[i], nums[j]);
                }
            }
            quick_sort(l, j);
            quick_sort(j + 1, r);
        };
        quick_sort(0, nums.size() - 1);
        return nums;
    }
};
```
---
## Rotate an Array (189.Leetcode):

<P>
  Difficulty: Medium 

  Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
</P>

### Solution: 

```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```
---
## 349. Intersection of Two Arrays(Leetcode): 

<P>
  Difficulty: Easy

  Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
</P>

### Solution:

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool s[1001];
        memset(s, false, sizeof(s));
        for (int x : nums1) {
            s[x] = true;
        }
        vector<int> ans;
        for (int x : nums2) {
            if (s[x]) {
                ans.push_back(x);
                s[x] = false;
            }
        }
        return ans;
    }
};
```
---
## Missing Number: (268.Leetcode):

<P>
  Difficulty: Easy
  Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8

Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
</P>

### Solution:
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i =0; i<nums.size();i++)
        {
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ i;
        }
        xor1 = xor1 ^ n;
        return xor1 ^ xor2;
    }
};
```
---
## Missing Number: (Geeks For Geeks)

<P>
  Difficulty: Easy
  You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.
Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size() + 1

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
</P>

### Solution:

```
 class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size() + 1;
        
        int xor1 = 0;
        int xor2 = 0;
        
        for (int i = 0; i<arr.size();i++)
        {
            xor2 = xor2 ^ arr[i];
            xor1 = xor1 ^ (i+1);
        }
        xor1 = xor1 ^ n;
        return xor1 ^ xor2;
    }
};
```
---
## Maxiumum Consective Ones (485. Leetcode):

<P>
  Difficulty: Easy

  Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
</P>

### Solution: 

```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0; 
        int cnt = 0;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                cnt++; 
                maxi = max(maxi, cnt);
            }
            else
            {
                cnt = 0;
            }
        }

        return maxi;
    }
};
```
---
## 136.Single Number(Leetcode):

<P>
  Difficulty: Easy

  Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
</P>

### Solution: 

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;

        for(int i =0; i<nums.size(); i++)
        {
            xorr = xorr^nums[i];
        }
        return xorr;
    }
};
```
---
