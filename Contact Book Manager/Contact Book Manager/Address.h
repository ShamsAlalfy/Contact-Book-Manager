#pragma once
#include <string>
#include <ostream>
using namespace std;

class Address
{
public:
    Address();
    Address(string, string, string, string);
    Address(const Address&);
    Address& operator=(const Address&);
    void setAddress(string, string, string, string);
    string getStreetNumber() const;
    string getStreet() const;
    string getTown() const;
    string getState() const;
    bool operator==(Address&);
    friend ostream& operator<<(ostream&, Address&);
    ~Address();
private:
    string streetNumber;
    string street;
    string town;
    string state;
};

