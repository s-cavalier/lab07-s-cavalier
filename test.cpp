#include <cstring>
#include <iostream>
using namespace std;

int main() {
    string test = "abcdedcba";
    cout << test << endl;
    test = test.substr(1, test.size() - 2);
    cout << test << endl;
    test = test.substr(1, test.size() - 2);
    cout << test << endl;
    test = test.substr(1, test.size() - 2);
    cout << test << endl;
    test = test.substr(1, test.size() - 2);
    cout << test << endl;
    return 0;
}