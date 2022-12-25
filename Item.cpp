#include <iostream>
#include "Item.h"
using namespace std;

Item::ostream &operator<<(ostream &os, const Item &obj) // Item:: nereye yazilmasi lazim?
{
    for (int i{0}; i < obj.getLength(); i++)
    {
        os << obj.Item << " "; // duzeltin
    }
    cout << endl;
    return os;
}