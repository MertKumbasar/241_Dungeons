#ifndef Item_H
#define Item_H
using namespace std;
#include "Player.h"
#include <string>

class Item
{
protected:
    int attackPower;
    int defensePower;
    int healthBonus;
    int cost;
    string Name;
public:
    // default const //
    Item():attackPower{0},defensePower{0},healthBonus{0},cost{0},Name{"Uknown"}{}
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
    int gethealthBonus() { return healthBonus; };
    int getcost() { return cost; };
    //Setters//
    void setAttackPower(int attackPower) { this->attackPower = attackPower; };
    void setdefensePower(int defensePower) { this->defensePower = defensePower; };
    void sethealthBonus(int healthBonus) { this->healthBonus = healthBonus; };
    void setcost(int cost) { this->cost = cost; };

    void virtual PrintItemStatus(void);
    //Method for Applying Item Bonuses to Player//

    //Player virtual UseItem(Player &Player);

    //Method for Negating Item Bonuses from Player//
    
    //Player virtual NegateItem(Player &Player);

    friend ostream &operator<<(ostream &os, const Item &obj);
    
    //copy asignment operator//
    virtual Item& operator=(const Item &s){
        if(this==&s){
            return *this;
        }
        else{
            this->attackPower=s.attackPower;
            this->defensePower=s.defensePower;
            this->cost=s.cost;
            this->healthBonus=s.healthBonus;
            this->Name=s.Name;


        }
    }
};


class MeleeWepon:public Item{
    private:
    int NumberofUsesLeft;
    public:
    //Default Constructor//
    MeleeWepon():Item(),NumberofUsesLeft{5}{}
    //Overloaded Constructor//
    MeleeWepon(int x,int y,int c,string n):Item(x,y,c),NumberofUsesLeft{5}{}



};


class MagicScroll:public Item{

    private:
    int NumberofUsesLeft;
    //Default Constructor//
    MagicScroll():Item(),NumberofUsesLeft{3}{}
    
    //Get//
    int getNumberofUsesLeft(){return NumberofUsesLeft;};

    //Set//
    void setNumberofUsesLeft(int NumberofUsesLeft){this->NumberofUsesLeft = NumberofUsesLeft;};

};

class Potion:public Item{

    private:
    int NumberofUsesLeft;

    //Default Constructor//
    Potion():Item(),NumberofUsesLeft{2}{}



};


#endif