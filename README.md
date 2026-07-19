# ELECTRICITY-BILLING-SYSTEM
Electricity Billing System in C featuring secure admin login, customer record management, electricity bill calculation, payment tracking, and persistent data storage using binary files.
----------------------------------
# Features

# 1.Authentication
* Admin Sign Up
* Admin Login
* Username uniqueness verification
* Three login attempts for security

# 2.Customer Management
* Add new customer
* View all customers
* Search customer by Consumer ID
* Modify customer details
* Delete customer records

# 3.Billing Management
* Generate electricity bill using meter readings
* Automatic unit consumption calculation
* Slab-wise electricity tariff calculation
* Display payment status (Paid/Pending)

# 4.Payment System
* Pay generated bills
* Prevent duplicate payments
* Update payment status automatically

# 5.Bill History
* Display complete billing history
* View units consumed
* View bill amount
* View payment status
--------------------------------
## Technologies Used

* **Language:** C
* **Compiler:** GCC / Code::Blocks / Dev-C++
* **Storage:** Binary Files 
* **Programming Concepts**:
  * Structures
  * Functions
  * Header Files
  * Modular Programming
  * File Handling
  * Conditional Statements
  * Loops
  * Menu-Driven Programming
-------------------------------------

## Project Structure
Electricity-Billing-System/
│
├── main.c              # Main menu and program flow
├── login.c             # Admin signup and login
├── login.h
│
├── customer.c          # Customer management
├── customer.h
│
├── billing.c           # Billing operations
├── billing.h
│
├── admin.dat           # Stores admin credentials
├── customers.dat       # Stores customer records
│
└── README.md

------------------------------
## Menu

### Main Menu
```text
1. Sign Up
2. Login
3. Exit
```

### After Login
```text
1. Add Customer
2. View Customers
3. Search Customer
4. Modify Customer
5. Delete Customer
6. Generate Bill
7. Pay Bill
8. Bill History
9. Exit
```
-----------------------------

## Billing Calculation
The bill is calculated using the difference between the current and previous meter readings.
```text
Units Consumed = Current Reading − Previous Reading
```

### Tariff Slabs
| Units     | Rate       |
| --------- | ---------- |
| 0–100     | ₹1.50/unit |
| 101–200   | ₹2.50/unit |
| 201–300   | ₹4.00/unit |
| Above 300 | ₹6.00/unit |

### Example
```text
Previous Reading : 150
Current Reading  : 280

Units Consumed   : 130

Bill Amount

100 × 1.50 = 150
30 × 2.50  = 75

Total = ₹225
```
------------------------------
## Data Storage

The project uses binary files for permanent storage.

| File          | Purpose                                         |
| ------------- | ----------------------------------------------- |
| admin.dat     | Stores admin username and password              |
| customers.dat | Stores customer records and billing information |

Each customer record stores:
* Consumer ID
* Customer Name
* Address
* Phone Number
* Previous Reading
* Current Reading
* Units Consumed
* Bill Amount
* Payment Status

--------------------
## Future Improvements

* Password encryption
* Monthly bill generation
* GST and fixed charges
* Due date and late payment penalty
* Receipt generation
* Electricity consumption reports
--------------------

## How to Run:

### Compile
```bash
gcc main.c login.c customer.c billing.c -o billing_system
```

### Execute
```bash
./billing_system
```

For Code::Blocks or Dev-C++, create a new project, add all source (`.c`) and header (`.h`) files, build the project, and run the executable.
