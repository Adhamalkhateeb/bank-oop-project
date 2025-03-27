# OOP Bank Project

## 📌 Project Overview
The **OOP Bank Project** is a comprehensive banking management system developed using **Object-Oriented Programming (OOP) principles in C++**. This project provides a structured approach to handling essential banking operations such as user authentication, client management, financial transactions, and more. It is designed to be scalable, efficient, and easy to use for bank employees and administrators.

## 🎯 Objectives
- Implement a **secure** and **efficient** banking system using OOP concepts.
- Provide a **user-friendly interface** for managing clients and transactions.
- Ensure **data integrity** through structured file handling techniques.
- Apply **role-based access control** to secure sensitive functionalities.

## 📂 Project Structure

```bash
Bank-System/
├── Core/                  # Core utilities and helpers
│   ├── clsDate.h         # Date manipulation utilities
│   ├── clsString.h       # String operations helper
│   ├── clsUtil.h         # General utilities
│   └── clsInputValidate.h # Input validation system
│
├── Entities/             # Business domain entities
│   ├── clsPerson.h       # Base person class
│   ├── clsUser.h         # User entity (derived from Person)
│   ├── clsBankClient.h   # Client banking entity
│   └── clsCurrency.h     # Currency exchange entity
│
├── Screens/              # UI components and workflows
│   ├── Clients/          # Client management screens
│   │   ├── clsAddNewClientScreen.h
│   │   ├── clsClientListScreen.h
│   │   ├── clsDeleteClientScreen.h
│   │   ├── clsUpdateClientScreen.h
│   │   └── clsFindClientScreen.h
│   │
│   ├── Transactions/     # Financial operations
│   │   ├── clsDepositionScreen.h
│   │   ├── clsWithDrawScreen.h
│   │   ├── clsTransferScreen.h
│   │   ├── clsTransferLogScreen.h
│   │   └── clsTotalBalancesScreen.h
│   │
│   ├── Users/            # User administration
│   │   ├── clsAddNewUserScreen.h
│   │   ├── clsDeleteUserScreen.h
│   │   ├── clsFindUserScreen.h
│   │   ├── clsListUsersScreen.h
│   │   ├── clsUpdateUserScreen.h
│   │   └── clsManageUsersScreen.h
│   │
│   ├── Currency/         # Currency operations
│   │   ├── clsCurrencyListScreen.h
│   │   ├── clsFindCurrencyScreen.h
│   │   ├── clsUpdateCurrencyRateScreen.h
│   │   ├── clsCurrencyCalculatorScreen.h
│   │   └── clsCurrencyExchangeMainScreen.h
│   │
│   ├── Authentication/   # Login system
│   │   ├── clsLoginScreen.h
│   │   └── clsLoginRegisterScreen.h
│   │
│   └── Main/             # Main application interface
│       └── clsMainScreen.h
│
├── main.cpp              # Application entry point
├── README.md             # Project documentation
│
└── Data/                 # Persistent data storage
    ├── Users.txt         # User credentials and permissions
    ├── Clients.txt       # Client account data
    ├── Currencies.txt    # Currency exchange rates
    ├── TransferLog.txt   # Transaction records
    └── LoginRegister.txt # Login attempt history
```

## 🚀 Features
### 🔹 User Management
- Add, update, delete, and search for users.
- Role-based authentication for administrators and employees.
- Secure login system with activity tracking.

### 🔹 Client Management
- Add, update, delete, and search for clients.
- View detailed client information including balance and transaction history.
- Validate client data to prevent errors.

### 🔹 Financial Transactions
- Deposit and withdraw funds securely.
- Transfer funds between clients within the system.
- Maintain transaction logs for auditing and reporting.

### 🔹 Currency Management
- View and manage different currencies.
- Convert between currencies based on exchange rates.

### 🔹 Security & Logging
- Secure access to financial transactions.
- Maintain logs of user actions for security auditing.

## 🛠️ Technologies Used
- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **File Handling:** Data storage using structured file formats
- **Security:** Basic authentication and access control

## 📥 Installation Guide
### Prerequisites
- A C++ compiler (e.g., **GCC**, **MSVC**, **Clang**)
- An IDE or text editor (**Visual Studio Code**, **Code::Blocks**, **Dev-C++**, **Visual Studio**)

### Steps to Install & Run
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Adhamalkhateeb/bank-oop-project.git
   ```
2. **Navigate to the Project Directory:**
   ```bash
   cd bank-oop-project
   ```
3. **Open the project in your preferred C++ IDE.**
4. **Compile the source code using your IDE or command-line tools:**
   ```bash
   g++ -o bank-oop-projectt main.cpp
   ```
5. **Run the compiled program:**
   ```bash
   ./bank-oop-project
   ```

## 📖 Usage Guide
1. **Login System:**
   - Enter credentials to access the system.
   - Role-based access restricts certain functionalities.
   - For First Time Login as User Name : Admin | Password : 123
2. **Client Management:**
   - Add new clients with personal and financial details.
   - Modify or remove clients as needed.
   - Search for clients by name or account number.
3. **Transaction System:**
   - Deposit, withdraw, and transfer funds.
   - View transaction history for auditing.
4. **User Management:**
   - Create new users and assign roles.
   - Modify user permissions and delete inactive users.
5. **Currency Management:**
   - Select preferred currency for transactions.
   - View live exchange rates and convert amounts accordingly.

### Console Output Examples
#### 🔹 Login Screen

```
________________________________________________________________________________________________________________________

                                                    Login Screen
________________________________________________________________________________________________________________________
Enter Username: Admin
Enter Password: ********
```

#### 🔹 Main Menu
```
  User: Admin
                                        Date: 27/3/2025

                                     ===========================================
                                                        Main Menu
                                     ===========================================
                                        [1] Show Client List.
                                        [2] Add New Client.
                                        [3] Delete Client.
                                        [4] Update Client Info.
                                        [5] Find Client.
                                        [6] Transactions.
                                        [7] Manage Users.
                                        [8] Login Register.
                                        [9] Currency Exchange.
                                        [10] Logout.
                                     ===========================================
                                     Choose what do you want to do? [1 to 10]?
```

#### 🔹 Adding a New Client
```
________________________________________________________________________________________________________________________

                                                  Add New Client Screen
________________________________________________________________________________________________________________________

                                        User: Admin
                                        Date: 27/3/2025


Please Enter Account Number: A123

Enter First Name? Adham

Enter last Name? Fawzy

Enter email? adham@gmail.com

Enter Phone? 010212121

Enter PinCode? 4311

Enter AccountBalance? 8000

Account Added Successfully :-)

Client Card:
________________________________
FirstName   : Adham
LastName    : Fawzy
Full Name   : Adham Fawzy
Email       : adham@gmail.com
Phone       : 010212121
Acc. Number : A123
Password    : 4311
Balance     : 8000
_______________________________

        Press any key to go back to Main Menu...
```

#### 🔹 Performing a Transaction
```
________________________________________________________________________________________________________________________

                                                  Transactions Screen
________________________________________________________________________________________________________________________

                                        User: Admin
                                        Date: 27/3/2025

                                     ===========================================
                                                  Transactions Menu
                                     ===========================================
                                        [1] Deposit.
                                        [2] Withdraw.
                                        [3] Total Balances.
                                        [4] Transfers.
                                        [5] Transfer Log.
                                        [6] Main Menu.
                                     ===========================================
                                     Choose what do you want to do? [1 to 6]?

#### 🔹 Viewing Transaction History
```
Transaction Log for Account: 123456
________________________________________________________________________________________________________________________

                                                  Transfers Log List Screen
                                                    (3) Record(s).
________________________________________________________________________________________________________________________

                                        User: Admin
                                        Date: 27/3/2025


        ________________________________________________________________________________________________

        | Date/Time                | S.Acct    | d.Acct    | Amount    | S.Balance | d.Balance | User
        ________________________________________________________________________________________________

        | 13/11/2024 - 23:1:6      | A101      | A150      | 1000      | 7000      | 51000     | uRamd
        | 15/11/2024 - 8:56:1      | A150      | A107      | 1000      | 50000     | 2234      | uRamd
        | 27/3/2025 - 14:54:34     | A103      | A150      | 200       | 3505      | 50200     | Admin

        ________________________________________________________________________________________________

```



## 📝 License
This project is licensed under the **MIT License**.

---
Feel free to contribute to enhance this project! 🚀

