# Bs on 2D Arrays: 
---
## Row with Max 1s in Rowwise Sorted (Geeks For Geeks): 

<P> 
Difficulty: Medium 

Given a 2D binary array arr[][] of size n*m consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note: The array follows 0-based indexing.

Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 - 1s). Hence, the output is 2.
Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 - 1s). Hence, the output is 1.
Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.
Constraints:

1 ≤ n, m ≤ 103
0 ≤ arr[i][j] ≤ 1

</P>

### Solution: 

```
class Solution {
public:

    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &arr) {

        int cnt_max = 0;
        int index = -1;

        int n = arr.size();
        int m = arr[0].size();

        for (int i = 0; i < n; i++) {

            int firstOne = lowerBound(arr[i], 1);

            int cnt = m - firstOne;

            if (cnt > cnt_max) {
                cnt_max = cnt;
                index = i;
            }
        }

        return index;
    }
};
```
---
## Search in a 2D Matrix(74. Leetcode): 

<P>
    Difficulty: Medium 

    You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:

<img width="322" height="242" alt="image" src="https://github.com/user-attachments/assets/9d62fbd0-681e-4c28-b120-b0c6cad24d37" />

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

<img width="322" height="242" alt="image" src="https://github.com/user-attachments/assets/74a9d9ab-9eb7-42a1-acb9-c86a7bb27193" />

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
</P>

### Solution: 

```
 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m -1;
        while(low <= high){
            int mid = (low + high) / 2;
            int row = mid / m; 
            int col = mid % m;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};
```
---
## Search 2D Matrix  II (240. Leetcode): 

<P>
    Difficulty: medium 

    Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:
<img width="402" height="402" alt="image" src="https://github.com/user-attachments/assets/7fae1753-f9d6-4691-9392-b1c52301e852" />


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
<img width="402" height="402" alt="image" src="https://github.com/user-attachments/assets/96d79ecb-ddcd-4f2e-9d39-0f84bc657ba4" />


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
</P>

### Solution: 

```

```
---
