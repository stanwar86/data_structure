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

    void insertAtBeginning(int v) {
        Node* n = new Node(v);
        if (head == NULL) { head = n; head->next = head; return; }
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        n->next = head;
        tail->next = n;
        head = n;
    }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if (head == NULL) { head = n; head->next = head; return; }
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = n;
        n->next = head;
    }

    void insertAfterValue(int target, int v) {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        Node* t = head;
        do {
            if (t->data == target) {
                Node* n = new Node(v);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
        cout << "Value not found" << endl;
    }

    void insertBeforeValue(int target, int v) {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        if (head->data == target) { insertAtBeginning(v); return; }
        Node* prev = head;
        Node* curr = head->next;
        while (curr != head && curr->data != target) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) { cout << "Value not found" << endl; return; }
        Node* n = new Node(v);
        prev->next = n;
        n->next = curr;
    }

    void deleteValue(int v) {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        if (head->data == v && head->next == head) { delete head; head = NULL; cout << "Deleted " << v << endl; return; }
        Node* prev = NULL;
        Node* curr = head;
        do {
            if (curr->data == v) break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        if (curr->data != v) { cout << "Value not found" << endl; return; }
        if (curr == head) {
            Node* tail = head;
            while (tail->next != head) tail = tail->next;
            head = head->next;
            tail->next = head;
            delete curr;
            cout << "Deleted " << v << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Deleted " << v << endl;
    }

    void search(int v) {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        Node* t = head;
        int pos = 1;
        do {
            if (t->data == v) { cout << "Found at position " << pos << endl; return; }
            t = t->next; pos++;
        } while (t != head);
        cout << "Not found" << endl;
    }

    void display() {
        if (head == NULL) { cout << "List is empty" << endl; return; }
        Node* t = head;
        bool first = true;
        while (first || t != head) {
            first = false;
            cout << t->data;
            t = t->next;
            if (t != head) cout << " -> ";
        }
        cout << " -> " << head->data << endl;
    }
};

int main() {
    CircularList cl;
    int ch, v, target;
    while (true) {
        cout << "\n1 Insert at beginning\n2 Insert at end\n3 Insert after value\n4 Insert before value\n5 Delete value\n6 Search\n7 Display (head repeated at end)\n8 Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Value: "; cin >> v; cl.insertAtBeginning(v); break;
            case 2: cout << "Value: "; cin >> v; cl.insertAtEnd(v); break;
            case 3: cout << "Target: "; cin >> target; cout << "Value: "; cin >> v; cl.insertAfterValue(target, v); break;
            case 4: cout << "Target: "; cin >> target; cout << "Value: "; cin >> v; cl.insertBeforeValue(target, v); break;
            case 5: cout << "Value to delete: "; cin >> v; cl.deleteValue(v); break;
            case 6: cout << "Value to search: "; cin >> v; cl.search(v); break;
            case 7: cl.display(); break;
            case 8: return 0;
            default: cout << "Invalid choice" << endl;
        }
    }
}
