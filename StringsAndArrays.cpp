#include <bits/stdc++.h>
using namespace std;  
            
/* -------- ARRAY OPERATIONS -------- */
class ArrayHelper { 
public:  
    void printArray(int arr[], int n) { 
        for (int i = 0; i < n; i++) { 
            cout << arr[i] << " ";   
        }  
        cout << endl;  
    }  
    
    void reverseArray(int arr[], int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    int removeElement(int arr[], int n, int value) {
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != value) {
                arr[index++] = arr[i];
            }
        }
        return index; // new size
    }
};

/* -------- STRING OPERATIONS -------- */
class StringHelper {
public:
    string concatenate(const string &a, const string &b) {
        string result = "";
        for (char c : a) result.push_back(c);
        for (char c : b) result.push_back(c);
        return result;
    }

    int countCharacters(const string &s) {
        return s.length();
    }

    int countWords(const string &s) {
        stringstream ss(s);
        string word;
        int count = 0;
        while (ss >> word) count++;
        return count;
    }

    int countCharacter(const string &s, char ch) {
        int count = 0;
        for (char c : s) {
            if (c == ch) count++;
        }
        return count;
    }

    string removeCharacter(const string &s, char ch) {
        string result = "";
        for (char c : s) {
            if (c != ch) result.push_back(c);
        }
        return result;
    }

    string removeDuplicates(const string &s) {
        set<char> seen;
        string result = "";
        for (char c : s) {
            if (seen.insert(c).second) {
                result.push_back(c);
            }
        }
        return result;
    }
};

/* -------- MAIN PROGRAM -------- */
int main() {

    cout << "===== ARRAY OPERATIONS =====\n";

    int arr[] = {1, 2, 2, 3, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ArrayHelper arrayTool;

    cout << "Original array: ";
    arrayTool.printArray(arr, n);

    n = arrayTool.removeElement(arr, n, 2);
    cout << "After removing number 2: ";
    arrayTool.printArray(arr, n);

    arrayTool.reverseArray(arr, n);
    cout << "After reversing the array: ";
    arrayTool.printArray(arr, n);

    cout << "\n===== STRING OPERATIONS =====\n";

    StringHelper stringTool;
    string text = "Hasan is learning C++";

    cout << "Original string: " << text << endl;
    cout << "Total characters: "
         << stringTool.countCharacters(text) << endl;
    cout << "Total words: "
         << stringTool.countWords(text) << endl;
    cout << "Count of letter 'a': "
         << stringTool.countCharacter(text, 'a') << endl;

    cout << "After removing 'a': "
         << stringTool.removeCharacter(text, 'a') << endl;

    cout << "After removing duplicate characters: "
         << stringTool.removeDuplicates(text) << endl;

    cout << "Concatenation example (HASAN + TECH): "
         << stringTool.concatenate("HASAN", "TECH") << endl;

    cout << "\nProgram finished successfully.\n";
    return 0;
}
