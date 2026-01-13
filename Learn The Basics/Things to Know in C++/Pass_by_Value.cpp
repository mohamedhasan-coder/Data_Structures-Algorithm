#include <iostream>
using namespace std;

void changeValue(int x) {
    x = 100; // Changes only the copy
}

int main() {
    int num = 10;
    changeValue(num);
    cout << num; // Output: 10 (Original didn't change!)
}
