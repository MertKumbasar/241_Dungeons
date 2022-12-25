#include <iostream>
#include "Item.h"
using namespace std;

void Item:: PrintItemStatus(void){

    cout<<"Attack Power:"<<attackPower<<endl;
    cout<<"Defense Power:"<<defensePower<<endl;
    cout<<"Health Bonus:"<<healthBonus<<endl;
    cout<<"Cost:"<<cost<<endl;

}



// Revise//

/*ostream& operator<<(ostream &os, const Item &obj)
{
    for (size_t i=0; i<obj.Numberofitems; i++)
    {
        os <<"atack"<<obj.attackPower<<endl;    //????//
    }
    cout << endl;
    return os;
}
*/