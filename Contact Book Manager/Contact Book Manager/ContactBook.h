#pragma once
#include "Array.h"
#include "Person.h"
#include "Address.h"

class ContactBook
{
public:
    ContactBook();
    ContactBook(ContactBook&);
    ContactBook& operator=(ContactBook&);
    void AddElement(Person&);
    void RemoveElement(int);
    size_t SearchByName(Person&);
    size_t SearchByPhoneNumber(Person&);
    void RemoveAllContacts();
    void ReverseContacts();
    void SaveToFile();
    void DisplayContacts();
    Array<Person>& getContacts();
    ~ContactBook();
private:
    Array<Person>contacts;
};

