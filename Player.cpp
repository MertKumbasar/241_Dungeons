#include "Player.h"
using namespace std;

void Player::PrintStatus(void)
{
    cout << "Your name is: " << this->Name << endl;
    cout << "Your score is: " << this->Score << endl;
    cout << "Your defense power is : " << this->Defense << endl;
    cout << "Your health is: " << this->Health << endl;
    cout << "Your attack power is: " << this->Attack << endl;
    cout << "Your total gold is: " << this->Total_Gold << endl;
    cout << "Items you have are: " << endl;
    /*for (int i{0}; i < nrOfItems; i++)
    {
        cout << itemsList[i];
    }
    */
}