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
