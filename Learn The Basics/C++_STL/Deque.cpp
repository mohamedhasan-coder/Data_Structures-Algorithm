#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int>dq;

    dq.push_back(2); //{2}
    dq.emplace_back(4); //{2,4}

    dq.push_front(5); //{5,2,4}

    dq.emplace_front(3); //{3,5,2,4}

    dq.pop_back(); //{3,5,2}
    
    dq.pop_front();//{5,2}

    dq.back(); //dq.front() → first element (read/write access).

    dq.front(); //dq.back() → last element (read/write access).

    // rest functions same as vector 

    // begin, end, rbegin, rend, clear, insert, size, swap 


    return 0; 
}
