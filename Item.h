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
    int cost;
    string Name;
    int NumberofUsesLeft;

public:
    // default const //
    Item() : attackPower{0}, defensePower{0}, cost{0}, Name{"Uknown"}, NumberofUsesLeft{5} {}

    // Overloaded Constructors//
    Item(int a, int d, int c, int n) : attackPower{a}, defensePower{d}, cost{c}, NumberofUsesLeft{n} {}
    // Item(int a, int d, int c) : attackPower{a}, defensePower{d}, cost{c} {}
    Item(int a, int d, int n) : attackPower{a}, defensePower{d}, NumberofUsesLeft{n} {}

    // destructor
    ~Item() {}
    // copy constructor//
    Item(const Item &obj) : attackPower{obj.attackPower}, defensePower{obj.defensePower}, cost{obj.cost}, NumberofUsesLeft{obj.NumberofUsesLeft} {}
    // move const ????

    // Getters//
    int getAttackPower() { return attackPower; };
    int getdefensePower() { return defensePower; };
    int getcost() { return cost; };
    int getNumberofUsesLeft() { return NumberofUsesLeft; };
    string getName() { return Name; };

    // Setters//
    void setAttackPower(int attackPower) { this->attackPower = attackPower; };
    void setdefensePower(int defensePower) { this->defensePower = defensePower; };
    void setcost(int cost) { this->cost = cost; };
    void setNumberofUsesLeft(int NumberofUsesLeft) { this->NumberofUsesLeft = NumberofUsesLeft; };
    void setName(string Name) { this->Name = Name; };

    // output stream operator overloading
    friend ostream &operator<<(ostream &os, const Item &obj)
    {
        os << obj.Name << obj.attackPower << obj.defensePower;
        return os;
    }

    // copy asignment operator overloading
    virtual Item &operator=(const Item &s)
    {
        if (this == &s)
        {
            return *this;
        }
        else
        {
            this->attackPower = s.attackPower;
            this->defensePower = s.defensePower;
            this->cost = s.cost;
            this->Name = s.Name;
            this->NumberofUsesLeft = s.NumberofUsesLeft;
        }
    }
};

class Weapon : public Item
{
public:
    // Default Constructor//
    Weapon() : Item() {}
    // Overloaded Constructor//
    Weapon(int x, int y, int c) : Item(x, y, c) {}
};

class MagicScroll : public Item
{

private:
    int ManaCost;

public:
    // Default Constructor//
    MagicScroll() : Item(), ManaCost{0} {}

    // Overloaded Constructor
    MagicScroll(int a, int d, int n, int p) : Item(a, d, n), ManaCost{p} {}

    // getter
    int getManaCost() { return ManaCost; };
    // setter
    void setManaCost(int manaCost) { ManaCost = manaCost; };
};

class Potion : public Item
{

private:
    int healthBonus;

public:
    // Default Constructor//
    Potion() : Item(), healthBonus{25} {}

    // Getter
    int gethealthBonus() { return healthBonus; };
    // Setter
    void sethealthBonus(int healthBonus) { this->healthBonus = healthBonus; };

    // printing healthBonus
    void printHealthBonus()
    {
        
    }
};

#endif