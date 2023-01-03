
#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Entity.h"
#include "Enemy.h"
#include "Item.h"
#include "ASCII_arts.h"
#include <cmath>
#include <vector>
using namespace std;

class Player : public Entity
{
    protected:
    vector <Item> Inventory;


public:
    // Default Constructor//
    Player() : Entity(){};

    // Overloaded Constructors//
    Player(vector <Item> newitems) : Entity(), Inventory {newitems} {}; 

    // Copy constructor//

    // Destructor//
    ~Player() {}

    //Method for adding item//
    bool AddWeapon(Weapon &w){
        //Print status//

        //Player Stat increase//
        Attack +=w.getAttackPower();
        Defense +=w.getdefensePower();

        //Adding Weapon to İnventory//
        Inventory.push_back(w);

    }
    void DrinkPotion(Potion &p){
        //Player Health İncrease//
        if(Health <100)
        {
            if(Health +=p.gethealthBonus() >100)
            {
                Health=100;
                cout<<"Bon appétit!!"<<endl;
                cout<<"Your Health is full now!!"<<endl;
            }
            else{
                Health +=p.gethealthBonus();
                cout<<"Enjoy,your health is increased by-"<<p.gethealthBonus()<<"!!!"<<endl;
                cout<<"Your health is now "<<Health<<"!!!"<<endl;
            }
        }
        else{
            cout<<"You drank the potion,but it has no effect!!!"<<endl;
            cout<<"Your health is already full!!!"<<endl;
        }
    }

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

    // method to use MeleeWepon for attack and defense
    void UseItem(Weapon &wepon)
    {
        this->Attack += wepon.getAttackPower();
        this->Defense += wepon.getdefensePower();
    }

    // method to use Potion for health
    void UsePotion(Potion &potion)
    {
        this->Health += potion.gethealthBonus();
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

        else if (e.GetHealth() <= 0)
        {
            cout << "Enemy is dead!!" << endl;
            return 2;
        }
    }
};

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

    virtual int battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice;
        string Escape;

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

        else if (e.GetHealth() <= 0)
        {
            cout << "Enemy is dead!!" << endl;
            return 2;
        }
    }
};


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

        else if (e.GetHealth() <= 0)
        {
            cout << "Enemy is dead!!" << endl;
            return 2;
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
        Crit_Strike_Chance += amount / 10;
        cout << Name << " improves their critical strike chance  " << amount / 10 << endl;
    }
    virtual int battle(Enemy &e)
    {
        srand(time(NULL));
        int damage, flag = 0, choice, rnd;
        string Escape;

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

        else if (e.GetHealth() <= 0)
        {
            cout << "Enemy is dead!!" << endl;
            return 2;
        }
    }
};
#endif