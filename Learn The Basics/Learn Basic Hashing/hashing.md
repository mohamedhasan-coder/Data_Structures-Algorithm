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
