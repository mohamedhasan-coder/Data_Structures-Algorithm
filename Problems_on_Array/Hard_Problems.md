# Hard Problems on Array: 
---
## Pascal Triangle (118.Leetcode): 

<P> 
Difficulty: Easy

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

![Pascal's Triangle Animation](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
</P>

### Solution:

```
class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1;col<row;col++){ 
            ans = ans * (row-col);
            ans = ans/(col);
        ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){ 
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
```
---
## Majority Element II (229.Leetcode): 

<P> 
Difficulty: Medium

 Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?
</P>

### Solution: 

```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1 == 0 && el2!=nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1!=nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1){
                cnt1++;
            }
            else if(nums[i] == el2){
                cnt2++;
            }
            else{
                cnt1--,cnt2--;
            }
        }
            cnt1 = 0;
            cnt2 = 0;
            vector<int>ls;
            for(int i=0;i<nums.size();i++){ 
                if(el1 == nums[i]){
                    cnt1++;
                }
                if(el2 == nums[i]){
                    cnt2++;
                }
            }
            int mini = nums.size()/3+1;
            if(cnt1 >= mini){
                ls.push_back(el1);
            }
            if(cnt2 >= mini){
                ls.push_back(el2);
            }
            return ls;
    }
};
```
---
## 3 SUM ():

<P>
Difficulty: Medium

 Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
</P>

### Solution (Brute Force Solution): 

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
```

### Solution (Better Solution):

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set <vector<int>> st;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            set<int> hashset; 
            for(int j = i+1;j<n;j++){
                int third = -(nums[i] + nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]); 
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
```

### Solution: (Optimal Solution): 

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{ 
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
```
---
