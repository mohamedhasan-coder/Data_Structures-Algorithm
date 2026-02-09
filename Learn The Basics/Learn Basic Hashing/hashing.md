# Problems on Hashing
---

## Frequency of Elements (Geeks For Geeks)

<P>
  Difficulty : Easy

  Given an array arr[] of positive integers which may contain duplicate elements, return the frequency of each distinct element.

Examples:

Input: arr[] = [1, 2, 2, 3, 3, 5]
Output: [[1, 1], [2, 2], [3, 2], [5, 1]]
Explaiantion: Here element 1 and 5 occur 1 times, 2 and 3 occur 2 times.
Input: arr[] = [1, 5, 6, 7, 7]
Output: [[1, 1], [5, 1], [6, 1], [7, 2]]
Explanation: Here element 1, 5 and 6 occur 1 times, 7 occur 2 times.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109

</P>

### Solution

```
class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here 
        unordered_map<int,int> freq;
        vector<vector<int>> result;
        
        for (int x: arr)
        {
            freq[x]++;
        }
        
        for(auto &it :freq)
        {
            result.push_back({it.first,it.second});
        }
        
        return result;
    }
};
```
---

## Most Frequent Element in an Array ( Geeks For Geeks ) 

<P>
  Difficulty: Easy

  You are given an integer array arr[]. You need to return the element which occurs maximum times in arr[].
Note: If multiple such elements exists return the maximum element.

Example: 

Input: arr[] = [1, 2, 2, 2, 4, 1]
Output: 2
Explanation: 2 is most frequent element of this array with 3 occurrences.
Input: arr[] = [1, -5, 8, 1]
Output: 1
Explanation: 1 is most frequent element of this array with 2 occurrences.
Input: arr[] = [3, 0, 0, 3, 8]
Output: 3
Explanation: 0 and 3 are two most frequent elements of this array. 3 is the maximum one.
Constraints:
1 ≤ arr.size() ≤ 105
-105 ≤ arr[i] ≤ 105
</P>

### Solution: 

```

class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        // code here
        unordered_map<int,int> freq;
        
        for (int x: arr)
        {
            freq[x]++;
        }
        
        int max_freq = 0; 
        int ans = INT_MIN;
        
        for (auto &it : freq)
        {
            int val = it.first;
            
            int count = it.second;
            
            if  (count>max_freq || (count == max_freq && val>ans))
            {
                max_freq = count;
                ans = val;
            }
        }
        return ans;
    }
};

```
---
