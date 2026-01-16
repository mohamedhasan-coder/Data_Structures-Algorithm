#include <iostream>
using namespace std;

class Solution {
public:
    void printPattern19(int n) {
        for (int i = 0; i < n; i++) {

            for (int j = 1; j <= n - i; j++)
            {
                cout << "*";
            } 
            for (int j = 1; j <= 2 * i; j++){
                cout << " ";
            }
            for (int j = 1; j <= n - i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            for (int j = 1; j <= 2 * (n - i); j++)
            {
                cout << " ";
            } 
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin>>n;
    Solution Pattern;
    Pattern.printPattern19(n);
    return 0;
}
