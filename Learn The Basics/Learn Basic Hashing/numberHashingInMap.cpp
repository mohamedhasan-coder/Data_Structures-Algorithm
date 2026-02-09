#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
        map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];    
        // Pre Compute
        mpp[arr[i]]++;
    }
 
    // Iterate in the Map
    for (auto it: mpp)
    {
        cout<<it.first<< "-->" << it.second <<endl;
    }

    int q;
    cin>>q;
    while (q--)
    {
        int number;
        cin>>number;
        // Fetch
        cout<<mpp[number]<<endl;
    }
    
    return 0;
}
