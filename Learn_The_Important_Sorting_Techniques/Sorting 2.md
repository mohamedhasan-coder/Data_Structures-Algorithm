# Sorting - 2 ( Recursive Sorting): 

--- 

## Merge Sort (GFG): 

<P> 
 Difficulty: Medium

  Merge Sort
Difficulty: MediumAccuracy: 54.1%Submissions: 276K+Points: 4Average Time: 15m
Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.

Examples:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: We get the sorted array after using merge sort
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: We get the sorted array after using merge sort 
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

Expected Complexities
Time Complexity: O(n log n)
Auxiliary Space: O(n)
</P>

### Solution:

```
void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> temp;
    int left = l;
    int right = mid + 1;

    while (left <= mid && right <= r) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    while (right <= r) {
        temp.push_back(arr[right++]);
    }

    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
}

class Solution {
public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};
```
---
