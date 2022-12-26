#ifndef Enemy_H
#define Enemy_H
#include "Player.h"
using namespace std;
#include <string>
#include <Item.h>

class Enemy: public Player{

    protected:
        int Reward_gold;
        //Enemy has an item that can be dropped when defeated//
        Item DroppedItem;
        
    
    public:
        //Default constructor//
        Enemy():Player(), Reward_gold{0}, DroppedItem(){}

        //Getters//
        string GetName(void){return Name;}
        int GetReward_gold(void){return Reward_gold;}
        int GetAttack_Power(void){return Attack_Power;}
        int GetHealth(void){return Health;}
        Item& DropItem(void){return DroppedItem;}
        //Set Item Method//
        void SetItem(Item &i){this->DroppedItem=i;}
        //Regular Setters//
        void SetName(string x){Name=x;}
        void SetReward_gold(int x){Reward_gold=x;}
        void SetAttack_Power(int x){Attack_Power=x;}
        void SetHealth(int x){Health=x;}
        
        //Attack Method//

        //Defend Method//

};

class MiniBoss:public Enemy{

    public:
        //Default constructor//
        MiniBoss(): Enemy(){
            Attack=30;
        }

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