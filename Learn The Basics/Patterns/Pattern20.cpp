#include <iostream>
using namespace std;

class Solution {
public:
    void printPattern20(int n)
    {
        int spaces = 2*n -2;
        for (int i=1;i<=2*n-1;i++)
        {
            int stars = i;
            if (i>n) stars = 2*n-i;
            //stars
            for (int j=1;j<=stars;j++)
            {
                cout<<"*";
            }
            // spaces
            for (int j=1;j<=spaces;j++)
            {
                cout<<" ";
            }
            //stars
            for (int j=1;j<=stars;j++)
            {
                cout<<"*";
            }
            if (i<n)
            {
                spaces -= 2;
            }
            else
            {
                spaces += 2;
            }
            cout<<endl;
        }
    }
};

int main() {
    int n;
    cin>>n;
    Solution Pattern;
    Pattern.printPattern20(n);
    return 0;
}
