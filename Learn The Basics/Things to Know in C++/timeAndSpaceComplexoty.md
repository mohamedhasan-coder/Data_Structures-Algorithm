# Understanding Time and Space Complexity

Understanding Time and Space Complexity is fundamental to evaluating and optimizing algorithms.

Time Complexity shows how execution time scales with input size.  
Space Complexity shows how memory usage grows as input size increases.

By analyzing both, developers can:
- Choose the most efficient algorithm
- Optimize performance
- Design scalable and resource-efficient applications

------------------------------------------------------------

## Time Complexity

Time complexity represents how long an algorithm takes to run as the size of input N increases.

Instead of measuring actual time (seconds), we analyze:
- How many operations are performed
- How execution grows with input size

------------------------------------------------------------

## Big O Notation

Big O notation describes the worst-case performance of an algorithm.

It answers:
“How slow can this algorithm get as input grows?”

------------------------------------------------------------

## Rules for Calculating Time Complexity

### Rule 1: Ignore Constants

Example:

    for(int i = 0; i < 5; i++) { }

Time Complexity: O(1)

    for(int i = 0; i < N; i++) { }

Time Complexity: O(N)

Explanation:  
Constant values are ignored because they do not affect the growth rate.

------------------------------------------------------------

### Rule 2: Consider the Worst Case

Example:

    for(int i = 0; i < N; i++) {
        if(arr[i] == target) break;
    }

Best Case: O(1)  
Worst Case: O(N)

We always analyze the worst case to guarantee maximum execution time.

------------------------------------------------------------

## Examples of Time Complexity

### Linear Time – O(N)

    for(int i = 0; i < N; i++) {
        // constant time operation
    }

------------------------------------------------------------

### Quadratic Time – O(N^2)

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // constant time operation
        }
    }

------------------------------------------------------------

### Logarithmic Time – O(log N)

    for(int i = 1; i < N; i = i * 2) {
        // constant time operation
    }

Used in binary search.

------------------------------------------------------------

### Constant Time – O(1)

    int sum = a + b;

------------------------------------------------------------

## Best, Average, and Worst Case

Best Case: Minimum time required  
Average Case: Expected time for random input  
Worst Case: Maximum time required (used in analysis)

------------------------------------------------------------

## Other Asymptotic Notations

Big O (O): Worst case  
Omega (Ω): Best case  
Theta (Θ): Average case  

Example:

    for(int i = 0; i < N; i++) { }

Best Case: Ω(N)  
Worst Case: O(N)  
Average Case: Θ(N)

------------------------------------------------------------

## Common Time Complexities

O(1)      Constant  
O(log N)  Logarithmic  
O(N)      Linear  
O(N log N) Linearithmic  
O(N^2)    Quadratic  
O(2^N)    Exponential  
O(N!)     Factorial  

------------------------------------------------------------

## Space Complexity

Space complexity measures how much memory an algorithm uses based on input size.

Types of Space:
1. Input Space – Memory used to store input
2. Auxiliary Space – Extra memory used during execution

------------------------------------------------------------

## Examples of Space Complexity

### O(N) Space

    int arr[N];

Memory increases with input size.

------------------------------------------------------------

### O(N) Space (Recursion)

    void func(int n) {
        if(n == 0) return;
        func(n - 1);
    }

Each recursive call uses stack memory.

------------------------------------------------------------

### O(1) Space

    int a, b, c;

Uses constant memory.

------------------------------------------------------------

## Time vs Space Trade-Off

Faster algorithms often use more memory.  
Memory-efficient algorithms may take more time.

Example:
- Hash tables: more space, faster access
- Linear search: less space, slower access

------------------------------------------------------------

## Conclusion

Time and Space Complexity help developers:
- Analyze performance
- Optimize algorithms
- Build scalable and efficient applications

Mastering complexity analysis is essential for:
- Technical interviews
- Competitive programming
- Real-world software development

------------------------------------------------------------

## Note

To improve your understanding:
- Practice analyzing different algorithms
- Compare multiple approaches
- Validate with test cases and examples
