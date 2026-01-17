#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(1);//{1}
    st.insert(2);//{1,2}
    st.emplace(2);//{1,2}
    st.insert(4);//{1,2,4}
    st.insert(3); //{1,2,3,4}

    // functionaltiy of insert in vector 

    // can be used also, that only increases efficiency 

    // begin(), end(), rbegin(), rend(), size(), empty(), swap(), are same as other

    //{1,2,3,4}
    auto it = st.find(3);

    //{1,2,3,4}
    auto it = st.find(6);

    //{1,4,5}
    st.erase(5);
    // erases 5 // takes logaritmitic time

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it);// it takes constanst time 

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); // after erase {1,4,5} [First, last)

    // lower bound() and upper_bound() function works in same way 
    // as in vector it does
    
    // this is syntax

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    
    return 0; 
}
