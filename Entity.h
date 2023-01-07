#ifndef Entity_H
#define Entity_H

#include <iostream>
#include <string>
using namespace std;

class Entity
{

protected:
    string Name;
    int Defense;
    int Health;
    int Attack;

public:
    // Default Constructor//
    Entity() : Name{"Unknown"}, Health{100}, Attack{20}, Defense{20} {}

    // Overloaded Constructor
    Entity(string str, int healt, int attck, int def) : Name{str}, Health{healt}, Attack{attck}, Defense{def} {}

    // Destructor
    ~Entity() {}

    // Getter//
    int GetDefense(void) { return Defense; };
    int GetAttack(void) { return Attack; };
    string GetName(void) { return Name; }
    int GetHealth(void) { return Health; }

    // Setter//
    void SetDefense(int input) { Defense = input; };
    void SetAttack(int input) { Attack = input; };
    void Setname(string input) { Name = input; }
    void SetHealth(int input) { Health = input; }
};

#endif