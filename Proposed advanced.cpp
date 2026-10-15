
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Customer {
    int id, priority, serviceTime;
    string name, issue;
};

struct Node {
    Customer data;
    Node* next;
};

struct History {
    Customer data;
    History* next;
};

Node* front = NULL;
History* historyHead = NULL;
int waiting = 0;

void addCustomer() {
    Customer c;

    cout << "Enter customer ID: ";
    cin >> c.id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter customer name: ";
    getline(cin, c.name);

    cout << "Enter issue: ";
    getline(cin, c.issue);

    cout << "Priority (3=High, 2=Medium, 1=Normal): ";
    cin >> c.priority;

    if (c.priority < 1 || c.priority > 3) {
        cout << "Invalid priority!\n";
        return;
    }

    c.serviceTime = 0;
    Node* n = new Node{c, NULL};

    if (front == NULL || c.priority > front->data.priority) {
        n->next = front;
        front = n;
    } else {
        Node* t = front;
        while (t->next != NULL &&
               t->next->data.priority >= c.priority)
            t = t->next;

        n->next = t->next;
        t->next = n;
    }

    waiting++;
    cout << "Customer added successfully!\n";
}

void displayQueue() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* t = front;
    cout << "\n--- Waiting Customers ---\n";

    while (t != NULL) {
        cout << "ID: " << t->data.id
             << " | Name: " << t->data.name
             << " | Issue: " << t->data.issue
             << " | Priority: " << t->data.priority << "\n";
        t = t->next;
    }

    cout << "Total waiting: " << waiting << "\n";
}

void searchCustomer() {
    int id;
    cout << "Enter customer ID to search: ";
    cin >> id;

    Node* t = front;

    while (t != NULL) {
        if (t->data.id == id) {
            cout << "Customer found: " << t->data.name
                 << " | Issue: " << t->data.issue
                 << " | Priority: " << t->data.priority << "\n";
            return;
        }
        t = t->next;
    }

    cout << "Customer not found in waiting queue.\n";
}

void serveCustomer() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* t = front;
    front = front->next;

    cout << "Serving: " << t->data.name
         << " (ID: " << t->data.id << ")\n";

    cout << "Enter service duration in seconds: ";
    cin >> t->data.serviceTime;

    if (t->data.serviceTime < 0) {
        cout << "Invalid duration. Using 0 seconds.\n";
        t->data.serviceTime = 0;
    }

    History* h = new History{t->data, historyHead};
    historyHead = h;

    cout << "Customer served successfully!\n";
    waiting--;

    delete t;
}

void displayHistory() {
    if (historyHead == NULL) {
        cout << "No call history available.\n";
        return;
    }

    History* h = historyHead;
    cout << "\n--- Served Customer History ---\n";

    while (h != NULL) {
        cout << "ID: " << h->data.id
             << " | Name: " << h->data.name
             << " | Issue: " << h->data.issue
             << " | Priority: " << h->data.priority
             << " | Service Time: " << h->data.serviceTime
             << " seconds\n";
        h = h->next;
    }
}

void cleanup() {
    while (front != NULL) {
        Node* t = front;
        front = front->next;
        delete t;
    }

    while (historyHead != NULL) {
        History* t = historyHead;
        historyHead = historyHead->next;
        delete t;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== CALL CENTRE SYSTEM =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Waiting Queue\n";
        cout << "4. Search Customer\n";
        cout << "5. Show Waiting Count\n";
        cout << "6. Show Call History\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: serveCustomer(); break;
            case 3: displayQueue(); break;
            case 4: searchCustomer(); break;
            case 5:
                cout << "Waiting customers: " << waiting << "\n";
                break;
            case 6: displayHistory(); break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    cleanup();
    return 0;
}
