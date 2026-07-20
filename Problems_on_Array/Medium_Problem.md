# Medium Problem on Arrays:                                                       
---                                                              
## 1. Two Sum (Leetcode) Give Index Value:    
   Difficulty: Easy  
                           
  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target .            

You may assume that each input would have exactly one solution, and you may not use the same element twice.     
                                    
You can return the answer in any order.                                                              
                    
Example 1:                       
Input: nums = [2,7,11,15], target = 9                   
Output: [0,1]            
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].      
Example 2:             
    
Input: nums = [3,2,4], target = 6
Output: [1,2] 
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
   

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

### Solution: 
         
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};
```
---

## Two Sum (Code ninja) Give YES or NO: 

<P> 
   Difficulty: Easy

  Problem statement
Sam want to read exactly ‘TARGET’ number of pages.

He has an array ‘BOOK’ containing the number of pages for ‘N’ books.

Return YES/NO, if it is possible for him to read any 2 books and he can meet his ‘TARGET’ number of pages.

Example:
Input: ‘N’ = 5, ‘TARGET’ = 5
‘BOOK’ = [4, 1, 2, 3, 1] 

Output: YES
Explanation:
Sam can buy 4 pages book and 1 page book.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5 5
4 1 2 3 1
Sample Output 1 :
YES
Explanation Of Sample Input 1:
Sam can buy 4 pages book and 1-page book.
Sample Input 2:
2 1
1 2
Sample Output 2 :
NO
Expected Time Complexity:
O( N ), Where N is the length of the array.
Constraints:
1  <= N <= 10^3
1 <= BOOK[i], TARGET <= 10^6
Time Limit: 1 sec
</P>

### Solution: 

```
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    int left = 0,  right =n-1;
    sort(book.begin(), book.end());
    while(left<right){
        int sum = book[left]+book[right];
        if(sum == target){
            return "YES";
        }
        else if(sum < target) left ++;
        else right--;
    }
    return "NO";
}

```
---
## Sort Colors (75.Leetcode):

<P>
   Difficulty: Medium
   Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
</P>

### Solution: 

```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid =0, high = n-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```
---

## Majority Elemment (169. Leetcode): 

<P>
   Diificulty: Easy

   Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
</P>

### Solution: (BETTER SOLUTION) 

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mpp;
        // O(N log N)
        for(int i=0; i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        // O(N)
        for(auto it:mpp){
            if(it.second > (nums.size()/2)){
                return it.first;
            }
        }
        return -1;
    }
};
```

### Solution(OPTIMAL SOLUTION): 

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0; 
        int el;
        for(int i=0;i<nums.size();i++){
           if(cnt==0){
            cnt = 1;
            el=nums[i];
           }
           else if(nums[i] == el){
            cnt++;
           } 
           else {
            cnt--;
           }
        }
        int cnt1=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == el){
                cnt1++;
            }
        } 
        if (cnt1 > nums.size() / 2){
            return el;
        }
        return -1;
    }
};
```
---
## Maximum Subarray (53. Leetcode): 

<P>
   Difficulty: Medium

   Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
</P>

### Solution: 

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN; 
        
        long long sum = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; 
            if (sum > maxi) {
                maxi = sum; 
            }
            if (sum < 0) {
                sum = 0; 
            }
        }
        return maxi;
    }
};
```
---
## Print Subarray With Maximum Subarray Sum: (Code Chef): 

<P> 
   Difficulty: Medium 

   Given an integer array 
n
u
m
s
nums, find the longest contiguous subarray (containing at least one element) with the largest sum and print the elements of that subarray.

Note:
If two or more sub arrays have the same length and same max sum then you should return the leftmost array.

Function Declaration
Function Name
m
a
x
S
u
b
A
r
r
a
y
maxSubArray – This function finds the longest contiguous subarray (with at least one element) that has the maximum possible sum, and returns the elements of that subarray. If multiple subarrays have the same maximum sum and same length, the function returns the leftmost such subarray.

Parameters
n
u
m
s
nums : A reference to a vector of integers representing the array.

Each element can be negative, zero, or positive.
Return Value
Returns an array containing the elements of the contiguous subarray that:

Has the maximum subarray sum.
If multiple subarrays achieve this sum, the function returns the longest one.
If still tied, returns the leftmost such subarray.
Constraints
1
≤
n
u
m
s
.
l
e
n
g
t
h
≤
10
5
1≤nums.length≤10 
5
 
−
10
4
≤
n
u
m
s
[
i
]
≤
10
4
−10 
4
 ≤nums[i]≤10 
4
 
The solution must run in O(N) time due to input size.
Input Format
The first line contains a single integer 
T
T — the number of test cases.

For each test case:

The first line contains an integer 
N
N — the size of the array.
The next line contains 
N
N space-separated integers representing the array elements.
Output Format
For each test case, print the elements of the longest maximum-sum subarray on a new line.
Sample 1:
Input
Output
2
6
4 -1 2 1 -5 4
5
1 2 -1 -2 5
4 -1 2 1
1 2 -1 -2 5
Explanation:
For the first test case the subarray from index 0 to 3 has the largest sum = 6.
The second test case the subarray from index 0 to 4 has the largest sum = 5.
</P>

### Solution: 

```
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        long long maxSum = nums[0], currSum = nums[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (currSum + nums[i] < nums[i]) {
                currSum = nums[i];
                tempStart = i;
            } else {
                currSum += nums[i];
            }

            int currLen = i - tempStart + 1;
            int bestLen = end - start + 1;

            if (currSum > maxSum ||
                (currSum == maxSum && currLen > bestLen)) {
                maxSum = currSum;
                start = tempStart;
                end = i;
            }
        }

        return vector<int>(nums.begin() + start, nums.begin() + end + 1);
    }
};
```
---
## Best Time to Buy and Sell Stock (121. Leetcode): 

<P> 
Difficulty: Easy

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
</P>

### Solution: 

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxprofit = 0;
        int n = prices.size();

        for(int i=0; i<n; i++){ 
            int cost = prices[i] - mini; 
            maxprofit = max(maxprofit,cost);
            mini = min(mini, prices[i]);
        }
        return maxprofit;
    }
};
```
---
