#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteOccurrences(int key) {
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }
    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "Count: " << count << endl;

    list.deleteOccurrences(key);
    cout << "Updated list: ";
    list.display();

    return 0;
}
