#ifndef ROGUE_H
#define ROGUE_H
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

class Rogue : public Player
{

private:
    int Crit_Strike_Chance;

public:
    Rogue() : Crit_Strike_Chance{5} {}

    void improveCritChance(int amount)
    {
        Crit_Strike_Chance += amount / 10;
        cout << Name << " improves their critical strike damage  " << amount / 10 << endl;
    }

    virtual void PrintStatus(void)
    {   
        system("cls");
        cout << "Your name is: " << Name << endl;
        cout << "Your defense power is : " << Defense << endl;
        cout << "Your health is: " << Health << endl;
        cout << "Your attack power is: " << Attack << endl;
        cout << "Your Critical damage is: " << Crit_Strike_Chance << endl;
        
        cout << "Attack and Defense bonuses gained from items: " << endl;
        for (size_t i{0}; i < Inventory.size(); i++)
        {
            cout << Inventory[i];
        }
        cout << endl;
    }

    virtual int battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice, rnd;
        string Escape;
        cout << Name << ", be careful. There occurs a dangerous monster called " << e.GetName() << endl;
        cout << " Get ready for the battle!!" << endl;
        cout << endl;
        while (e.GetHealth() > 0 && Health > 0)
        {
            // Display available attack options for the player
            cout << "Choose your attack:" << endl;
            cout << "1. Basic Attack (Chance of critic attack: %10)" << endl;
            cout << "2. Defend" << endl;
            cin >> choice;
            system("cls");
            if (choice == 1)
            { // Basic attack
                rnd = 1 + (rand() % 11);

                if (rnd == 7)
                {
                    damage = Crit_Strike_Chance + (rand() % Attack);
                    cout << "CRITICAL DAMAGE!!" << endl;
                }

                else
                {
                    damage = 1 + (rand() % Attack);
                }
                e.SetHealth(e.GetHealth() - damage);
                improveCritChance(damage);
                cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl;
            }

            else if (choice == 2)
            {
                cout << "Player defended and Player dealt no damage" << endl;
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

            if (Health < 30 && e.GetHealth() > 30 && Health > 0)
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
                    return 1;
                }
            }
        }

        // Determine the outcome of the battle
        if (Health <= 0)
        {
            return 0;
        }

        else
        {
            return 2;
        }
    }
};
#endif