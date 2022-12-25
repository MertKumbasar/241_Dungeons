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
    // default const //
    Item():attackPower{0},defensePower{0},healthIncreaser{0},cost{0}{}
    //Overloaded Constructor//
    Item(int x,int y,int z,int k):attackPower{x},defensePower{y},healthIncreaser{z},cost{k}{}
    // destructor
    ~Item(){}
    // copy constructor//
    Item(const Item &obj):attackPower{obj.attackPower},defensePower{obj.defensePower},healthIncreaser{obj.healthIncreaser},cost{obj.cost}{} 
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


class MeleeWepon:public Item{



};


class MagicScroll:public Item{



};


#endif