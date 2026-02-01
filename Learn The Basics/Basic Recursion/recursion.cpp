#include<bits/stdc++.h>
using namespace std; 

/*
        Recusrion is a Function Calls Itself 
        untill Specified Condtion is met
*/

int cnt = 0;

void Printn()
{
    if (cnt == 4)
        return; 
    cout<<cnt<<endl;
    cnt++;
    Printn();
}

int main()
{
    Printn();
    return 0;
}
