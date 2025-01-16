#include "Person.h"
#include "Array.h"
#include "Address.h"
#include <iomanip>
#include <iostream>
using namespace std;
Person::Person()
{
    //ctor
}
Person::Person(string lastName)
{
    this->lastName = lastName;
}
Person::Person(string firstName, string lastName, string classification, int isFav, int numOfPhoneNumbers, int numOfMails, Array<string>& phone, Array<string>& mail, Address& address)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->isFav = isFav;
    this->classification = classification;
    this->numOfPhoneNumbers = numOfPhoneNumbers;
    this->numOfMails = numOfMails;
    setPhoneNumbers(phone);
    setMails(mail);
    this->address = address;
}
Person::Person(Person& person)
{
    this->firstName = person.firstName;
    this->lastName = person.lastName;
    this->isFav = person.isFav;
    this->classification = person.classification;
    this->numOfPhoneNumbers = person.numOfPhoneNumbers;
    this->numOfMails = person.numOfMails;
    this->phoneNumbers.Clear();
    setPhoneNumbers(person.phoneNumbers);
    this->mails.Clear();
    setMails(person.mails);
    this->address = person.address;
}
Person& Person::operator=(Person& person)
{
    if (this != &person)
    {
        this->firstName = person.firstName;
        this->lastName = person.lastName;
        this->classification = person.classification;
        this->isFav = person.isFav;
        this->numOfPhoneNumbers = person.numOfPhoneNumbers;
        this->numOfMails = person.numOfMails;
        this->phoneNumbers.Clear();
        setPhoneNumbers(person.phoneNumbers);
        this->mails.Clear();
        setMails(person.mails);
        this->address = person.address;
    }
    return *this;
}
bool Person::operator>(Person& person)
{
    return (this->firstName + this->lastName > person.firstName + person.lastName);
}
bool Person::operator==(Person& person)
{
    return (this->firstName + ' ' + this->lastName == person.lastName);
}
ostream& operator<<(ostream& COUT, Person& person)
{
    COUT << setw(20) << left << person.firstName + ' ' + person.lastName
        << setw(20) << person.classification
        << setw(20) << person.isFav
        << setw(20) << person.getAddress();
    string number = "", mail = "";
    for (size_t i = 0; i < person.phoneNumbers.getSize(); i++)
        number += person.phoneNumbers[i] + (i == person.phoneNumbers.getSize() - 1 ? ' ' : ',');
    for (size_t i = 0; i < person.mails.getSize(); i++)
        mail += person.mails[i] + ' ';
    COUT << setw(20) << number
        << setw(20) << mail;
    COUT << "\n--------------------------------------------------------------------------------------------------------------------------------------------\n";

    return COUT;
}
void Person::setPerson(string firstName, string lastName, string classification, int isFav, int numOfPhoneNumbers, int numOfMails, Array<string>& phone, Array<string>& mail, Address& address)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->isFav = isFav;
    this->classification = classification;
    this->numOfPhoneNumbers = numOfPhoneNumbers;
    this->numOfMails = numOfMails;
    setPhoneNumbers(phone);
    setMails(mail);
    this->address = address;
}

void Person::setPhoneNumbers(Array<string>& a)
{
    for (int i = 0; i < numOfPhoneNumbers; i++)
    {
        phoneNumbers.Append(a[i]);
    }
}
void Person::setMails(Array<string>& a)
{
    for (int i = 0; i < numOfMails; i++)
    {
        mails.Append(a[i]);
    }
}
string Person::getFirstName() const
{
    return firstName;
}
string Person::getLastName() const
{
    return lastName;
}
string Person::getClassification() const
{
    return classification;
}
int Person::getFav() const
{
    return isFav;
}
int Person::getNumOfPhoneNumbers() const
{
    return numOfPhoneNumbers;
}
int Person::getNumOfMails() const
{
    return numOfMails;
}
Array<string> Person::getPhoneNumbers() const
{
    return phoneNumbers;
}
Array<string> Person::getMails() const
{
    return mails;
}
Address& Person::getAddress() 
{
    return address;
}
Person::~Person()
{
    //dtor
}
