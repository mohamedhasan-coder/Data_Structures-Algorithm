#include<bits/stdc++.h>
using namespace std; 

/*
        Recusrion is a Function Calls Itself 
        untill Specified Condtion is met
*/

int cnt = 0;

void Print()
{
    if (cnt == 4)
        return; 
    cout<<cnt<<endl;
    cnt++;
    Print();
}

int main()
{
    Print();
    return 0;
}
