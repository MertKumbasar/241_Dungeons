#ifndef Enemy_H
#define Enemy_H
#include "Player.h"
using namespace std;
#include <string>

class Enemy{

    protected:
        string Enemy_Type;//default enemy,mini bos,Final Boss//
        int Reward_gold;
        int Attack_Power;
        int Health;
        //Mana??//
        
        //Enemy has an item that can be dropped when defeated//

        //Position of enemy in the map??//

    public:
        //Default constructor//

        //Overloaded constructor//

        //Attack Method//

        //Defend Method//

};

class MiniBoss:public Enemy{

    public:
        //Default constructor//

        //Overloaded constructor//

        //Attack Method//

        //Defend Method//
    

};

class FinalBoss:public Enemy{

        //Default constructor//

        //Overloaded constructor//

        //Attack Method//

        //special Attack Method(might be one hit kill)//

        //Defend Method//


};

#endif