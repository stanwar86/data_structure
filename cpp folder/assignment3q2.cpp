#include <iostream>
#include <string>
using namespace std;
char s[100];
int top = -1;

void push(char c) {
    top = top +1;
    s[top] = c;
}

char pop() {
    top = top -1;
    return s[top];
}

int main() {
    string str;
    cout << "Enter string to reverse: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    } 
    cout << "Reversed string is: ";
    while (top != -1){
     cout << pop();
     cout << endl;
    }
    
    return 0;
}
