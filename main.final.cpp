// main code 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "CODE.h"
#include "PERSON.h"
using namespace std;

// --- Helper functions to save and load customer and employee data ---

void saveCustomersToFile(const vector<customer> &customers, const string &filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        for (const auto &cust : customers)
        {
            outFile << cust.getId() << ","
                    << cust.getName() << ","
                    << cust.getPhone() << ","
                    << cust.getAccountNumber() << ","
                    << cust.getBalance() << ","
                    << cust.getPassword() << "\n";
        }
        outFile.close();
        cout << "Customer data saved successfully!" << endl;
    }
    else
    {
        cerr << "Error: Failed to open customer file for saving." << endl;
    }
}

vector<customer> loadCustomersFromFile(const string &filename)
{
    vector<customer> customers;
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            stringstream ss(line);
            string id, name, phone, accNum, password, balanceStr;
            double bal;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, accNum, ',');
            getline(ss, balanceStr, ',');
            getline(ss, password, ',');

            try
            {
                bal = stod(balanceStr);
                customers.push_back(customer(id, name, phone, accNum, bal, password));
            }
            catch (const invalid_argument &e)
            {
                cerr << "Error converting balance for customer: " << id << ". Line ignored." << endl;
            }
        }
        inFile.close();
        cout << "Customer data loaded successfully!" << endl;
    }
    else
    {
        cout << "No customer data file found, a new file will be created when saving." << endl;
    }
    return customers;
}

void saveEmployeesToFile(const vector<employee> &employees, const string &filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        for (const auto &emp : employees)
        {
            outFile << emp.getId() << ","
                    << emp.getName() << ","
                    << emp.getPhone() << ","
                    << emp.getAge() << ","
                    << emp.getPosition() << ","
                    << emp.getSalary() << "\n";
        }
        outFile.close();
        cout << "Employee data saved successfully!" << endl;
    }
    else
    {
        cerr << "Error: Failed to open employee file for saving." << endl;
    }
}

vector<employee> loadEmployeesFromFile(const string &filename)
{
    vector<employee> employees;
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            stringstream ss(line);
            string id, name, phone, position, ageStr, salaryStr;
            int age;
            double salary;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, ageStr, ',');
            getline(ss, position, ',');
            getline(ss, salaryStr, ',');

            try
            {
                age = stoi(ageStr);
                salary = stod(salaryStr);
                employees.push_back(employee(id, name, phone, age, position, salary));
            }
            catch (const invalid_argument &e)
            {
                cerr << "Error converting employee data for: " << id << ". Line ignored." << endl;
            }
        }
        inFile.close();
        cout << "Employee data loaded successfully!" << endl;
    }
    else
    {
        cout << "No employee data file found, a new file will be created when saving." << endl;
    }
    return employees;
}

// --------------------- Main Code ---------------------

int main()
{
    int choice;
    cout << "enter your service: " << endl;
    cout << "1.The bank services" << endl;
    cout << "2.The ATM" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int cho;
        cout << "1.client" << endl;
        cout << "2.employees and staff" << endl;
        cout << "3.Exit Bank Services" << endl;
        cout << "Enter your choice: ";
        cin >> cho;

        switch (cho)
        {
        case 1:
        {
            string client_password;
            cout << "Enter client password: ";
            cin >> client_password;
            if (client_password != "5678")
            {
                cout << "Incorrect password. Access denied." << endl;
                break;
            }

            vector<customer> customers = loadCustomersFromFile("customers.txt");
            if (customers.empty())
            {
                customers.push_back(customer("3001101", "Ahmed Mohamed", "01012345678", "1101", 1500.50, "2101"));
                customers.push_back(customer("3001102", "Fatma Ali", "01123456789", "1102", 2500.75, "2102"));
                customers.push_back(customer("3001103", "Mahmoud Hassan", "01234567890", "1103", 500.00, "2103"));
                customers.push_back(customer("3001104", "Aisha Ibrahim", "01501234567", "1104", 3000.20, "2104"));
                customers.push_back(customer("3001105", "Khaled Ahmed", "01098765432", "1105", 1000.00, "2105"));
                customers.push_back(customer("3001106", "Sara Tarek", "01187654321", "1106", 4500.90, "2106"));
                customers.push_back(customer("3001107", "Mostafa Gamal", "01276543210", "1107", 200.50, "2107"));
                customers.push_back(customer("3001108", "Nourhan Walid", "01590123456", "1108", 5000.00, "2108"));
                customers.push_back(customer("3001109", " Amr reda", "01001122334", "1109", 750.25, "2109"));
                customers.push_back(customer("3001110", "Hoda Samir", "01112233445", "1110", 1800.00, "2110"));
            }

            cout << "Welcome to our Banking System!" << endl;
            bool run = true;
            while (run)
            {
                cout << "\n ==choose an operation==" << endl;
                cout << "1. Add New Customer" << endl;
                cout << "2. Search Customer by Account Number" << endl;
                cout << "3. Delete Customer by Account Number" << endl;
                cout << "4. Update Customer Details" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";

                int customer_choice;
                cin >> customer_choice;
                cin.ignore();

                switch (customer_choice)
                {
                case 1:
                {
                    string id, name, phone, accNum, password;
                    double bal;
                    cout << "\nEnter Customer Details:" << endl;
                    cout << "Enter ID: ";
                    cin >> id;
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Phone: ";
                    cin >> phone;
                    cout << "Enter Account Number: ";
                    cin >> accNum;
                    cout << "Enter Initial Balance: ";
                    cin >> bal;
                    cout << "Enter Password: ";
                    cin >> password;
                    customers.push_back(customer(id, name, phone, accNum, bal, password));
                    cout << "\nCustomer added successfully!" << endl;
                    break;
                }
                case 2:
                {
                    string searchAccNum;
                    cout << "\nEnter Account Number to search: ";
                    cin >> searchAccNum;
                    bool found = false;
                    for (const auto &cust : customers)
                    {
                        if (cust.getAccountNumber() == searchAccNum)
                        {
                            cout << "\n--- Customer Details ---" << endl;
                            cust.display();
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "\nCustomer with account number " << searchAccNum << " not found." << endl;
                    }
                    break;
                }
                case 3:
                {
                    string deleteAccNum;
                    cout << "\nEnter Account Number to delete: ";
                    cin >> deleteAccNum;
                    bool found = false;
                    for (auto it = customers.begin(); it != customers.end(); ++it)
                    {
                        if (it->getAccountNumber() == deleteAccNum)
                        {
                            customers.erase(it);
                            found = true;
                            cout << "Customer with account number " << deleteAccNum << " has been removed." << endl;
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "\nCustomer with account number " << deleteAccNum << " not found." << endl;
                    }
                    break;
                }
                case 4:
                {
                    string accNum;
                    cout << "\nEnter Account Number to update: ";
                    cin >> accNum;
                    bool found = false;
                    for (auto &cust : customers)
                    {
                        if (cust.getAccountNumber() == accNum)
                        {
                            string newName, newPhone, newPass;
                            double newBal;
                            cout << "Enter new name: ";
                            cin.ignore();
                            getline(cin, newName);
                            cout << "Enter new phone: ";
                            cin >> newPhone;
                            cout << "Enter new balance: ";
                            cin >> newBal;
                            cout << "Enter new password: ";
                            cin >> newPass;
                            cust.update(newName, newPhone, newBal, newPass);
                            cout << "Customer details updated successfully!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "Customer not found!" << endl;
                    }
                    break;
                }
                case 5:
                {
                    saveCustomersToFile(customers, "customers.txt");
                    cout << "\nExiting system. Goodbye!" << endl;
                    run = false;
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please select a valid option (1-5)." << endl;
                }
                }
            }
            break;
        }
        case 2:
        {
            string employee_password;
            cout << "Enter employee password: ";
            cin >> employee_password;
            if (employee_password != "1234")
            {
                cout << "Incorrect password. Access denied." << endl;
                break;
            }

            vector<employee> employees = loadEmployeesFromFile("employees.txt");
            if (employees.empty())
            {
                employees.push_back(employee("a001", "mohammed", "01061365920", 20, "manager", 20000.5));
                employees.push_back(employee("a002", "Ahmed", "01112223333", 25, "Developer", 15000.0));
                employees.push_back(employee("a003", "Sara", "01234567890", 30, "Senior Analyst", 25000.75));
                employees.push_back(employee("a004", "Ali", "01555556666", 22, "Tester", 12000.50));
                employees.push_back(employee("a005", "Heba", "01098765432", 28, "Team Lead", 30000.20));
                employees.push_back(employee("a006", "Khaled", "01100001111", 35, "Architect", 40000.0));
                employees.push_back(employee("a007", "Nour", "01212123456", 21, "Junior Dev", 10000.90));
                employees.push_back(employee("a008", "Omar", "01565657890", 27, "UX Designer", 18000.0));
                employees.push_back(employee("a009", "Mai", "01033334444", 32, "Project Manager", 35000.50));
                employees.push_back(employee("a010", "You", "01144440000", 24, "Database Admin", 22000.0));
                employees.push_back(employee("a012", "Youss", "01144440011", 26, "Supervisor", 22000.0));
                employees.push_back(employee("a013", "Yousse", "01144440111", 27, "Security ", 22000.0));
                employees.push_back(employee("a014", "Youssef", "01144441111", 28, "sanitation worker", 22000.0));
            }

            int employee_choice;
            do
            {
                cout << "\n--- Employee Management System ---\n";
                cout << "1. Show All Employees and staff\n";
                cout << "2. Show Employee or staff by Index\n";
                cout << "3. Modify Employee or staff\n";
                cout << "4. Calculate Bonus\n";
                cout << "5. delete employee\n";
                cout << "6. Exit Employee Management\n";
                cout << "Enter your choice: ";
                cin >> employee_choice;

                int index;
                switch (employee_choice)
                {
                case 1:
                    for (size_t i = 0; i < employees.size(); i++)
                    {
                        cout << "\nEmployee or staff #" << i + 1 << ":\n";
                        employees[i].display();
                    }
                    break;
                case 2:
                    cout << "Enter index (0 to " << employees.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < employees.size())
                    {
                        employees[index].display();
                    }
                    else
                    {
                        cout << "Invalid index!\n";
                    }
                    break;
                case 3:
                    cout << "Enter index (0 to " << employees.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < employees.size())
                    {
                        string newPos;
                        double newSal;
                        cout << "New position: ";
                        cin.ignore();
                        getline(cin, newPos);
                        cout << "New salary: ";
                        cin >> newSal;
                        employees[index].setPosition(newPos);
                        employees[index].setSalary(newSal);
                        cout << "Employee details updated successfully!" << endl;
                    }
                    else
                    {
                        cout << "Invalid index!\n";
                    }
                    break;
                case 4:
                    cout << "Enter index (0 to " << employees.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < employees.size())
                    {
                        cout << "Bonus: " << employees[index].calculateBonus() << "\n";
                    }
                    else
                    {
                        cout << "Invalid index!\n";
                    }
                    break;
                case 5:
                    cout << "Enter index (0 to " << employees.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < employees.size())
                    {
                        employees.erase(employees.begin() + index);
                        cout << "Employee with index " << index << " has been removed.\n";
                    }
                    else
                    {
                        cout << "Invalid index!\n";
                    }
                    break;
                case 6:
                    cout << "Exiting Employee Management.\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (employee_choice != 6);
            saveEmployeesToFile(employees, "employees.txt");
            break;
        }
        case 3:
        {
            cout << "Exiting Bank Services." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice for bank services!" << endl;
            break;
        }
        break;
    }
    case 2:
    {
        string p = "1152006";
        string current_password;
        int attempts = 0;
        bool access_granted = false;

        while (attempts < 3)
        {
            cout << "Enter the ATM password: " << endl;
            cin >> current_password;
            if (current_password == p)
            {
                access_granted = true;
                break;
            }
            else
            {
                attempts++;
                cout << "Incorrect password. You have " << 3 - attempts << " attempts left." << endl;
            }
        }

        if (access_granted)
        {
            double balance = 10000;
            double amount = 0;
            ATM t;
            t.info("mohammed", 14799);
            int choice2;
            double b;

            do
            {
                cout << "\nChoose an operation:" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Show balance" << endl;
                cout << "4. Payments" << endl;
                cout << "5. Money transfer" << endl;
                cout << "6. Change Password" << endl;
                cout << "7. Exit ATM" << endl;
                cout << "Enter your choice: ";
                cin >> choice2;

                if (choice2 == 1 || choice2 == 2)
                {
                    cout << "Enter the amount: ";
                    cin >> amount;
                    b = amount;
                }

                switch (choice2)
                {
                case 1:
                    balance = t.deposit(b, balance);
                    break;
                case 2:
                    balance = t.withdraw(b, balance);
                    break;
                case 3:
                    t.print(balance);
                    break;
                case 4:
                {
                    int choice_payment;
                    cout << "1. Mobile charging" << endl;
                    cout << "2. Pay installments" << endl;
                    cout << "3. Insurance" << endl;
                    cout << "Enter your payment option: ";
                    cin >> choice_payment;

                    if (choice_payment == 1 || choice_payment == 2 || choice_payment == 3)
                    {
                        cout << "Enter the amount: ";
                        cin >> amount;
                    }
                    switch (choice_payment)
                    {
                    case 1:
                    {
                        string phone_number;
                        cout << "Enter your number: ";
                        cin >> phone_number;

                        t.Mobile_charging(phone_number, amount);
                        break;
                    }
                    case 2:
                    {
                        string acc_n;
                        cout << "Enter the account number: ";
                        cin >> acc_n;
                        t.Pay_installments(acc_n, amount);
                        break;
                    }
                    case 3:
                    {
                        string aco;
                        cout << "Enter the account number: ";
                        cin >> aco;
                        t.Insurance(aco, amount);
                        break;
                    }
                    default:
                        cout << "Invalid payment option!" << endl;
                        break;
                    }
                    break;
                }
                case 5:
                {
                    string acc;
                    cout << "Enter the recipient account number: ";
                    cin >> acc;
                    double transfer_amount;
                    cout << "Enter the amount you want to transfer: ";
                    cin >> transfer_amount;
                    t.transfer(acc, transfer_amount);
                    break;
                }
                case 6:
                {
                    cout << "Password change not implemented in this version." << endl;
                    break;
                }
                case 7:
                    cout << "Thank you for using the ATM!" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            } while (choice2 != 7);
        }
        else
        {
            cout << "Maximum attempts reached. Exiting ATM." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice. Exiting." << endl;
        break;
    }
    return 0;
}