#ifndef WARRIOR_H
#define WARRIOR_H
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

class Warrior : public Player
{

private:
    int furryMeter;

public:
    Warrior() : furryMeter{0} {}
    friend void printWarrior(void);
    void furymeter(int increase)
    {
        furryMeter += increase;
        cout << Name << " increases their fury meter " << endl;
    }

    int unleashFurry()
    {
        int temp = 0;
        temp = furryMeter;
        cout << Name << " unleashes their fury, increasing their attack power by " << furryMeter << "!" << endl;
        furryMeter = 0;
        return temp / 10;
    }

    virtual void PrintStatus(Player &p1)
    {
        cout << "Your name is: " << p1.GetName() << endl;
        cout << "Your score is: " << p1.GetScore() << endl;
        cout << "Your defense power is : " << p1.GetDefense() << endl;
        cout << "Your health is: " << p1.GetHealth() << endl;
        cout << "Your attack power is: " << p1.GetAttack() << endl;
        cout << "Your total gold is: " << p1.GetTotalGold() << endl;

        cout << "Items you have in inventory are: " << endl;
        for (size_t i{0}; i < Inventory.size(); i++)
        {
            cout << Inventory[i];
        }
        cout << endl;
    }

    virtual int battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice;
        string Escape;
        cout << Name << ", be careful. There occurs a dangerous monster called " << e.GetName() << endl;
        cout << " Get ready for the battle!!" << endl;
        cout << endl;

        // Display available attack options for the player
        while (e.GetHealth() > 0 && Health > 0)
        {
            cout << "Choose your attack:" << endl;
            cout << "1. Basic Attack" << endl;
            cout << "2. Special Attack" << endl; // speacil attack bizim heroya bağlı olabilir böylece
            cout << "3. Defend" << endl;
            cin >> choice;

            system("cls");
            if (choice == 1)
            { // Basic attack

                damage = 1 + (rand() % Attack);
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl
                     << endl;
            }
            else if (choice == 2)
            { // unleash fury

                damage = 1 + (rand() % (Attack));
                damage *= unleashFurry();
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl
                     << endl;
            }

            else if (choice == 3)
            {

                cout << "Player defended and your defense is increased" << endl
                     << endl; // item gücü kadar defense artabilir şimdilik böyle kalsın elleme???
            }

            // Enemy turn
            if (e.GetHealth() > 0)
            {
                damage = 1 + (rand() % e.GetAttack());
                furymeter(damage);
                if (choice == 3)
                {

                    Defense = 5 + (rand() % e.GetDefense());
                }
                else
                {

                    Defense = 1 + (rand() % (e.GetDefense()));
                }
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
                cout << "Your Health is: " << Health << endl;
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
