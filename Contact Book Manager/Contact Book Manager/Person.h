#pragma once
#include "Address.h"
#include "Array.h"
#include <string>
using namespace std;
class Person
{
public:
    Person();
    Person(string);
    Person(string, string, string, int, int, int, Array<string>&, Array<string>&, Address&);
    Person(Person&);
    Person& operator=(Person&);
    friend ostream& operator<<(ostream&, Person&);
    bool operator>(Person&);
    bool operator==(Person&);
    void setPerson(string, string, string, int, int, int, Array<string>&, Array<string>&, Address&);
    void setPhoneNumbers(Array<string>&);
    void setMails(Array<string>&);
    string getFirstName() const;
    string getLastName() const;
    string getClassification() const;
    int getFav() const;
    int getNumOfPhoneNumbers() const;
    int getNumOfMails() const;
    Array<string> getPhoneNumbers() const;
    Array<string> getMails() const;
    Address& getAddress() ;
    ~Person();
private:
    string firstName;
    string lastName;
    int isFav;
    string classification;
    int numOfPhoneNumbers;
    Array<string> phoneNumbers;
    int numOfMails;
    Array<string> mails;
    Address address;
};
