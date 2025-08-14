#include<iostream>
using namespace std;

int arr[100];
int n = 0;

void create() {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter elements:";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if(n == 0) {
        cout << "Array is empty";
        return;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if(n >= 100) {
        cout << "Array is full";
        return;
    }

    int pos, val;
    cout << "Enter the index to insert the element at:";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    for(int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    cout << "Inserted";
}

void del() {
    int pos;
    cout << "Enter the index to delete element from: ";
    cin >> pos;

    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Deleted";
}

void linearsearch() {
    int key, found = 0;
    cout << "Enter value to search: ";
    cin >> key;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Found at index " << i << endl;
            found = 1;
            break;
        }
    }

    if(!found)
        cout << "Not found";
}

int main() {
    int ch;
    while(1) {
        cout << "\nMENU:\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch(ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linearsearch(); break;
            case 6: return 0;
            default: cout << "Invalid choice";
        }
    }

    return 0;
}


