#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void printPattern14(int n)
        {
            for (int i=1;i<=n;i++)
            {
                for (char ch = 'A'; ch<= 'A' + i; ch++)
                {
                    cout<<ch<<" ";
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
    Pattern.printPattern14(n);
    return 0; 
}
