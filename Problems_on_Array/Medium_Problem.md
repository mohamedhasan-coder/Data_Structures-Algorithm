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
