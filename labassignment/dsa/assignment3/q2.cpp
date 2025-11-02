#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str, reversed = "";
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;
    for (char c : str) s.push(c);

    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed;
    return 0;
}
