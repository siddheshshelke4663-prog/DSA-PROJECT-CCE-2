Call Centre Queue Using Linked List

Aim

To implement a call centre queue using a singly linked list in C++.

Description

This project simulates a call centre system in which customer calls are managed using a queue. Customers are served in the order they arrive, following the FIFO (First In, First Out) principle.

Features

- Add a customer to the queue.
- Serve the next customer.
- Display all waiting customers.
- Exit the program.

Concepts Used

- C++ Programming
- Singly Linked List
- Queue Data Structure
- FIFO (First In, First Out)
- Pointers and Dynamic Memory Allocation

Working

- Each node stores a customer ID and a pointer to the next node.
- "front" points to the first customer in the queue.
- "rear" points to the last customer in the queue.
- New customers are added at the rear.
- Customers are served and removed from the front.

How to Compile and Run

Compile using a C++ compiler:

g++ main.cpp -o callcentre

Run the program:

./callcentre

On Windows, run:

callcentre.exe

Sample Output

1. Add Customer
2. Serve Customer
3. Display Queue
4. Exit
Enter choice: 1
Enter customer ID: 101
Customer 101 added to queue.

Enter choice: 3
Customers in queue: 101

Enter choice: 2
Serving customer 101.

Enter choice: 4
Exiting program.

Conclusion

This project demonstrates how a queue can be implemented using a singly linked list in C++. It helps in understanding FIFO, pointers, dynamic memory allocation, and basic queue operations.
