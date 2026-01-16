#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void printPattern18(int n)
        {
            for (int i=0;i<n;i++)
            {
                char ch = 'A' + (n-1);

                for (int j=0;j<=i;j++)
                {
                    cout<<ch<<" ";
                    ch--;
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
    Pattern.printPattern18(n);
    return 0; 
}
