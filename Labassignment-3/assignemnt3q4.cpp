#include <iostream>
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
bool isEmpty() { 
    return top == -1; 
}

int main() {
    char exp[100];
    cout << "Enter expression: ";
    cin >> exp;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty()) { cout << "Not Balanced\n"; return 0; }
            char ch = pop();
            if ((exp[i] == ')' && ch != '(') || 
                (exp[i] == '}' && ch != '{') || 
                (exp[i] == ']' && ch != '[')) {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }
    if (isEmpty()) cout << "Balanced\n"; 
    else cout << "Not Balanced\n";
    return 0;
}
