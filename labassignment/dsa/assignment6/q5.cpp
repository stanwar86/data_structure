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

    void deleteNode(int val) {
        if (head == NULL) return;

        Node* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;

        if (temp == NULL) return;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    int n, val, del;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dl.insertEnd(val);
    }
    cout << "Enter node to delete: ";
    cin >> del;
    dl.deleteNode(del);
    cout << "Updated list: ";
    dl.display();
}
