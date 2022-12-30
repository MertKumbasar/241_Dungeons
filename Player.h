
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
    virtual Player battle(Enemy &e)
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
    Warrior()
    {
        furryMeter = 0;
    }

    void BasicAttack(Item &item)
    {
    }

    void defend()
    {
        furryMeter += 10;
        cout << name << " increases their furry meter by 10!" << endl;
    }

    void unleashFurry()
    {
        attackPower += furryMeter;
        cout << name << " unleashes their furry, increasing their attack power by " << furryMeter << "!" << endl;
        furryMeter = 0;
    }
};

class Mage : public Player
{

private:
    int mana;

public:
    Mage() : mana{100}
    {
    }
    void castSpell(Item &item)
    {
        if (mana >= item.spellManaCost)
        {
            mana -= spellManaCost;
            cout << Name << " casts a spell, using " << spellManaCost << " mana." << endl;
        }
        else
        {
            cout << Name << " does not have enough mana to cast the spell." << endl;
        }
    }

    void replenishMana(int amount)
    {
        mana += amount;
        cout << Name << " replenishes " << amount << " mana." << endl;
    }
};

class Rogue : public Player
{

private:
    int Crit_Strike_Chance; // Chance for the rogue to perform a critical strike
public:
    // Default constructor
    Rogue()
    {
        Crit_Strike_Chance = 10;
    }

    // Overloaded constructor
    Rogue(string name, int health, int attackPower, int defense, int critChance) : Player(name, health, attackPower, defense), Crit_Strike_Chance{critChance} {}

    // Method to attack an enemy with a chance to perform a critical strike
    void attack(Enemy &enemy)
    {
        int chance = rand() % 100 + 1; // Generate a random number between 1 and 100
        if (chance <= Crit_Strike_Chance)
        {
            // Perform a critical strike
            cout << enemy.GetName() << " lands a critical strike on " << enemy.GetName() << "!" << endl;
            enemy.takeDamage(2 * attackPower);
        }
        else
        {
            // Perform a normal attack
            cout << enemy.GetName() << " attacks " << enemy.GetName() << "." << endl;
            enemy.takeDamage(attackPower);
        }
    }

    // Method to increase the rogue's critical strike chance
    void improveCritChance(int amount)
    {
        Crit_Strike_Chance += amount;
        cout << name << " improves their critical strike chance by " << amount << "%." << endl;
    }
};

#endif