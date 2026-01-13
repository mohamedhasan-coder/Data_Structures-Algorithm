#include <iostream>
using namespace std;

void changeRealValue(int &x) { // Note the '&'
    x = 100; // Changes the actual variable
}

int main() {
    int num = 10;
    changeRealValue(num);
    cout << num; // Output: 100 (It changed!)
}
