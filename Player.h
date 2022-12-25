
#ifndef Player_H
#define Player_H

#include "Item.h"
#include <iostream>
#include <string>
using namespace std;

class Player
{

protected:
    // position on the map//
    string Name;
    int Score;
    int Defense;
    int Health;
    int Attack;
    int Total_Gold;
    Item *items;

public:
    // Default Constructor//

    // Overloaded Constructors//

    // Copy constructor//

    // Move Constructor??//

    // Destructor//

    // Setters//
    void Setname(string input) { Name = input; }
    void SetHealth(int input) { Health = input; }
    void SetScore(int input) { Score = input; }
    void SetTotalGold(int input) { Total_Gold = input; }
    // Getters//
    string GetName(void) { return Name; }
    int GetHealth(void) { return Health; }
    int GetScore(void) { return Score; }
    int GetTotalGold(void) { return Total_Gold; }
    void virtual PrintStatus(void); // function for printing player status//
    // Move method//

    // Attack method//

    // Defend Method//
};

class Warior : public Player
{

private:
    // A Furry meter which goes up when defending resulting more attack power//
};

class Mage : public Player
{

private:
    int mana;
    // Magic scrolls(???)//
};

class Rouge : public Player
{

private:
    int Crit_Strike_Chance; //???//
};

#endif