// Sub class form main code
#include "CODE.h"
#include "PERSON.h"
#include <iostream>
#include <string>

// ATM class
void ATM::info(std::string b, int a)
{
    name = b;
    account_number = a;
    std::cout << "##the name is " << name << std::endl
              << "##the account number is " << account_number << std::endl;
}

double ATM::deposit(double amount, double balance)
{
    balance += amount;
    std::cout << "##the deposit is done " << std::endl;
    std::cout << "##the new balance is " << balance << std::endl;
    return balance;
}

double ATM::withdraw(double amount, double balance)
{
    if (amount > balance)
    {
        std::cout << "##Insufficient balance!!" << std::endl;
        return balance;
    }
    balance -= amount;
    std::cout << "##the withdraw is done " << std::endl;
    std::cout << "##the new balance is " << balance << std::endl;
    return balance;
}

double ATM::Mobile_charging(std::string phone_number, double amount)
{
    std::cout << "##the charging to " << phone_number << " done with " << amount << " $" << std::endl;
    return amount;
}

double ATM::Pay_installments(std::string acc_n, double amount)
{
    std::cout << "##the pay to " << acc_n << " done with " << amount << " $" << std::endl;
    return amount;
}

double ATM::Insurance(std::string aco, double amount)
{
    std::cout << "##the insurance to " << aco << " done with " << amount << " $" << std::endl;
    return amount;
}

double ATM::transfer(std::string acc, double amount)
{
    std::cout << "##the transfer to " << acc << " done with " << amount << " $" << std::endl;
    return amount;
}

void ATM::print(double balance)
{
    std::cout << "##the balance is " << balance << std::endl;
}

// employee class
employee::employee() {}
employee::employee(std::string id, std::string name, std::string phone, int a, std::string pos, double sal)
    : people(id, name, phone), age(a), position(pos), salary(sal) {}

void employee::setAge(int a) { age = a; }
void employee::setPosition(std::string pos) { position = pos; }
void employee::setSalary(double sal) { salary = sal; }
int employee::getAge() const { return age; }
std::string employee::getPosition() const { return position; }
double employee::getSalary() const { return salary; }

void employee::display() const
{
    people::display();
    std::cout << "Age: " << age << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Salary: " << salary << std::endl;
}

void employee::display(bool detailed) const
{
    display();
    if (detailed)
    {
        std::cout << " (Employee Details)" << std::endl;
    }
}

void employee::update(std::string newName, std::string newPhone)
{
    people::update(newName, newPhone);
    std::cout << "Employee name and phone updated." << std::endl;
}

void employee::update(std::string newName, std::string newPhone, std::string newPosition, double newSalary)
{
    people::update(newName, newPhone);
    position = newPosition;
    salary = newSalary;
    std::cout << "The information of employee updated" << std::endl;
}

void employee::delete_person()
{
    setId("");
    setName("");
    setPhone("");
    age = 0;
    position = "";
    salary = 0.0;
    std::cout << "This employee has been removed." << std::endl;
}

double employee::calculateBonus() const { return salary * 0.10; }

// customer class
customer::customer() {}
customer::customer(std::string id, std::string name, std::string phone, std::string accNum, double bal, std::string pass)
    : people(id, name, phone), accountNumber(accNum), balance(bal), password(pass) {}

void customer::setAccountNumber(std::string accNum) { accountNumber = accNum; }
void customer::setBalance(double bal) { balance = bal; }
void customer::setPassword(std::string pass) { password = pass; }
std::string customer::getAccountNumber() const { return accountNumber; }
double customer::getBalance() const { return balance; }
std::string customer::getPassword() const { return password; }

void customer::display() const
{
    people::display();
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

void customer::display(bool detailed) const
{
    display();
    if (detailed)
    {
        std::cout << " (Customer Details)" << std::endl;
    }
}

void customer::update(std::string newName, std::string newPhone)
{
    people::update(newName, newPhone);
    std::cout << "Customer name and phone updated." << std::endl;
}

void customer::update(std::string newName, std::string newPhone, double newbal, std::string newpassword)
{
    people::update(newName, newPhone);
    balance = newbal;
    password = newpassword;
    std::cout << "Customer with accountNumber " << getAccountNumber() << " updated." << std::endl;
}

void customer::delete_person()
{
    std::string deletedAcc = accountNumber;
    setId("");
    setName("");
    setPhone("");
    accountNumber = "";
    balance = 0.0;
    password = "";
    std::cout << "Customer with account " << deletedAcc << " has been removed." << std::endl;
}

void customer::search(std::string searchAccNumber) const
{
    if (getAccountNumber() == searchAccNumber)
    {
        std::cout << "Customer found" << std::endl;
        display();
    }
    else
    {
        std::cout << "Customer with account number " << searchAccNumber << " not found." << std::endl;
    }
}