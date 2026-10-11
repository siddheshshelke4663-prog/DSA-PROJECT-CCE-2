#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void addCustomer(int id) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
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

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

void displayQueue() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Customers in queue: ";

    while (temp != NULL) {
        cout << temp->id << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int choice, id;

    do {
        cout << "\n1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer ID: ";
                cin >> id;
                addCustomer(id);
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
