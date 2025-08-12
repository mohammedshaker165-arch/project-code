// Base class (person)
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class people
{
protected:
    std::string id;
    std::string name;
    std::string phone;

public:
    people();
    people(std::string id, std::string name, std::string phone);
    virtual ~people() = default;

    virtual void display() const;
    virtual void display(bool detailed) const;
    virtual void update(std::string newName, std::string newPhone);
    virtual void delete_person();

    void setId(std::string newId);
    void setName(std::string newName);
    void setPhone(std::string newPhone);
    std::string getId() const;
    std::string getName() const;
    std::string getPhone() const;
};

#endif