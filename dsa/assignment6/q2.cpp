#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class CircularList {
    Node* head;
public:
    CircularList() { head = NULL; }

    void insert(int v) {
        Node* n = new Node(v);
        if (head == NULL) {
            head = n;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    CircularList cl;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        cl.insert(val);
    }
    cout << "Circular Linked List: ";
    cl.display();
}
