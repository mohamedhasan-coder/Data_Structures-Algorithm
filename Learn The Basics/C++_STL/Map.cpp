#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mpp;
    
    map<int, pair<int , int>>mpp1;

    map<pair<int,int>, int> mpp2;

    mpp[1] = 2;
    mpp.emplace(3,1);
    mpp.insert({2,4});

    mpp2[{2,3}] = 10;

    for (auto it: mpp)
    {
        cout<< it.first <<" "<<it.second<<endl;
    }

    cout<<mpp[1]<<endl;
    cout<<mpp[2]<<endl;

    auto it = mpp.find(3);
    cout<< *(it).second<<endl;

    auto it1 = mpp.find(5);

    auto it2= mpp.lower_bound(2);
    auto it3 = mpp.upper_bound(3);

    //erase, swap, size, empty are same as above


    return 0;
}
