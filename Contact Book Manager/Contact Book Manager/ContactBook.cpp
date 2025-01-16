#include "ContactBook.h"
#include <fstream>
#include <iomanip>

ContactBook::ContactBook()
{
    //ctor
}
ContactBook::ContactBook(ContactBook& contactBook)
{
    for (size_t i = 0; i < contactBook.contacts.getSize(); i++)
    {
        this->contacts.Append(contactBook.contacts[i]);
    }
}
ContactBook& ContactBook::operator=(ContactBook& contactBook)
{
    if (this != &contactBook)
    {
        for (int i = 0; i < contactBook.contacts.getSize(); i++)
        {
            this->contacts[i] = contactBook.contacts[i];
        }
        return *this;
    }
}
void ContactBook::AddElement(Person& person)
{
    contacts.Append(person);
    contacts.sort();
}
void ContactBook::RemoveElement(int index)
{
    if (index == contacts.getSize() - 1)
        contacts.Remove();
    else
        contacts.Delete(index);
}
size_t ContactBook::SearchByName(Person& person)
{
    return contacts.search(person);
}
size_t ContactBook::SearchByPhoneNumber(Person& person)
{
    for (int i = 0; i < contacts.getSize(); i++)
    {
        for (int j = 0; j < contacts[i].getNumOfPhoneNumbers(); j++)
        {
            if (person.getLastName() == contacts[i].getPhoneNumbers()[j])
                return i;
        }
    }
    return -1;
}
void ContactBook::RemoveAllContacts()
{
    contacts.Clear();
    cout << "All Contacts has been removed" << endl;
}
void ContactBook::ReverseContacts()
{
    contacts.Reverse();
}
void ContactBook::SaveToFile()
{
    fstream out;
    out.open("Contacts.txt", ios::out);
    if (out.is_open())
    {
        out << contacts.getSize() << endl;
        for (int i = 0; i < contacts.getSize(); i++)
        {
            out << contacts[i].getFirstName() << endl
                << contacts[i].getLastName() << endl
                << contacts[i].getClassification() << endl
                << contacts[i].getFav() << endl
                << contacts[i].getAddress().getStreetNumber() << endl
                << contacts[i].getAddress().getStreet() << endl
                << contacts[i].getAddress().getTown() << endl
                << contacts[i].getAddress().getState() << endl
                << contacts[i].getNumOfPhoneNumbers() << endl;
            for (int j = 0; j < contacts[i].getNumOfPhoneNumbers(); j++)
                out << contacts[i].getPhoneNumbers()[j] << endl;
            out << contacts[i].getNumOfMails() << endl;
            for (int j = 0; j < contacts[i].getNumOfMails(); j++)
                out << contacts[i].getMails()[j] << endl;
            out << "-------------------------------------------------------------------------------" << endl;
        }
        out.close();
    }
    cout << "Contacts Saved Succesfully " << endl << endl;
}

void ContactBook::DisplayContacts()
{
    for (int i = 0; i < contacts.getSize(); i++)
        cout << setw(20) << i + 1 << contacts[i];
}
Array<Person>& ContactBook::getContacts()
{
    return contacts;
}
ContactBook::~ContactBook()
{
    //dtor
}
