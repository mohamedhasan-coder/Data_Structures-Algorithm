# Basic and Easy String Problems:
---
## Remove Outermost Paranthesis (1021. Leetcode): 

<p>
  Difficulty: Easy

  A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.

</p>

### Solution: 

```
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";

        for(int i=0; i<s.length();i++){
            if(s[i] == ')'){
                cnt--;
            }
            if(cnt!=0){
                ans += s[i];
            }
            if(s[i] == '('){
                cnt++;
            }
        }
        return ans;
    }
};
```
---
## reverse Words in String(151. Leetcode): 

<P>
  Difficulty: Medium 

  Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
</P>

### Solution (Better Approach): 

```
class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i = 0;
        int n = s.length();

        while(i<n){
            while(i<n && s[i] == ' ') i++;  
            if(i >= n) break;
            int j = i+1;
            while(j<n && s[j] != ' ') j++;
            string sub = s.substr(i, j-i);
            if(result.length() == 0) result = sub;
            else result =  sub + " " + result;
            i = j+1;
        }
        return result;
    }
};
```

### Solution (Optimized):

```
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.length();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            int j = i;

            while (j < n && s[j] != ' ')
                j++;

            words.push_back(s.substr(i, j - i));

            i = j;
        }

        string result;

        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];

            if (i != 0)
                result += " ";
        }

        return result;
    }
};
```
### Solution (Without Extra Space): 

```
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        // 1. Remove extra spaces
        int i = 0;
        int j = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }

            while (i < n && s[i] == ' ')
                i++;

            if (i < n)
                s[j++] = ' ';
        }

        s.resize(j);

        // 2. Reverse the entire string
        reverse(s.begin(), s.end());

        // 3. Reverse each word
        i = 0;

        while (i < j) {
            int start = i;

            while (i < j && s[i] != ' ')
                i++;

            reverse(s.begin() + start, s.begin() + i);

            i++;
        }

        return s;
    }
};
```
---
## Largest Odd Number in a String: (1903. Leetcode):

<P>
  Diffculty: Easy

  You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 

Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.
</P>

### Solution:

```
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int i = n-1;
        while(i >= 0 && (num[i] - '0') % 2 == 0){
            i--;
        }
        return num.substr(0, i+1);
    }
};
```
---
## longest Common Prefix (14. Leetcode): 

<P>
  Difficulty: Easy 

  Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
</P>

### Solution:

```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int n = strs[0].size();

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;

            while (j < n &&
                   j < strs[i].size() &&
                   strs[0][j] == strs[i][j]) {
                j++;
            }

            n = j;

            if (n == 0) return "";
        }

        return strs[0].substr(0, n);
    }
};
```
---
