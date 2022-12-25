#ifndef Item_H
#define Item_H
using namespace std;
#include "Player.h"
#include "player.cpp"
#include <string>

class Item
{
protected:
    int attackPower;
    int defensePower;
    int healthBonus;
    int cost;
public:
    // default const //
    Item():attackPower{0},defensePower{0},healthBonus{0},cost{0}{}
    //Overloaded Constructor//
    Item(int x,int y,int z,int k):attackPower{x},defensePower{y},healthBonus{z},cost{k}{}
    Item(int x,int y,int c):attackPower{x},defensePower{y},healthBonus{0},cost{c}{}
    // destructor
    ~Item(){}
    // copy constructor//
    Item(const Item &obj):attackPower{obj.attackPower},defensePower{obj.defensePower},healthBonus{obj.healthBonus},cost{obj.cost}{} 
    // move const ????
    //Getters//
    int getAttackPower() { return attackPower; };
    int getdefensePower() { return defensePower; };
    int gethealthIncreaser() { return healthBonus; };
    int getcost() { return cost; };
    //Setters//
    void setAttackPower(int attackPower) { this->attackPower = attackPower; };
    void setdefensePower(int defensePower) { this->defensePower = defensePower; };
    void sethealthIncreaser(int healthBonus) { this->healthBonus = healthBonus; };
    void setcost(int cost) { this->cost = cost; };

    void virtual PrintItemStatus(void);
    //Method for Applying Item Bonuses to Player//
    //Player virtual UseItem(Player &Player);
    //Method for Negating Item Bonuses from Player//
    //Player virtual NegateItem(Player &Player);

    friend ostream &operator<<(ostream &os, const Item &obj);
};


class MeleeWepon:public Item{
    private:
    string Name;
    int NumberofUsesLeft;
    public:
    //Default Constructor//
    MeleeWepon():Item(),Name{"Unknwon"},NumberofUsesLeft{0}{}
    //Overloaded Constructor//
    MeleeWepon(int x,int y,int c,string n):Item(x,y,c),Name{n},NumberofUsesLeft{5}{}




};


class MagicScroll:public Item{

    private:
    string Name;
    int NumberofUsesLeft;

};

class Potion:public Item{

    private:
    string Name;
    int NumberofUsesLeft;

};


#endif