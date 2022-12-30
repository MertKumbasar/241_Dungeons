
#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "Enemy.h"
#include "Item.h"
using namespace std;

class Player : public Entity
{

public:
    // Default Constructor//
    Player() : Entity(){};

    // Overloaded Constructors//

    // Copy constructor//

    // Destructor//

    // function for printing player status//
    void PrintStatus(Player &p1)
    {
        cout << "Your name is: " << p1.Name << endl;
        cout << "Your score is: " << p1.Score << endl;
        cout << "Your defense power is : " << p1.Defense << endl;
        cout << "Your health is: " << p1.Health << endl;
        cout << "Your attack power is: " << p1.Attack << endl;
        cout << "Your total gold is: " << p1.Total_Gold << endl;
        cout << "Items you have are: " << endl;
        /*for (int i{0}; i < nrOfItems; i++)
        {
            cout << itemsList[i];
        }
        */
    }
    // Move method//

    // method to use MeleeWepon for attack and defense
    void UseItem(MeleeWepon &meleeWepon)
    {
        this->Attack += meleeWepon.getAttackPower();
        this->Defense += meleeWepon.getdefensePower();
    }

    // method to use Potion for health
    void UsePotion(Potion &potion)
    {
        this->Health += potion.gethealthBonus();
    }

    // Attack method virtual//
    virtual void battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice;
        string Escape;

        // Display available attack options for the player
        cout << "Choose your attack:" << endl;
        cout << "1. Basic Attack" << endl;
        cout << "2. Special Attack" << endl; // speacil attack bizim heroya bağlı olabilir böylece
        cout << "3. Defend" << endl;
        cin >> choice;

        while (e.GetHealth() > 0 && Health > 0)
        {

            if (choice == 1)
            { // Basic attack

                damage = 1 + (rand() % Attack);
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl;
            }
            else if (choice == 2)
            { // Special attack

                damage = 2 + (rand() % (Attack + 5)); // item a bağlı bir artış burada olabilir ya da speller, player type a göre
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl;
            }

            else if (choice == 3)
            {                 // Defend
                Defense += 2; // burdan pek enim değilim defend için daha mantıklı bir şey olabilir defense random değişebilir gibi
                cout << "Player defended and increased Defense by 2." << endl;
            }

            // Enemy turn
            if (e.GetHealth() > 0)
            {
                damage = 1 + (rand() % e.GetAttack());
                Defense = 1 + (rand() % e.GetDefense());
                Health = Health - (Defense - damage);
                cout << "Enemy dealt: " << damage << " damage. Player blocked " << Defense << " damage. Player's current Health is: " << Health << endl;
            }

            if (Health < 30 && e.GetHealth() > 30)
            {
                cout << "Your Healt is: " << Health << endl
                     << "Enemy's health  is: " << e.GetHealth() << endl;
                cout << "Would you like to RUN AWAY!??" << endl;
                cout << "Yes or NO (DO NO TRY TO RUN!):" << endl;
                cin >> Escape;
                if (Escape == "Yes" || Escape == "YES" || Escape == "yes" || Escape == "YEAH BRO")
                {
                    cout << "COWARD !-! " << endl;
                    cout << "";
                }
            }
        }

        // Determine the outcome of the battle
        if (Health <= 0)
        {
            cout << "You are dead!!" << endl;
        }

        else if (e.GetHealth() <= 0)
        {
            cout << "Enemy is dead!!" << endl;
        }
    }
};

class Warrior : public Player
{

private:
    int furryMeter;

public:
    Warrior() : furryMeter{0} {}

    void furymeter(int increase)
    {
        furryMeter += increase;
        cout << Name << " increases their furry meter " << endl;
    }

    int unleashFurry()
    {
        int temp = 0;
        temp = furryMeter;
        cout << Name << " unleashes their furry, increasing their attack power by " << furryMeter << "!" << endl;
        furryMeter = 0;
        return temp / 10;
    }

    virtual void battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice;
        string Escape;

        // Display available attack options for the player
        cout << "Choose your attack:" << endl;
        cout << "1. Basic Attack" << endl;
        cout << "2. Special Attack" << endl; // speacil attack bizim heroya bağlı olabilir böylece
        cout << "3. Defend" << endl;
        cin >> choice;

        while (e.GetHealth() > 0 && Health > 0)
        {

            if (choice == 1)
            { // Basic attack

                damage = 1 + (rand() % Attack);
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl;
            }
            else if (choice == 2)
            { // unleash fury

                damage = 1 + (rand() % (Attack));
                damage *= unleashFurry();
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl;
            }

            else if (choice == 3)
            {

                cout << "Player defended and your defense is increased" << endl; // item gücü kadar defense artabilir şimdilik böyle kalsın elleme???
            }

            // Enemy turn
            if (e.GetHealth() > 0)
            {
                damage = 1 + (rand() % e.GetAttack());
                furymeter(damage);
                if (choice == 3)
                    Defense = 5 + (rand() % e.GetDefense());
                else
                    Defense = 1 + (rand() % e.GetDefense());

                Health = Health - (Defense - damage);
                cout << "Enemy dealt: " << damage << " damage. Player blocked " << Defense << " damage. Player's current Health is: " << Health << endl;
            }

            if (Health < 30 && e.GetHealth() > 30)
            {
                cout << "Your Healt is: " << Health << endl;
                cout << "Enemy's health  is: " << e.GetHealth() << endl;
                cout << "Would you like to RUN AWAY!??" << endl;
                cout << "Yes or NO (DO NO TRY TO RUN!):" << endl;
                cin >> Escape;
                if (Escape == "Yes" || Escape == "YES" || Escape == "yes" || Escape == "YEAH BRO")
                {
                    cout << "COWARD !-! " << endl;
                    cout << "";
                }
            }
        }

        // Determine the outcome of the battle
        if (Health <= 0)
        {
            cout << "You are dead!!" << endl;
        }

        else if (e.GetHealth() <= 0)
        {
            cout << "Enemy is dead!!" << endl;
        }
    }
};

class Mage : public Player
{

private:
    int mana;

public:
    Mage() : mana{100} {}

    bool castSpell()
    {
        if (mana >= 20)
        {
            mana -= 20;
            cout << Name << " casts a spell, using " << spellManaCost << " mana." << endl;
            return true;
        }
        else
        {
            cout << Name << " does not have enough mana to cast the spell." << endl;
            return false;
        }
    }

    void replenishMana(int amount)
    {
        mana += amount;
        cout << Name << " replenishes " << amount << " mana." << endl;
    }

    virtual void battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice;
        string Escape;

        // Display available attack options for the player
        cout << "Choose your attack:" << endl;
        cout << "1. Basic Attack" << endl;
        cout << "2. Special Attack" << endl; // speacil attack bizim heroya bağlı olabilir böylece
        cout << "3. Defend" << endl;
        cin >> choice;

        while (e.GetHealth() > 0 && Health > 0)
        {

            if (choice == 1)
            { // Basic attack

                damage = 1 + (rand() % Attack);
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl;
            }
            else if (choice == 2)
            { // casspell

                if (castSpell())
                    damage = MagicScroll.getAttackPower();
                else
                    damage = 0;

                e.SetHealth(e.GetHealth() - damage);

                cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl;
            }

            else if (choice == 3)
            {

                replenishMana(20);
                cout << "Player defended and your mana is increased" << endl;
            }

            // Enemy turn
            if (e.GetHealth() > 0)
            {
                Defense = 5 + (rand() % e.GetDefense());
                Health = Health - (Defense - damage);
                cout << "Enemy dealt: " << damage << " damage. Player blocked " << Defense << " damage. Player's current Health is: " << Health << endl;
            }

            if (Health < 30 && e.GetHealth() > 30)
            {
                cout << "Your Healt is: " << Health << endl
                     << "Enemy's health  is: " << e.GetHealth() << endl;
                cout << "Would you like to RUN AWAY!??" << endl;
                cout << "Yes or NO (DO NO TRY TO RUN!):" << endl;
                cin >> Escape;
                if (Escape == "Yes" || Escape == "YES" || Escape == "yes" || Escape == "YEAH BRO")
                {
                    cout << "COWARD !-! " << endl;
                    cout << "";
                }
            }
        }

        // Determine the outcome of the battle
        if (Health <= 0)
        {
            cout << "You are dead!!" << endl;
        }

        else if (e.GetHealth() <= 0)
        {
            cout << "Enemy is dead!!" << endl;
        }
    }
};

class Rogue : public Player
{

private:
    int Crit_Strike_Chance;

public:
    Rogue() : Crit_Strike_Chance{5} {}

    void improveCritChance(int amount)
    {
        Crit_Strike_Chance += amount;
        cout << name << " improves their critical strike chance  " << amount / 10 << endl;
    }

    while (e.GetHealth() > 0 && Health > 0)
    {

        if (choice == 1)
        { // Basic attack

            damage = 1 + (rand() % Attack);
            e.SetHealth(e.GetHealth() - damage);
            cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl;

            improveCritChance(damage / 10);
        }
        else if (choice == 2)
        {

            damage = Crit_Strike_Chance + (rand() % Attack);
            e.SetHealth(e.GetHealth() - damage);

            cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl;
        }

        else if (choice == 3)
        {

            e.SetHealth(e.GetHealth() - 1);
            cout << "Player defended and Player dealt 1 damage" << endl;
        }

        // Enemy turn
        if (e.GetHealth() > 0)
        {
            Defense = 5 + (rand() % e.GetDefense());
            Health = Health - (Defense - damage);
            cout << "Enemy dealt: " << damage << " damage. Player blocked " << Defense << " damage. Player's current Health is: " << Health << endl;
        }

        if (Health < 30 && e.GetHealth() > 30)
        {
            cout << "Your Healt is: " << Health << endl
                 << "Enemy's health  is: " << e.GetHealth() << endl;
            cout << "Would you like to RUN AWAY!??" << endl;
            cout << "Yes or NO (DO NO TRY TO RUN!):" << endl;
            cin >> Escape;
            if (Escape == "Yes" || Escape == "YES" || Escape == "yes" || Escape == "YEAH BRO")
            {
                cout << "COWARD !-! " << endl;
                cout << "";
            }
        }
    }

    // Determine the outcome of the battle
    if (Health <= 0)
    {
        cout << "You are dead!!" << endl;
    }

    else if (e.GetHealth() <= 0)
    {
        cout << "Enemy is dead!!" << endl;
    }
};

#endif