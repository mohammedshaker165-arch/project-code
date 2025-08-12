// Subclass from person
#include "PERSON.h"

people::people() {}

people::people(std::string Id, std::string Name, std::string p)
{
    id = Id;
    name = Name;
    phone = p;
}

void people::display() const
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
}

void people::display(bool detailed) const
{
    display();
    if (detailed)
    {
        std::cout << " (Generic Person Info)" << std::endl;
    }
}

void people::update(std::string newName, std::string newPhone)
{
    name = newName;
    phone = newPhone;
}

void people::delete_person()
{
    id = "";
    name = "";
    phone = "";
    std::cout << "Generic person record deleted." << std::endl;
}

std::string people::getId() const { return id; }
std::string people::getName() const { return name; }
std::string people::getPhone() const { return phone; }
void people::setId(std::string newId) { id = newId; }
void people::setName(std::string newName) { name = newName; }
void people::setPhone(std::string newPhone) { phone = newPhone; }