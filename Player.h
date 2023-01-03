
#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Entity.h"
#include "Enemy.h"
#include "Item.h"
#include <cmath>
#include <vector>
using namespace std;

class Player : public Entity
{
protected:
    vector<Weapon> Inventory;

public:
    // Default Constructor//
    Player() : Entity(){};

    // Overloaded Constructors//
    Player(vector<Weapon> newWeapon) : Entity(), Inventory{newWeapon} {};

    // Copy constructor//

    // Destructor//
    ~Player() {}

    

    // Method for adding weapon//
    bool AddWeapon(Weapon &w)
    {
        string answer;
        // Print status//
        cout << w;
        do
        {
            cout << "Would you like to pick this weapon? (Yes / No): ";
            cin >> answer;

            if (answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y")
            {
                // Player Stat increase//
                Attack += w.getAttackPower();
                Defense += w.getdefensePower();

                // Adding Weapon to İnventory//
                Inventory.push_back(w);

                cout << endl;
                cout << w.getName() << " added to your inventory!! Use it wisely." << endl;

                return true;
            }
            else if (answer == "No" || answer == "no" || answer == "n" || answer == "N")
            {
                cout << "Well, i hope you made a good decision.." << endl;
                cout << w.getName() << " is not added to your inventory." << endl;

                return false;
            }
            else
            {
                cout << "Please enter Yes or No !.." << endl;
          }
        } while (answer != "yes" || answer != "Yes" || answer != "No" || answer != "no");
    }

    // method for using potion
    void DrinkPotion(Potion &p)
    {  
        // printing health bonus of the potion
        p.printHealthBonus();

        // Player Health İncrease//
        if (Health < 100)
        {
            if (Health += p.gethealthBonus() > 100)
            {
                Health = 100;
                cout << "Bon appétit!!" << endl;
                cout << "Your Health is full now!!" << endl;
            }
            else
            {
                Health += p.gethealthBonus();
                cout << "Enjoy,your health is increased by-" << p.gethealthBonus() << "!!!" << endl;
                cout << "Your health is now " << Health << "!!!" << endl;
            }
        }
        else
        {
            cout << "You drank the potion,but it has no effect!!!" << endl;
            cout << "Your health is already full!!!" << endl;
        }
    }

    // function for printing player status//
    virtual void PrintStatus(Player &p1)
    {
        cout << "Your name is: " << p1.Name << endl;
        cout << "Your score is: " << p1.Score << endl;
        cout << "Your defense power is : " << p1.Defense << endl;
        cout << "Your health is: " << p1.Health << endl;
        cout << "Your attack power is: " << p1.Attack << endl;
        cout << "Your total gold is: " << p1.Total_Gold << endl;

        cout << "Items you have in inventory are: " << endl;
        for (size_t i{0}; i < Inventory.size(); i++)
        {
            cout << Inventory[i];
        }
        cout << endl;
    }

    // Attack method virtual//
    virtual int battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice;
        string Escape;

        while (e.GetHealth() > 0 && Health > 0)
        {
            // Display available attack options for the player
            cout << "Choose your attack:" << endl;
            cout << "1. Basic Attack" << endl;
            cout << "2. Special Attack" << endl;
            cout << "3. Defend" << endl;
            cin >> choice;

            if (choice == 1)
            { // Basic attack

                damage = 1 + (rand() % Attack);
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl;
            }
            else if (choice == 2)
            { // Special attack

                damage = 2 + (rand() % (Attack + 5));
                e.SetHealth(e.GetHealth() - damage);
                cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl;
            }

            else if (choice == 3)
            { // Defend
                Defense += 2;
                cout << "Player defended and increased Defense by 2." << endl;
            }

            // Enemy turn
            if (e.GetHealth() > 0)
            {
                damage = 1 + (rand() % e.GetAttack());
                Defense = 1 + (rand() % e.GetDefense());

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
