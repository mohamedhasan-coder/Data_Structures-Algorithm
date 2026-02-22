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
## Bubble Sort (Recursive way) - (GFG):

<P>
 Difficulty: Easy

 Given an array, arr[]. Sort the array using bubble sort algorithm.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After Sorting the array in ascending order of their values is [1, 3, 4, 7, 9].
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: Sort the array in ascending order of their values.
Input: arr[] = [1, 2, 3, 4, 5]
Output: [1, 2, 3, 4, 5]
Explanation: An array that is already sorted should remain unchanged after applying bubble sort.
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 103

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(1)
</P>

### Solution: 

```
class Solution {
  public:
    void bubbleSortUtil(vector<int>& arr, int n) {
        if (n == 1) return;

        bool didswap = false;

        for (int j = 0; j <= n - 2; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didswap = true;
            }
        }

        if (!didswap) return;

        bubbleSortUtil(arr, n - 1);
    }

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;
        bubbleSortUtil(arr, n);
    }
};
```
---
## Insertion Sort - Recursive Way - (GFG): 

<P>
 Difficulty: Easy

 Given an array arr[] of positive integers.The task is to complete the insertsort() function which is used to implement Insertion Sort.

Examples:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: The sorted array will be [1, 3, 4, 7, 9].
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].
Input: arr[] = [4, 1, 9]
Output: [1, 4, 9]
Explanation: The sorted array will be [1, 4, 9].
Constraints:
1 ≤ arr.size() ≤ 1000
1 ≤ arr[i] ≤ 10000

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(1)
</P>

### Solution: 

```
class Solution {
  public:
    void insertionSortUtil(vector<int>& arr, int i, int n) {
        if (i == n) return;

        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }

        insertionSortUtil(arr, i + 1, n);
    }
    
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;
        insertionSortUtil(arr, 1, n); 
    }
};
```
---
## Quick Sort (GFG): 

<P>
 <Difficulty: Medium

  
</P>
