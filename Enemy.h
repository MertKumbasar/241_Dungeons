#ifndef Enemy_H
#define Enemy_H
#include "Entity.h"
using namespace std;
#include <string>
#include <iostream>
#include <string>
#include <map>
#include <random>

class Enemy : public Entity
{

public:
    // constructors//
    Enemy() : Entity() {}

    // overloaded constructors
    Enemy(string name, int h, int a, int d) : Entity(name, h, a, d) {}

    // destructor
    ~Enemy() {}
};

#endif