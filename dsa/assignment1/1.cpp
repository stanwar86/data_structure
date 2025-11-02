#include <iostream>
using namespace std;

const int MAXN = 1000;
int arr[MAXN];
int sz = 0;

void createArray() {
    cout << "enter the size of array: ";
    int n; 
    cin >> n;
    if (n < 0 || n > MAXN) { cout << "invalid size\n"; return; }
    sz = n;
    cout << "enter elements in array:\n";
    for (int i = 0; i < sz; ++i) cin >> arr[i];
}

void display() {
    if (sz == 0) { cout << "array is empty\n"; return; }
    cout << "array: ";
    for (int i = 0; i < sz; ++i) {
        cout << arr[i] << (i + 1 < sz ? ' ' : '\n');
    }
}

void insertAt() {
    if (sz == MAXN) { cout << "array full\n"; return; }
    int pos, value;
    cout << "enter position (0.." << sz << "): ";
    cin >> pos;
    cout << "enter value to insert: ";
    cin >> value;
    if (pos < 0 || pos > sz) { cout << "invalid position\n"; return; }
    for (int i = sz; i > pos; --i) arr[i] = arr[i - 1];
    arr[pos] = value;
    ++sz;
}

void deleteAt() {
    if (sz == 0) { cout << "array empty\n"; return; }
    int pos;
    cout << "enter position to delete (0.." << sz - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= sz) { cout << "invalid position\n"; return; }
    for (int i = pos; i < sz - 1; ++i) arr[i] = arr[i + 1];
    --sz;
}

void linearSearch() {
    if (sz == 0) { cout << "array empty\n"; return; }
    int key; 
    cout << "enter the key: ";
    cin >> key;
    for (int i = 0; i < sz; ++i) {
        if (arr[i] == key) { cout << "found at index " << i << "\n"; return; }
    }
    cout << "not found\n";
}

int main() {
    while (true) {
        cout << "\n--Menu-- \n"
             << "1. create \n"
             << "2. display \n"
             << "3. insert \n"
             << "4. delete \n"
             << "5. linear search \n"
             << "6. exit \n"
             << "choice: ";
        int choice; 
        if (!(cin >> choice)) return 0;

        switch (choice) {
            case 1: createArray(); break;
            case 2: display(); break;
            case 3: insertAt(); break;
            case 4: deleteAt(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
            default: cout << "invalid choice\n";
        }
    }
}

