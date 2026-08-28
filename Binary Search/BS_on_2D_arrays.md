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
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while(row < n  && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};
```
---

## Find Peak Element II: 

<p>
    Difficulty: Medium 

    A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:

<img width="206" height="209" alt="image" src="https://github.com/user-attachments/assets/c4e16189-519d-4460-811d-7f58133f096f" />


Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

Example 2:

<img width="254" height="257" alt="image" src="https://github.com/user-attachments/assets/1e1b903a-513b-4f34-8bbe-8b01643b6e91" />


Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.
</p>

### Solution: 

```
class Solution {
public:
    int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col){
        int maxValue = -1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low + high) / 2;
            int maxRowIndex = findMaxIndex(mat, n, m, mid);
            int left = mid -1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid +1 < m ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return {maxRowIndex, mid};
            }
            else if(mat[maxRowIndex][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};
```
---
## Matrix Median (Code 360): 

<P> 
.Diffculty: Medium 

    Problem statement
You have been given a matrix of ‘N’ rows and ‘M’ columns filled up with integers where every row is sorted in non-decreasing order. Your task is to find the overall median of the matrix i.e if all elements of the matrix are written in a single line, then you need to return the median of that linear array.

The median of a finite list of numbers is the "middle" number when those numbers are listed in order from smallest to greatest. If there is an odd number of observations, the middle one is picked. For example, consider the list of numbers [1, 3, 3, 6, 7, 8, 9]. This list contains seven numbers. The median is the fourth of them, which is 6.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 50
1 <= 'N' , 'M' <= 100
1 <= 'MATRIX'['I']['J'] <= 10 ^ 5
'N' * 'M' is always an odd number.

Where 'MATRIX'['I']['J']  denotes the value at ('I', 'J')th cell in the matrix.

Time limit: 1 sec
Sample Input 1:
2
1 3
1 2 3
3 3
2 6 9
1 5 11
3 7 8
Sample Output 1:
2
6
Explanation of sample input 1:
In the first test case, the overall median of the matrix is 2.

In the second test case, the overall median of the matrix is 6.
Sample Input 2:
2
3 3
2 6 8
1 4 7
6 8 9
3 5
1 2 6 6 10
2 4 4 5 7
2 5 5 6 6
Sample Output 2:
2
5
Explanation for sample input 2:
In the first test case, the overall median of the matrix is 2.

In the second test case, the overall median of the matrix is 5.
</P>

### Solution: 

```
#include <bits/stdc++.h>
using namespace std;

int countLessEqual(vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

int getMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = matrix[0][0];
    int high = matrix[0][cols - 1];

    for (int i = 1; i < rows; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols - 1]);
    }

    while (low < high) {
        int mid = (low + high) / 2;

        int count = 0;

        for (int i = 0; i < rows; i++) {
            count += countLessEqual(matrix[i], mid);
        }

        if (count < (rows * cols + 1) / 2)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
```
---
