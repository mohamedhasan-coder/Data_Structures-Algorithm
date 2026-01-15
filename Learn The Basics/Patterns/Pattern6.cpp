#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void printPattern6(int n)
        {
            for (int i=1; i<=n ; i++)
            {
                for(int j=1;j<=n-i+1;j++)
                {
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    int n;
    cin>>n;
    Solution Pattern;
    Pattern.printPattern6(n);
    return 0; 
}
