#include "Player.h"
using namespace std;

void Player::PrintStatus(void)
{
    cout << "Your name is: " << Name << endl;
    cout << "Your score is: " << Score << endl;
    cout << "Your defense power is : " << Defense << endl;
    cout << "Your health is: " << Health << endl;
    cout << "Your attack power is: " << Attack << endl;
    cout << "Your total gold is: " << Total_Gold << endl;
    cout << "Items you have are: " << endl;
    for (int i{0}; i < nrOfItems; i++)
    {
        cout << itemsList[i];
    }
}