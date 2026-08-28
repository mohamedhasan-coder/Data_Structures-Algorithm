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
