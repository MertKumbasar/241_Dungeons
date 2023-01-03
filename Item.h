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
    string Name;
public:
    // default const //
    Item() : attackPower{0}, defensePower{0}, Name{"Unknown"}{}

    // Overloaded Constructors//
    Item(int a, int d, string name) : attackPower{a}, defensePower{d}, Name{name} {}
    Item(int a, int d) : attackPower{a}, defensePower{d} {}
    Item(string name) : Name{name} {}

    // destructor
    ~Item() {}
    // copy constructor//
    Item(const Item &obj) : attackPower{obj.attackPower}, defensePower{obj.defensePower}{}
    // move const ????

    // Getters//
    int getAttackPower() { return attackPower; };
    int getdefensePower() { return defensePower; };
    string getName() { return Name; };

    // Setters//
    void setAttackPower(int attackPower) { this->attackPower = attackPower; };
    void setdefensePower(int defensePower) { this->defensePower = defensePower; };
    void setName(string Name) { this->Name = Name; };

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
            this->Name = s.Name;
        }
    }
};

class Weapon : public Item
{
public:
    // Default Constructor//
    Weapon() : Item() {}
    // Overloaded Constructor//
    Weapon(int a, int d, string name) : Item(a, d, name) {}

    // output stream operator overloading
    friend ostream &operator<<(ostream &os, Item &obj)
    {
        os << obj.getName()<<"  " << obj.getAttackPower()<<"  "  << obj.getdefensePower()<<endl;
        return os;
    }
};

class MagicScroll : public Item
{

private:
    int ManaCost;

public:
    // Default Constructor//
    MagicScroll() : Item(), ManaCost{0} {}

    // Overloaded Constructor
    MagicScroll(int a, int d, string name, int mc  ) : Item (a, d, name), ManaCost{mc} {}

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

    // Overloaded Constructor
    Potion(string name, int bonus) : Item(name), healthBonus{bonus}{}

    // Getter
    int gethealthBonus() { return healthBonus; };
    // Setter
    void sethealthBonus(int healthBonus) { this->healthBonus = healthBonus; };

    // printing healthBonus
    void printHealthBonus()
    {
        cout << "Health bonus of the potion is: " << healthBonus << endl;
    }
};

#endif
