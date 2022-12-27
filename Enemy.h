#ifndef Enemy_H
#define Enemy_H
#include "Player.h"
using namespace std;
#include <string>
#include "Item.h"

class Enemy: public Player{

    protected:
        int Reward_gold;
        //Enemy has an item that can be dropped when defeated//
        Item DroppedItem;
        
    
    public:
        //Default constructor//
        Enemy():Player(), Reward_gold{0}, DroppedItem(){}

        //Getters//
        int GetReward_gold(void){return Reward_gold;}
        Item& DropItem(void){return DroppedItem;}
        //Set Item Method//
        void SetItem(Item &i){this->DroppedItem=i;}
        //Regular Setters//
        void SetReward_gold(int x){Reward_gold=x;}
        
        //Attack Method//

        //Defend Method//

};

class MiniBoss:public Enemy{

    public:
        //Default constructor//
        MiniBoss(): Enemy(){
            Attack=40;
            Defense=40;
        }

        //Overloaded constructor//

        //Attack Method//

        //Defend Method//
    

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