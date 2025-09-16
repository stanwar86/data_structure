#include <iostream>
#include <cctype>
using namespace std;

#define MAX 100
int s[MAX];
int top = -1;

void push(int x) { 
    top = top +1;
    s[top] = x; 
}
int pop() { 
    return s[top--]; 
}

int main() {
    char exp[MAX];
    cout << "Enter postfix: ";
    cin >> exp;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isdigit(c)) push(c - '0');
        else {
            int b = pop();
            int a = pop();
            switch(c) {
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
    }
    cout << "Result: " << pop() << endl;
    return 0;
}
