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
    Item(const Item &obj) : attackPower{obj.attackPower}, defensePower{obj.defensePower}, cost{obj.cost} {}
    // move const ????

    // Getters//
    int getAttackPower() { return attackPower; };
    int getdefensePower() { return defensePower; };
    int getcost() { return cost; };
    int getNumberofUsesLeft() { return NumberofUsesLeft; };

    // Setters//
    void setAttackPower(int attackPower) { this->attackPower = attackPower; };
    void setdefensePower(int defensePower) { this->defensePower = defensePower; };
    void setcost(int cost) { this->cost = cost; };
    void setNumberofUsesLeft(int NumberofUsesLeft) { this->NumberofUsesLeft = NumberofUsesLeft; };

    void virtual PrintItemStatus(void)
    {
        cout << "Item's status: " << endl;
        cout << "Name is: " << Name << ", Attack power is: " << attackPower << ", Defense power is: " << defensePower << ", Cost is: " << cost << ", Number of uses left: " << NumberofUsesLeft;
        cout << endl;
    }

    friend ostream &operator<<(ostream &os, Item &obj)
    {
        obj.PrintItemStatus();
        return os;
    }

    // copy asignment operator//
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

class MeleeWepon : public Item
{

public:
    // Default Constructor//
    MeleeWepon() : Item() {}
    // Overloaded Constructor//
    MeleeWepon(int x, int y, int c) : Item(x, y, c) {}
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
    Potion() : Item(), healthBonus{25}
    {
        NumberofUsesLeft = 2;
    }

    // Getter
    int gethealthBonus() { return healthBonus; };
    // Setter
    void sethealthBonus(int healthBonus) { this->healthBonus = healthBonus; };

    //
};

#endif