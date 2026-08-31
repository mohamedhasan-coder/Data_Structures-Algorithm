# Medium String Problems:
---
## Sort Charcters By Frequency: (451. Leetcode):

<P>
  Difficulty: Medium 

  Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
</P>

### Solution: 

```
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c]++;
        }
        vector<vector<char>> bucket(s.length() + 1);

        for(auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }

        string ans;
        
        for(int i = s.length(); i >= 1; i--) {
            for(char c : bucket[i]) {
                ans.append(i, c);
            }
        }

        return ans;
    }
};
```
---
## Maximum Nesting Depth of Parantheisis: (1614. Leetcode): 

<p>
  DIfficulty: Medium 

  Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3

 

Constraints:

1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.
 

</p>

### Solution: 

```
class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int curr = 0;
        for(char &c:s){
            if(c=='('){
                res = max(res, ++curr); 
            }
            if(c==')'){
                curr--;
            }
        }
        return res;
    }
};
```
---
## Roman to integer (13. Leetcode):

<P>
  Diffculty: Easy

  Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
</P>

### Solution: 

```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int total = mpp[s[s.length() - 1]];

        for(int i = s.length() - 2;i>=0;i--){
            int val = mpp[s[i]];
            if(val < mpp[s[i+1]]){
                total -= val;
            }
            else{
                total += val;
            }
        }

        return total;
    }
};
```
---

## String to integer (8. Leetcode): 

<P>
  Difficulty: Medium 


mplement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

 

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.

 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
</P>

### Solution: 

```
class Solution {
public:
    int myAtoi(string s) {
        // possible Cases
        // "235 Hello" -> returns 235

        int i = 0;
        int l = s.length();
    
        // ignore leading whitespaece
        while(i < l && isspace(s[i])){
            i++;
        }

        // if no more characters 
        //"     "
        if(i == l){
            return 0;
        }

        // check for valid sign
        bool negative = false;
        if(s[i] == '-'){
            negative = true;
            i++;
        }
        else if(s[i] == '+'){
            // move on the next character
            i++;
        }
        // " e23 "
        else if(!isdigit(s[i])){
            return 0;
        }
 
        // if no more characters 
        if(i == l){
            return 0;
        }

        // skip the leading zeros
        while(i < l && s[i] == '0'){
            i++;
        }

        // " +00000 "
        // if no more characters 
        if(i == l){
            return 0;
        }

        // extract numbers and return the int value 

        int value = 0; 
        int max = INT_MAX / 10;
        int min = INT_MIN / 10;

        while(i < l && isdigit(s[i])) {
            int digit = s[i] - '0'; // get the corresponding digit for this char
            
 
            // check if val within limits

            // handle Overflow
             if(value > max){
                return INT_MAX;
             }
             else if(value == max && digit>7){
                return INT_MAX;
             }

             // handle Overflow
             if(value < min){
                return INT_MIN;
             }
             else if(value == min && digit>8){
                return INT_MIN;
             }

            // if this is negative value
            if(negative){
                value = value * 10 + (-digit);
            }  
            // else if this is positive value
            else{
                value = value * 10 + digit;
            }

            i++;
        }

        // return 

        return value;
    }
};
```
---

