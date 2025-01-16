#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Array.h"
#include "Person.h"
#include "Address.h"
#include "ContactBook.h"
void showAttributes();
void ShowMenu();
void AddContact(ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&);
void PrintAllContacts(ContactBook&);
void SearchByName(ContactBook&);
void SearchByPhoneNumber(ContactBook&);
void SearchByClassification(ContactBook&, ContactBook&, ContactBook&, ContactBook&);
void PrintFavContacts(ContactBook&);
void SaveToFile(ContactBook&);
void LoadFromFile(ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&);
void DeleteContact(ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&);
void DeleteFromClassification(int, ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&);
void UpdateContact(ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&, ContactBook&);
void ShareContact();
void ReverseContacts(ContactBook&);
void RemoveAllContacts(ContactBook&);
int toInt(string);