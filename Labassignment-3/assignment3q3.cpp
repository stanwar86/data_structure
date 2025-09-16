#include <iostream>
#include <cctype>
using namespace std;

#define MAX 100
char s[MAX];
int top = -1;

void push(char c) { 
    top = top +1;
    s[top] = c; 
}
char pop() { 
    return s[top--]; 
}
char peek() { 
    return s[top]; 
}
bool isEmpty() { 
    return top == -1; 
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter infix: ";
    cin >> infix;

    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) postfix[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') postfix[k++] = pop();
            pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (!isEmpty()) postfix[k++] = pop();
    postfix[k] = '\0';

    cout << "Postfix: " << postfix << endl;
    return 0;
}
