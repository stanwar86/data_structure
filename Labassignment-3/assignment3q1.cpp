#include <iostream>
using namespace std;

#define MAX 5
int s[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "stack Overflow";
    } else {
        s[++top] = x;
        cout << x << " pushed";
    }
}

void pop() {
    if (top == -1) {
        cout << "stack Underflow";
    } else {
        cout << s[top--] << " popped";
    }
}

void isEmpty() {
    if (top == -1) cout << "s is Empty\n";
    else cout << "s is not Empty\n";
}

void isFull() {
    if (top == MAX - 1) cout << "s is Full\n";
    else cout << "s is not Full\n";
}

void display() {
    if (top == -1) cout << "s is Empty\n";
    else {
        cout << "s: ";
        for (int i = top; i >= 0; i--)
            cout << s[i] << " ";
        cout << endl;
    }
}

void peek() {
    if (top == -1) cout << "s Empty\n";
    else cout << "Top Element: " << s[top] << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: pop(); 
            break;
            case 3: isEmpty(); 
            break;
            case 4: isFull(); 
            break;
            case 5: display(); 
            break;
            case 6: peek(); 
            break;
            case 7: cout << "Exiting..."; 
            break;
            default: cout << "Invalid";
        }
    } while(choice != 7);
    return 0;
}
