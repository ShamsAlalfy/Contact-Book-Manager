#include <iostream>
#include "General Function.h"
#include "ContactBook.h"
using namespace std;

int main()
{
    ContactBook contacts;
    ContactBook friends;
    ContactBook work;
    ContactBook family;
    ContactBook other;
    ContactBook Fav;
    while (true)
    {
        ShowMenu();
        cout << "Enter your choice : ";
        int choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            AddContact(contacts, friends, work, family, other, Fav);
            break;
        case 2:
            SearchByName(contacts);
            break;
        case 3:
            SearchByPhoneNumber(contacts);
            break;
        case 4:
            SearchByClassification(friends, work, family, other);
            break;
        case 5:
            showAttributes();
            PrintAllContacts(contacts);
            cout << endl << endl;
            break;
        case 6:
            PrintFavContacts(Fav);
            break;
        case 7:
            SaveToFile(contacts);
            break;
        case 8:
            LoadFromFile(contacts, friends, work, family, other, Fav);
            break;
        case 9:
            DeleteContact(contacts, friends, work, family, other, Fav);
            break;
        case 10:
            UpdateContact(contacts, friends, work, family, other, Fav);
            break;
        case 11:
            ShareContact();
            break;
        case 12:
            ReverseContacts(contacts);
            break;
        case 13:
            RemoveAllContacts(contacts);
            break;
        case 14:
            system("cls");
            return 0;

        }
    }
    return 0;
}
