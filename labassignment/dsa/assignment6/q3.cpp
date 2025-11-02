#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int v) { data = v; next = NULL; prev = NULL; }
};

class DoublyList {
    Node* head;
public:
    DoublyList() { head = NULL; }

    void insertEnd(int v) {
        Node* n = new Node(v);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dl.insertEnd(val);
    }
    cout << "Reverse order: ";
    dl.displayReverse();
}
