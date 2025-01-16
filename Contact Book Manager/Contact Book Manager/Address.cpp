#include "Address.h"
#include <iomanip>
Address::Address()
{
    streetNumber = street = town = state = "";
}
Address::Address(string streetNumber, string street, string town, string state)
{
    this->streetNumber = streetNumber;
    this->street = street;
    this->town = town;
    this->state = state;
}
Address::Address(const Address& address)
{
    this->streetNumber = address.streetNumber;
    this->street = address.street;
    this->town = address.town;
    this->state = address.state;
}
Address& Address::operator=(const Address& address)
{
    if (this != &address)
    {
        this->streetNumber = address.streetNumber;
        this->street = address.street;
        this->town = address.town;
        this->state = address.state;
    }
    return *this;
}
void Address::setAddress(string streetNumber, string street, string town, string state)
{
    this->streetNumber = streetNumber;
    this->street = street;
    this->town = town;
    this->state = state;
}
string Address::getStreetNumber() const
{
    return streetNumber;
}
string Address::getStreet() const
{
    return street;
}
string Address::getTown() const
{
    return town;
}
string Address::getState() const
{
    return state;
}
bool Address::operator==(Address& address)
{
    return (streetNumber == address.streetNumber &&
        street == address.street &&
        town == address.town &&
        state == address.state);
}
ostream& operator<<(ostream& COUT, Address& address)
{
    string a = address.streetNumber + ','
        + address.street + ','
        + address.town + ','
        + address.state;
    COUT << a;
    return COUT;
}
Address::~Address()
{
    //dtor
}
