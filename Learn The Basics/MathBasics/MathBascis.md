# Math Basics
---
## Number of Digits (Coding Ninjas)

<P>Difficulty : Easy</P>

<P>Ninja want to add coding to his skill set so he started learning it. On the first day, he stuck to a problem in which he has given a long integer ‘X’ and had to count the number of digits in it.

Ninja called you for help as you are his only friend. Help him to solve the problem.

</p>

### EXAMPLE:
<p>
Input: 'X' = 2

Output: 1

As only one digit is ‘2’ present in ‘X’ so answer is ‘1’.
</P>

### Constraints :
<P>
1 <= 'T' <= 1000
1 <= ‘X’ <= 10^18
Time Limit: 1 sec
</p>

```
Sample Input 1 :
2
89
870
Sample Output 1 :
2
3
Explanation Of Sample Input 1 :
In test case ‘1’. There are ‘2’ digits present in ‘89’ that is ‘8’ and ‘9’. So the answer is ‘2’.
In test case ‘2’. There are ‘3’ digits present in ‘870’ that is ‘8’, ‘7’ and ‘0’. So the answer is ‘3’.
Sample Input 2 :
2
240
1
Sample Output 2 :
3
1
```

### Solution: 

```
#include <bits/stdc++.h> 
int countDigit(long long x) {
    // Write your code here.
    int count = 0;
    while (x>0)
    {
        count = count + 1;
        x = x/10;
    }
    return count;
}
```
---
## 7. Reverse Integer (Leetcode)

<P>Difficulty: Medium</P>

<P>
    Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
</P>

### Solution: 

```
class Solution {
public:
    int reverse(int x) {
        int ReverseNumber = 0;
        while (x!=0)
        {
            int LastDigit = x %10;
            if (ReverseNumber > INT_MAX / 10 || 
               (ReverseNumber == INT_MAX / 10 && LastDigit > 7))
                return 0;

            if (ReverseNumber < INT_MIN / 10 || 
               (ReverseNumber == INT_MIN / 10 && LastDigit < -8))
                return 0;
            ReverseNumber = (ReverseNumber * 10) + LastDigit;
            x = x/10;
        }
        return ReverseNumber;
    }
};

```
---
## 9.Palindrome Number (LeetCode)

<P>Difficulty : Easy</P>

<P>
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
</P>

### Solution: 

```
class Solution {
public:
    bool isPalindrome(int x) {
        int duplicate = x;
        int ReverseNumber = 0; 
        while (x > 0)
        {
            int LastDigit = x%10;
            if (ReverseNumber > INT_MAX / 10 ||
               (ReverseNumber == INT_MAX/10 && LastDigit >7))
            return 0;
            if (ReverseNumber < INT_MIN/10 ||
                (ReverseNumber == INT_MIN/10 && LastDigit < -8))
            return 0; 
            ReverseNumber = (ReverseNumber * 10) + LastDigit;         
            x = x/10;   
        }
        if (ReverseNumber == duplicate)
        {
            return true;
        } 
        else if (duplicate < 0)
        {
            return false;
        }  
        else
        { 
            return false;
        }
    }
};

```
