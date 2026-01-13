#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void whichWeekDay(int Day){
            switch(Day){
                case 1:
                    cout<<"Monday";
                    break;
                case 2:
                    cout<<"Tuesday";
                    break;
                case 3:
                    cout<<"Wednesday";
                    break;
                case 4: 
                    cout<<"Thursday";
                    break;
                case 5: 
                    cout<<"Friday";
                    break;
                case 6: 
                    cout<<"Saturday";
                    break;
                case 7: 
                    cout<<"Sunday";
                    break;
                default: 
                    cout<<"Invalid";
                    break;
            }
        }
};

int main()
{
    int day;
    cin>>day;
    Solution WeekDay;
    WeekDay.whichWeekDay(day);
    return 0;
}
