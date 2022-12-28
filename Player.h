
#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "Item.h"
using namespace std;

class Player:public Entity{

    protected:  


    public:
    //Default Constructor//
    
    //Overloaded Constructors//
    
    //Copy constructor//


    //Destructor// 
    
    //function for printing player status//
    void PrintStatus(Player &p1){
        cout << "Your name is: " << p1.Name << endl;
        cout << "Your score is: " << p1.Score << endl;
        cout << "Your defense power is : " << p1.Defense << endl;
        cout << "Your health is: " << p1.Health << endl;
        cout << "Your attack power is: " <<p1.Attack << endl;
        cout << "Your total gold is: " << p1.Total_Gold << endl;
        cout << "Items you have are: " << endl;
        /*for (int i{0}; i < nrOfItems; i++)
        {
            cout << itemsList[i];
        }
        */
        }
    //Move method//

    //Attack method virtual//
    virtual Player battle(Enemy &E){
       
        
    }

    
    

   

};


class Warior:public Player{

    private:
        //A Furry meter which goes up when defending resulting more attack power//
    


};


class Mage:public Player{

    private:
        int mana;
        //Magic scrolls(???)//

};


class Rouge:public Player{

    private:
        int Crit_Strike_Chance;//???//
    


};

#endif