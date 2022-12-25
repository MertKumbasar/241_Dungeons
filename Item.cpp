#include <iostream>
#include "Item.h"
using namespace std;

ostream& operator<<(ostream &os, const Item &obj)
{
    for (size_t i=0; i<obj.Numberofitems; i++)
    {
        os <<"atack"<<obj.attackPower<<endl;    //????//
    }
    cout << endl;
    return os;
}