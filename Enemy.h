#ifndef Enemy_H
#define Enemy_H
#include "Entity.h"
using namespace std;
#include <string>


class Enemy: public Entity{

    protected:
        int Reward_gold;
        
    
    public:
        //constructors//
        

        //Getters//
        int GetReward_gold(void){return Reward_gold;}
        
        //Setters//
        void SetReward_gold(int x){Reward_gold=x;}
        

};



class FinalBoss:public Enemy{

    public:
        //Default constructor//
        FinalBoss():Enemy(){
            Attack=80;
            Defense=80;
        }
        //Overloaded constructor//

        //Attack Method//

        //special Attack Method(might be one hit kill)//

        //Defend Method//


};

#endif