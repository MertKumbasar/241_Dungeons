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

public:
    // default const
    // destructor
    // copy const
    // move const ????

    int getAttackPower() { return attackPower; };
    void setAttackPower(int attackPower) { this->attackPower = attackPower; };
    int getdefensePower() { return defensePower; };
    void setdefensePower(int defensePower) { this->defensePower = defensePower; };
    int gethealthIncreaser() { return healthIncreaser; };
    void sethealthIncreaser(int healthIncreaser) { this->healthIncreaser = healthIncreaser; };
    int getcost() { return cost; };
    void setcost(int cost) { this->cost = cost; };
};
#endif