// Base class form main code 
#ifndef CODE_H
#define CODE_H

#include "PERSON.h"
#include <string>

// ATM class
class ATM
{
public:
    void info(std::string b, int a);
    double deposit(double amount, double balance);
    double withdraw(double amount, double balance);
    void print(double balance);
    double Mobile_charging(std::string phone_number, double amount);
    double Pay_installments(std::string acc_n, double amount);
    double Insurance(std::string aco, double amount);
    double transfer(std::string acc, double amount);

private:
    std::string name;
    int account_number;
};

// employee class
class employee : public people
{
private:
    int age;
    std::string position;
    double salary;

public:
    employee();
    employee(std::string id, std::string name, std::string phone, int age, std::string pos, double sal);
    void setAge(int a);
    void setPosition(std::string pos);
    void setSalary(double sal);
    int getAge() const;
    std::string getPosition() const;
    double getSalary() const;
    void display() const override;
    void display(bool detailed) const override;
    void update(std::string newName, std::string newPhone) override;
    void update(std::string newName, std::string newPhone, std::string newPosition, double newSalary);
    void delete_person() override;
    double calculateBonus() const;
};

// customer class
class customer : public people
{
private:
    std::string accountNumber;
    double balance;
    std::string password;

public:
    customer();
    customer(std::string id, std::string name, std::string phone, std::string accNum, double bal, std::string pass);
    void setAccountNumber(std::string accNum);
    void setBalance(double bal);
    void setPassword(std::string pass);
    std::string getAccountNumber() const;
    double getBalance() const;
    std::string getPassword() const;
    void display() const override;
    void display(bool detailed) const override;
    void update(std::string newName, std::string newPhone) override;
    void update(std::string newName, std::string newPhone, double newbal, std::string newpassword);
    void delete_person() override;
    void search(std::string searchAccNumber) const;
};

#endif