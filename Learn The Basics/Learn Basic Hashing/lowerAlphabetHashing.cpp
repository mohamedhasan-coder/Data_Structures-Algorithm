#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int q;
    cin>>q;

    // Pre Compute
    int hash[26] = {0};
    for (int i=0;i<s.size();i++)
    {
        hash[s[i] - 'a']++;
    }
    while(q--)
    {
        char c;
        cin>>c;
        // Fetch
        cout<<hash[c-'a'] <<endl;
    }
    return 0;
}
