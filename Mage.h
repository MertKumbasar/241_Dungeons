#ifndef MAGE_H
#define MAGE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Entity.h"
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include <cmath>
#include <vector>
using namespace std;
class Mage : public Player
{

private:
    MagicScroll scroll;
    int mana;

public:
    Mage() : mana{100} {}

    bool castSpell()
    {
        if (mana >= 20)
        {
            mana -= 20;
            cout << Name << " casts a spell, using 20 mana." << endl;
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

    virtual int battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice;
        string Escape;
        cout << Name << "occurs " << e.GetName() <<" the monster GUARD ON !!" << endl ;
        while (e.GetHealth() > 0 && Health > 0)
        {
            // Display available attack options for the player
            cout << "Choose your attack:" << endl;
            cout << "1. Basic Attack" << endl;
            cout << "2. Special Attack" << endl;
            cout << "3. Defend" << endl;
            cin >> choice;
            system("cls");
            if (choice == 1)
            { // Basic attack

                damage = 1 + (rand() % Attack);
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl
                     << endl;
                ;
            }
            else if (choice == 2)
            { // casspell

                if (castSpell())
                    damage = scroll.getAttackPower();
                else
                    damage = 0;

                e.SetHealth(e.GetHealth() - damage);

                cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl
                     << endl;
                ;
            }

            else if (choice == 3)
            {

                replenishMana(20);

                cout << "Player defended and your mana is increased" << endl
                     << endl;
                ;
            }

            // Enemy turn
            if (e.GetHealth() > 0)
            {
                damage = 1 + (rand() % e.GetAttack());
                Defense = 5 + (rand() % e.GetDefense());

                if (Defense < damage)
                {

                    Health = Health - (damage - Defense);
                    cout << "Enemy dealt: " << damage << " damage. Player blocked " << Defense << " damage. Player's current Health is: " << Health << endl
                         << endl;
                }
                else
                {
                    cout << "Blocked!!" << endl;
                    cout << "Enemy dealt: " << damage << " damage. Player blocked " << damage << " damage. Player's current Health is: " << Health << endl
                         << endl;
                }
            }

            if (Health < 30 && e.GetHealth() > 30)
            {
                cout << "Your Health is: " << Health << endl
                     << "Enemy's health  is: " << e.GetHealth() << endl;
                cout << "Would you like to RUN AWAY!??" << endl;
                cout << "Yes or NO (DO NO TRY TO RUN!):" << endl;
                cin >> Escape;
                if (Escape == "Yes" || Escape == "YES" || Escape == "yes" || Escape == "YEAH BRO")
                {
                    cout << "COWARD !-! " << endl;
                    cout << "";
                    return 1;
                }
            }
        }

        // Determine the outcome of the battle
        if (Health <= 0)
        {
            cout << "You are dead!!" << endl;
            return 0;
        }

        else
        {
            cout << "Enemy is dead!!" << endl;
            return 2;
        }
    }
};

#endif