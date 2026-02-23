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
