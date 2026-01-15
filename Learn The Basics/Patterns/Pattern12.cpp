#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void printPattern12(int n)
        {
            int space = 2*(n-1);
            // number
            for(int i=1; i<=n; i++)
            {
                for (int j=1; j<=i; j++)
                {
                    cout<<j;
                }

            //space
            for(int j=1;j<=space;j++)
            {
                cout<<" ";
            }

            //number
            for(int j=i;j>=1;j--)
            {
                cout<<j;
            }
            cout<<endl;
            space-=2;
            }
        }
};

int main()
{
    int n;
    cin>>n;
    Solution Pattern;
    Pattern.printPattern12(n);
    return 0; 
}
