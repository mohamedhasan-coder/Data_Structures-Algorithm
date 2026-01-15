#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void printPattern1(int n){
            for (int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout<<"* ";
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
    Pattern.printPattern1(n);
    return 0; 
}
