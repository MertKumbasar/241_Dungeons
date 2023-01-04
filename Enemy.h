#ifndef Enemy_H
#define Enemy_H
#include "Entity.h"
using namespace std;
#include <string>

class Enemy : public Entity
{

public:
    // constructors//
    Enemy() : Entity() {}

    // overloaded constructors
    Enemy(string name) : Entity(name) {}

    // destructor
    ~Enemy() {}
};

#endif