# Easy Problems on Array: 
---
## Largest in Array (GFG): 

<P>
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
</P>  

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
