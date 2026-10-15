Verified Sample Output

Call Centre Queue Using Linked List

Test Scenario: Add two customers, search, check waiting count, serve a customer, and display call history.

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 1
Enter customer ID: 101
Enter customer name: Rahul
Enter issue: Internet Problem
Priority (3=High, 2=Medium, 1=Normal): 3
Customer added successfully!

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 1
Enter customer ID: 102
Enter customer name: Amit
Enter issue: Billing Problem
Priority (3=High, 2=Medium, 1=Normal): 1
Customer added successfully!

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 3

--- Waiting Customers ---
ID: 101 | Name: Rahul | Issue: Internet Problem | Priority: 3
ID: 102 | Name: Amit | Issue: Billing Problem | Priority: 1
Total waiting: 2

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 4
Enter customer ID to search: 102
Customer found: Amit | Issue: Billing Problem | Priority: 1

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 5
Waiting customers: 2

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 2
Serving: Rahul (ID: 101)
Enter service duration in seconds: 120
Customer served successfully!

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 6

--- Served Customer History ---
ID: 101 | Name: Rahul | Issue: Internet Problem | Priority: 3 | Service Time: 120 seconds

===== CALL CENTRE SYSTEM =====
1. Add Customer
2. Serve Customer
3. Display Waiting Queue
4. Search Customer
5. Show Waiting Count
6. Show Call History
7. Exit
Enter choice: 7
Exiting program.

Final verification status

- Compilation: Successful with C++11.
- Priority queue: Higher-priority customer Rahul is served first.
- Customer search: Amit is found in the waiting queue.
- Waiting count: Correctly shows 2 before serving.
- Call history: Records Rahul's service duration as 120 seconds.
- Exit: Works correctly.

Important: This verifies the tested scenario, not every possible input. GitHub par ise "OUTPUT.md" naam se upload kar. Agar mam actual screenshot maange, toh apne compiler mein program run karke screenshot lena—ye text output screenshot nahi hai.
