#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

Node *front = NULL, *rear = NULL;

void addCustomer(int id) {
    Node* n = new Node{id, NULL};

    if (front == NULL)
        front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }

    cout << "Customer " << id << " added to queue.\n";
}

void serveCustomer() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Serving customer " << temp->id << ".\n";
    front = front->next;

    if (front == NULL) rear = NULL;
    delete temp;
}

void displayQueue() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Customers in queue: ";
    for (Node* t = front; t != NULL; t = t->next)
        cout << t->id << " ";
    cout << endl;
}

int main() {
    int choice, id;

    do {
        cout << "\n1. Add Customer\n2. Serve Customer\n"
             << "3. Display Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer ID: ";
                cin >> id;
                addCustomer(id);
                break;
            case 2: serveCustomer(); break;
            case 3: displayQueue(); break;
            case 4: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

