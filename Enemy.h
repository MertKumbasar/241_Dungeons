#ifndef Enemy_H
#define Enemy_H
#include "Entity.h"
using namespace std;
#include <string>

class Enemy : public Entity
{

protected:
    int Reward_gold;

public:
    // constructors//
    Enemy() : Entity(), Reward_gold{0} {}

    // overloaded constructor
    Enemy(int gold) : Entity(), Reward_gold{gold} {}

    // destructor
    ~Enemy() {}

    // Getters//
    int GetReward_gold(void) { return Reward_gold; }

    // Setters//
    void SetReward_gold(int x) { Reward_gold = x; }
};

#endif