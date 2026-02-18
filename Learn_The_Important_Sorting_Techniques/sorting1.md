# Sorting 1: 
---
## Selection Sort (GFG):

<P>
  Difficulty: Easy
  Given an array arr, use selection sort to sort arr[] in increasing order.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: Maintain sorted (in bold) and unsorted subarrays. Select 1. Array becomes 1 4 3 9 7. Select 3. Array becomes 1 3 4 9 7. Select 4. Array becomes 1 3 4 9 7. Select 7. Array becomes 1 3 4 7 9. Select 9. Array becomes 1 3 4 7 9.
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Input: arr[] = [38, 31, 20, 14, 30]
Output: [14, 20, 30, 31, 38]
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 106

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(1)
</P>

### Solution:

```
class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0;i<=n- 2; i++)
        {
            int mini = i;
            for(int j=i+1;j<=n-1;j++)
            {
                if(arr[j]<arr[mini])
                {
                    mini = j;
                }
            }
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i]=temp;
        }
    }
};
```
---
