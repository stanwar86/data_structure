#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int v) { data = v; prev = next = NULL; }
};

class DoublyList {
    Node* head;
public:
    DoublyList() { head = NULL; }

    void insertAtBeginning(int v) {
        Node* n = new Node(v);
        if (head == NULL) { head = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if (head == NULL) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    void insertAfterValue(int target, int v) {
        Node* t = head;
        while (t && t->data != target) t = t->next;
        if (t == NULL) { cout << "Value not found" << endl; return; }
        Node* n = new Node(v);
        n->next = t->next;
        n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }

    void insertBeforeValue(int target, int v) {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        if (head->data == target) { insertAtBeginning(v); return; }
        Node* t = head->next;
        while (t && t->data != target) t = t->next;
        if (t == NULL) { cout << "Value not found" << endl; return; }
        Node* n = new Node(v);
        n->next = t;
        n->prev = t->prev;
        t->prev->next = n;
        t->prev = n;
    }

    void deleteValue(int v) {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        Node* t = head;
        while (t && t->data != v) t = t->next;
        if (t == NULL) { cout << "Value not found" << endl; return; }
        if (t->prev) t->prev->next = t->next;
        else head = t->next;
        if (t->next) t->next->prev = t->prev;
        cout << "Deleted " << v << endl;
        delete t;
    }

    void search(int v) {
        Node* t = head;
        int pos = 1;
        while (t) {
            if (t->data == v) { cout << "Found at position " << pos << endl; return; }
            t = t->next; pos++;
        }
        cout << "Not found" << endl;
    }

    void displayForward() {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        Node* t = head;
        while (t) {
            cout << t->data;
            if (t->next) cout << " -> ";
            t = t->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        Node* t = head;
        while (t->next) t = t->next;
        while (t) {
            cout << t->data;
            if (t->prev) cout << " -> ";
            t = t->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    int ch, v, target;
    while (true) {
        cout << "\n1 Insert at beginning\n2 Insert at end\n3 Insert after value\n4 Insert before value\n5 Delete value\n6 Search\n7 Display forward\n8 Display backward\n9 Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Value: "; cin >> v; dl.insertAtBeginning(v); break;
            case 2: cout << "Value: "; cin >> v; dl.insertAtEnd(v); break;
            case 3: cout << "Target: "; cin >> target; cout << "Value: "; cin >> v; dl.insertAfterValue(target, v); break;
            case 4: cout << "Target: "; cin >> target; cout << "Value: "; cin >> v; dl.insertBeforeValue(target, v); break;
            case 5: cout << "Value to delete: "; cin >> v; dl.deleteValue(v); break;
            case 6: cout << "Value to search: "; cin >> v; dl.search(v); break;
            case 7: dl.displayForward(); break;
            case 8: dl.displayBackward(); break;
            case 9: return 0;
            default: cout << "Invalid choice" << endl;
        }
    }
}
