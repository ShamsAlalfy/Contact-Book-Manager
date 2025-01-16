#include "General Function.h"

void ShowMenu()
{
    cout << "\t\t\t\t\t\t -------------------------------------------------------------\n"
        << "\t\t\t\t\t\t|                      Contacts Book Menu                     |\n"
        << "\t\t\t\t\t\t -------------------------------------------------------------\n"
        << "\t\t\t\t\t\t| 1. Add a new Contact                                        |\n"
        << "\t\t\t\t\t\t| 2. Search by Name                                           |\n"
        << "\t\t\t\t\t\t| 3. Search By PhoneNumber                                    |\n"
        << "\t\t\t\t\t\t| 4. Search by Classification (friend,work,family,other)?     |\n"
        << "\t\t\t\t\t\t| 5. Print All Contacts                                       |\n"
        << "\t\t\t\t\t\t| 6. Print Fav Contacts                                       |\n"
        << "\t\t\t\t\t\t| 7. Save to File                                             |\n"
        << "\t\t\t\t\t\t| 8. Load from File                                           |\n"
        << "\t\t\t\t\t\t| 9. Delete Contact                                           |\n"
        << "\t\t\t\t\t\t| 10. Update Contact Information                              |\n"
        << "\t\t\t\t\t\t| 11. Share contact with other                                |\n"
        << "\t\t\t\t\t\t| 12. Reverse contacts                                        |\n"
        << "\t\t\t\t\t\t| 13. Remove All contacts                                     |\n"
        << "\t\t\t\t\t\t| 14. Exit                                                    |\n"
        << "\t\t\t\t\t\t -------------------------------------------------------------\n";
}
void showAttributes()
{
    cout << setw(20) << left << "ID"
        << setw(20) << "Name"
        << setw(20) << "Classification"
        << setw(20) << "Fav"
        << setw(20) << "Address"
        << setw(20) << "Phone Numbers"
        << setw(20) << "Mails" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}
void AddContact(ContactBook& contacts, ContactBook& friends, ContactBook& work, ContactBook& family, ContactBook& other, ContactBook& Fav)
{
    string fname, lname, classification, contact, streetNo, street, town, state;
    int isFav;
    int numOfnumbers, numOfMails;
    cout << "First Name : ";
    cin >> fname;
    cout << "Last Name : ";
    cin >> lname;
    cout << "Class (friend,work,family,other) : ";
    cin >> classification;
    cout << "Set as Fav (Press 1 Fav or 0 (NOT)) : ";
    cin >> isFav;
    cout << "How Many Numbers ? ";
    cin >> numOfnumbers;
    Array<string> phoneNumbers;
    for (int i = 0; i < numOfnumbers; i++)
    {
        cout << "Phone#" << i + 1 << " : ";
        cin >> contact;
        phoneNumbers.Append(contact);
    }
    cout << "How Many Mails ? ";
    cin >> numOfMails;
    Array<string> mails;
    for (int i = 0; i < numOfMails; i++)
    {
        cout << "Mail#" << i + 1 << " : ";
        cin >> contact;
        if (contact.find('@') == string::npos && contact.find('.') == string::npos)
        {
            cout << "Invalid Email , Try Again " << endl;
            i--;
        }
        else
            mails.Append(contact);
    }
    cout << "----------Enter Address----------\n";
    cout << "Street Number : ";
    cin >> streetNo;
    cout << "Street Name : ";
    cin >> street;
    cout << "Town : ";
    cin >> town;
    cout << "State : ";
    cin >> state;
    Address address(streetNo, street, town, state);
    Person person(fname, lname, classification, isFav, numOfnumbers, numOfMails, phoneNumbers, mails, address);
    contacts.AddElement(person);
    if (isFav == 1)
        Fav.AddElement(person);
    if (classification == "friend")
        friends.AddElement(person);
    else if (classification == "work")
        work.AddElement(person);
    else if (classification == "family")
        family.AddElement(person);
    else if (classification == "other")
        other.AddElement(person);
}
void PrintAllContacts(ContactBook& contacts)
{
    contacts.DisplayContacts();
}
void SearchByName(ContactBook& contacts)
{
    string lname;
    cout << "Enter Name Correctly : ";
    getline(cin, lname);
    getline(cin, lname);
    cout << lname;
    Person p(lname);
    cout << endl;
    int index = contacts.SearchByName(p);
    cout << "\t\t\t--------------------------Contacts Information-------------------------------------\n";
    if (index != -1)
    {
        showAttributes();
        cout << left << setw(20) << contacts.getContacts()[index];
    }
    else
        cout << "NOT FOUND" << endl;
}
void SearchByPhoneNumber(ContactBook& contacts)
{
    string phone;
    cout << "Enter Phone Number : ";
    cin >> phone;
    Person p(phone);
    int index = contacts.SearchByPhoneNumber(p);
    cout << "\t\t\t--------------------------Contacts Information-------------------------------------\n";
    if (index != -1)
    {
        showAttributes();
        cout << left << setw(20) << contacts.getContacts()[index];

    }
    else
        cout << "NOT FOUND" << endl;
}
void SearchByClassification(ContactBook& friends, ContactBook& work, ContactBook& family, ContactBook& other)
{
    string classification;
    cout << "Enter the classification : ";
    cin >> classification;
    cout << endl;
    showAttributes();
    if (classification == "friend")
        friends.DisplayContacts();
    else if (classification == "work")
        work.DisplayContacts();
    else if (classification == "family")
        family.DisplayContacts();
    else if (classification == "other")
        other.DisplayContacts();
}
void PrintFavContacts(ContactBook& Fav)
{
    showAttributes();
    Fav.DisplayContacts();
}
void DeleteFromClassification(int index, ContactBook& contacts, ContactBook& friends, ContactBook& work, ContactBook& family, ContactBook& other, ContactBook& Fav)
{
    string classification = contacts.getContacts()[index].getClassification();
    string lname = contacts.getContacts()[index].getFirstName()+contacts.getContacts()[index].getLastName();
    Person person(lname);

    if (classification == "friend")
    {
        int indx = INT_MAX;
        for (int i = 0; i <= friends.getContacts().getSize(); i++)
        {
            if (friends.getContacts()[i] == person)
                indx = i;
            break;
        }
        if (indx != INT_MAX)
            friends.RemoveElement(indx);
        else
            cout << "NOT FOUND";
    }
    else if (classification == "work")
    {
        int indx = INT_MAX;
        for (int i = 0; i < work.getContacts().getSize(); i++)
        {
            if (work.getContacts()[i] == person)
                indx = i;
            break;
        }
        if (indx != INT_MAX)
            work.RemoveElement(indx);
        else
            cout << "NOT FOUND";
    }
    else if (classification == "family")
    {
        int indx = INT_MAX;
        for (int i = 0; i < family.getContacts().getSize(); i++)
        {
            if (family.getContacts()[i] == person)
                indx = i;
            break;
        }
        if (indx != INT_MAX)
            family.RemoveElement(indx);
        else
            cout << "NOT FOUND";
    }
    else if (classification == "other")
    {
        int indx = INT_MAX;
        for (int i = 0; i < other.getContacts().getSize(); i++)
        {
            if (other.getContacts()[i] == person)
                indx = i;
            break;
        }
        if (indx != INT_MAX)
            other.RemoveElement(indx);
        else
            cout << "NOT FOUND";
    }
    int indx = INT_MAX;
    for (int i = 0; i < Fav.getContacts().getSize(); i++)
    {
        if (Fav.getContacts()[i] == person)
            indx = i;
        break;
    }
    if (indx != INT_MAX)
        Fav.RemoveElement(indx);
    else
        cout << "NOT FOUND";
}
void DeleteContact(ContactBook& contacts, ContactBook& friends, ContactBook& work, ContactBook& family, ContactBook& other, ContactBook& Fav)
{
    int index;
    cout << "Enter the ID : ";
    cin >> index;
    index--;
    cout << index << ' ';
    DeleteFromClassification(index, contacts, friends, work, family, other, Fav);
    contacts.RemoveElement(index);
}
void UpdateContact(ContactBook& contacts, ContactBook& friends, ContactBook& work, ContactBook& family, ContactBook& other, ContactBook& Fav)
{
    int index;
    cout << "Enter the ID : ";
    cin >> index;
    index--;
    DeleteFromClassification(index, contacts, friends, work, family, other, Fav);
    string fname, lname, classification, contact, streetNo, street, town, state;
    int isFav;
    int numOfnumbers, numOfMails;
    cout << "First Name : ";
    cin >> fname;
    cout << "Last Name : ";
    cin >> lname;
    cout << "Class (friend,work,family,other) : ";
    cin >> classification;
    cout << "Set as Fav (Press 1 Fav or 0 (NOT)) : ";
    cin >> isFav;
    cout << "How Many Numbers ? ";
    cin >> numOfnumbers;
    Array<string> phoneNumbers;
    for (int i = 0; i < numOfnumbers; i++)
    {
        cout << "Phone#" << i + 1 << " : ";
        cin >> contact;
        phoneNumbers.Append(contact);
    }
    cout << "How Many Mails ? ";
    cin >> numOfMails;
    Array<string> mails;
    for (int i = 0; i < numOfMails; i++)
    {
        cout << "Mail#" << i + 1 << " : ";
        cin >> contact;
        mails.Append(contact);
    }
    cout << "----------Enter Address----------\n";
    cout << "Street Number : ";
    cin >> streetNo;
    cout << "Street Name : ";
    cin >> street;
    cout << "Town : ";
    cin >> town;
    cout << "State : ";
    cin >> state;
    Address address(streetNo, street, town, state);
    contacts.getContacts()[index].setPerson(fname, lname, classification, isFav, numOfnumbers, numOfMails, phoneNumbers, mails, address);
    if (isFav == 1)
        Fav.AddElement(contacts.getContacts()[index]);
    if (classification == "friend")
        friends.AddElement(contacts.getContacts()[index]);
    else if (classification == "work")
        work.AddElement(contacts.getContacts()[index]);
    else if (classification == "family")
        family.AddElement(contacts.getContacts()[index]);
    else if (classification == "other")
        other.AddElement(contacts.getContacts()[index]);
}
void ShareContact()
{
    cout << "Which Contact Do You Want To Share ? (index) : ";
    int index;
    cin >> index;
    cout << "Who Do You Want To Share With ? ";
    string person;
    cin >> person;
    cout << "Contact Shared Successfully :)" << endl;
}
void ReverseContacts(ContactBook& contacts)
{
    showAttributes();
    contacts.getContacts().Reverse();
    PrintAllContacts(contacts);
}
void SaveToFile(ContactBook& contacts)
{
    contacts.SaveToFile();
}
void LoadFromFile(ContactBook& contacts, ContactBook& friends, ContactBook& work, ContactBook& family, ContactBook& other, ContactBook& Fav)
{
    fstream in;
    in.open("Contacts.txt", ios::in);
    if (in.is_open())
    {
        string contactsSize, fname, lname, classification, contact, streetNo, street, town, state;
        getline(in, contactsSize);
        int Size = toInt(contactsSize);
        string isFav;
        string numOfnumbers, numOfMails;
        for (int i = 0; i < Size; i++)
        {
            getline(in, fname);
            getline(in, lname);
            getline(in, classification);
            getline(in, isFav);
            int isfav = toInt(isFav);
            getline(in, streetNo);
            getline(in, street);
            getline(in, town);
            getline(in, state);
            getline(in, numOfnumbers);
            int numofnums = toInt(numOfnumbers);
            Array<string> phoneNumbers;
            for (int j = 0; j < numofnums; j++)
            {
                getline(in, contact);
                phoneNumbers.Append(contact);
            }
            getline(in, numOfMails);
            int numofmails = toInt(numOfMails);
            Array<string> mails;
            for (int j = 0; j < numofmails; j++)
            {
                getline(in, contact);
                mails.Append(contact);
            }
            Address address(streetNo, street, town, state);
            Person person(fname, lname, classification, isfav, numofnums, numofmails, phoneNumbers, mails, address);
            contacts.AddElement(person);
            if (isfav == 1)
                Fav.AddElement(person);
            if (classification == "friend")
                friends.AddElement(person);
            else if (classification == "work")
                work.AddElement(person);
            else if (classification == "family")
                family.AddElement(person);
            else if (classification == "other")
                other.AddElement(person);
            string UnderScore;
            getline(in, UnderScore);
        }
        in.close();
    }
    cout << "Contacts Loaded Succesfully" << endl << endl;
}
void RemoveAllContacts(ContactBook& contacts)
{
    contacts.RemoveAllContacts();
}
int toInt(string value)
{
    int r = 0;
    for (int i = 0; i < value.size(); i++)
    {
        r = (value[i] - '0') + r * 10;
    }
    return r;
}
