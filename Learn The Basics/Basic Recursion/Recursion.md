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
---

## Sum of First N Numbers (Code Ninja)

<P>

Difficulty: Easy
Problem statement
You are given an integer ‘n’.



Your task is determining the sum of the first ‘n’ natural numbers and returning it.



Example:
Input: ‘n’ = 3

Output: 6

Explanation: The sum of the first 3 natural numbers is 1 + 2 + 3, equal to 6.
</P>

### Solution 

```
long long sumFirstN(long long n) {
    return n * (n + 1) / 2;
}

/*
  Functional Approach
  long long sumFirstN(long long n) {
    // Write your code here.
    if (n == 0)
        return 0; 
    return n+sumFirstN(n-1);
}
*/

```

---
## Factorial (Geeks For Geeks)

<P>
  Difficulty: Basic

  Given a positive integer, n. Find the factorial of n.

Examples :

Input: n = 5
Output: 120
Explanation: 1 x 2 x 3 x 4 x 5 = 120
Input: n = 4
Output: 24
Explanation: 1 x 2 x 3 x 4 = 24
Constraints:
0 ≤ n ≤ 12

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
</P>

### Solution 

```

class Solution {
  public:
    int factorial(int n) {
        // code here
        if (n == 0)
            return 1;
        return n * factorial(n-1);
    }
};

```

---
## Reverse an Array (Geeks For Geeks)

<P>
  Difficulty: Easy

  You are given an array of integers arr[]. You have to reverse the given array.

Note: Modify the array in place.

Examples:

Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are [1, 4, 3, 2, 6, 5]. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is [5, 6, 2, 3, 4, 1].
Input: arr = [4, 5, 2]
Output: [2, 5, 4]
Explanation: The elements of the array are [4, 5, 2]. The reversed array will be [2, 5, 4].
Input: arr = [1]
Output: [1]
Explanation: The array has only single element, hence the reversed array is same as the original.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

</P>

### Solution 1: (Recursion): 

```
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        static int i=0; 
        
        int n = arr.size();

        if (i >= n-i-1)
        {
            i = 0;
            return;
        }
        
        swap(arr[i],arr[n-i-1]);
        i++;
        reverseArray(arr);
    }
};

```
### Solution 2: (Two Pointer Iterative)

```
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
};

```
---
