#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

void Player :: PrintStatus(Player &p1){
    cout << "Your name is: " << p1.Name << endl;
    cout << "Your score is: " << p1.Score << endl;
    cout << "Your defense power is : " << p1.Defense << endl;
    cout << "Your health is: " << p1.Health << endl;
    cout << "Your attack power is: " <<p1.Attack << endl;
    cout << "Your total gold is: " << p1.Total_Gold << endl;
    cout << "Items you have are: " << endl;
    /*for (int i{0}; i < nrOfItems; i++)
    {
        cout << itemsList[i];
    }
    */
}