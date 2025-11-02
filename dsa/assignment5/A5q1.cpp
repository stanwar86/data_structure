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

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning" << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            cout << "Inserted " << value << " at end" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at end" << endl;
    }

    void insertAfterValue(int target, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != target)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node with value " << target << " not found" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << target << endl;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning" << endl;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            cout << "Deleted " << head->data << " from end" << endl;
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        cout << "Deleted " << temp->next->data << " from end" << endl;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteSpecificNode(int value) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value)
            temp = temp->next;
        if (temp->next == NULL) {
            cout << "Node not found" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted " << value << endl;
        delete toDelete;
    }

    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Found " << value << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value not found" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, target;

    while (true) {
        cout << "\n1. Insert at beginning\n2. Insert at end\n3. Insert after a value\n4. Delete from beginning\n5. Delete from end\n6. Delete specific node\n7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                list.insertAfterValue(target, value);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteSpecificNode(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
