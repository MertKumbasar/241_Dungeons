
#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "Enemy.h"
#include "Item.h"
using namespace std;

class Player:public Entity{

    public:
    //Default Constructor//
    Player(): Entity(){};
    
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
    virtual Player battle(Enemy &e){
       srand(time(NULL));
        int damage,flag=0,choice;
        while(e.GetHealth()>0){
            if(Health<=0){
                flag=1;
                break;
            }
            else{
                damage= 1+(rand()%Attack);
                e.SetHealth(e.GetHealth()-damage);
                cout<<"Player dealt "<<damage<<". Enemy current Health is "<<e.GetHealth()<<endl;
                
                damage= 1+(rand()%e.GetAttack());
                Health=Health-(Defense-damage);
                cout<<"Enemy dealt "<<damage<<". Player current Health is "<<Health<<endl;

                cout<<"ENTER 1 TO CONTINUE FIGHTING,2 TO RUN!!:";
                cin>>choice;
                if(choice==1){continue;}
                else if(choice==2){flag=2;break;}
            }
        }
        if(flag==1){
            cout<<"You are dead!!"<<endl;
        }
    
        else if(flag==0){
             cout<<"Enemy is dead!!"<<endl;
        }
        else if(flag==2) {
            cout<<"You ran away. COWARD!!!"<<endl;
        }
        
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