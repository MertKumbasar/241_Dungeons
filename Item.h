#ifndef Item_H
#define Item_H
using namespace std;

class Item
{
protected:
    int attackPower;
    int defensePower;
    int healthIncreaser;
    int cost;
    int Numberofitems;
public:
    // default const
    // destructor
    // copy const
    // move const ????
    //Getters//
    int getAttackPower() { return attackPower; };
    int getdefensePower() { return defensePower; };
    int gethealthIncreaser() { return healthIncreaser; };
    int getcost() { return cost; };
    //Setters//
    void setAttackPower(int attackPower) { this->attackPower = attackPower; };
    void setdefensePower(int defensePower) { this->defensePower = defensePower; };
    void sethealthIncreaser(int healthIncreaser) { this->healthIncreaser = healthIncreaser; };
    void setcost(int cost) { this->cost = cost; };

    friend ostream &operator<<(ostream &os, const Item &obj);
};
#endif