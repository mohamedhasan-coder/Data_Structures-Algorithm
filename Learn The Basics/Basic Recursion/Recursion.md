# Problems on Recursion 
---

## Print GFG n times ( Geeks For Geeks )

<P>
  Difficulty: Easy

  Print GFG n times without the loop.
  
  Your Task:
  
  This is a function problem. You only need to complete the function printGfg() that takes N as parameter and prints N times GFG recursively. Don't print newline, it will be added by the driver code.
  
  Expected Time Complexity: O(N).
  
  Expected Auxiliary Space: O(N) (Recursive).
  
  Constraint:
  1<=N<=1000

  Example:
  
  Input:
  
  5
  
  Output:
  GFG GFG GFG GFG GFG
</P>

### Solution: 

```
class Solution {
  public:
    void printGfg(int N) {
        // Code here
        if (N<=0)
           return;
        cout<<"GFG"<<" ";
        printGfg(N-1);
    }
};

```

---
## 1 to n Without Loops (Geeks For Geeks)

<P>
  Difficulty: Basic

Given an positive integer n, print numbers from 1 to n without using loops.

Implement the function printTillN() to print the numbers from 1 to n as space-separated integers.

Examples

Input: n = 5
Output: 1 2 3 4 5
Explanation: We have to print numbers from 1 to 5.
Input: n = 10
Output: 1 2 3 4 5 6 7 8 9 10
Explanation: We have to print numbers from 1 to 10.
Constraints:
1 ≤ n ≤ 1000
</P>

### Solution: 

```

class Solution {
  public:
    void printTillN(int n) {
        // code here
        if (n == 0)
            return;
        printTillN(n-1);
        cout<<n<<" ";
    }
};

```

---

## Print N to 1 without loop

<P>
  Difficulty: Easy

Print numbers from N to 1 (space separated) without the help of loops.

Example 1:

Input:
N = 10
Output: 10 9 8 7 6 5 4 3 2 1
Your Task:
This is a function problem. You only need to complete the function printNos() that takes N as parameter and prints number from N to 1 recursively. Don't print newline, it will be added by the driver code.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N) (Recursive).

Constraint
1<=n<=1000
</P>

### Solution

```
class Solution {
  public:
    void printNos(int N) {
        // code here
        if (N <= 0)
            return;
        
        cout<<N<<" ";
        printNos(N-1);
    }
};

```
