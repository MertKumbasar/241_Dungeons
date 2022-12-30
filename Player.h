
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
    ~Player(){}

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
        int damage, flag = 0, choice;
        string Escape;

        // Display available attack options for the player
        cout << "Choose your attack:" << endl;
        cout << "1. Basic Attack" << endl;
        cout << "2. Special Attack" << endl;                //speacil attack bizim heroya bağlı olabilir böylece 
        cout << "3. Defend" << endl;
        cin >> choice;

        while (e.GetHealth() > 0 && Health > 0) {


            if (choice == 1) {   // Basic attack
            
            damage = 1 + (rand() % Attack);
            e.SetHealth(e.GetHealth() - damage);
            cout << "Player dealt " << damage << " damage. Enemy current Health is " << e.GetHealth() << endl;


            } 
            else if (choice == 2) {      // Special attack                
            
            damage = 2 + (rand() % (Attack + 5));                         //item a bağlı bir artış burada olabilir ya da speller, player type a göre 
            e.SetHealth(e.GetHealth() - damage);
            cout << "Player dealt " << damage << " damage with a special attack. Enemy current Health is " << e.GetHealth() << endl;
            } 
            
            else if (choice == 3) {         // Defend
            
            Defense += 2;                                                              //burdan pek enim değilim defend için daha mantıklı bir şey olabilir defense random değişebilir gibi 
            cout << "Player defended and increased Defense by 2." << endl;
            }

            // Enemy turn
            if (e.GetHealth() > 0) {
            damage = 1 + (rand() % e.GetAttack());
            Defense = 1 + (rand() % e.GetDefense());
            Health = Health - (Defense - damage);
            cout << "Enemy dealt: " << damage << " damage. Player blocked " << Defense << " damage. Player's current Health is: " << Health << endl;
            }

            if(Health<30&&e.GetHealth()>30){
                cout<<"Your Healt is: "<<Health<<endl<<"Enemy's health  is: "<<e.GetHealth()<<endl;
                cout<<"Would you like to RUN AWAY!??"<<endl;
                cout<<"Yes or NO (DO NO TRY TO RUN!):"<<endl; 
                cin>>Escape;
                if (Escape=="Yes"||Escape=="YES"||Escape=="yes"||Escape=="YEAH BRO"){
                    cout<<"COWARD !! "<<endl;
                }
            }


        }

        // Determine the outcome of the battle
        if (Health <= 0) {
            cout << "You are dead!!" << endl;
        } 

        else if (e.GetHealth() <= 0) {
            cout << "Enemy is dead!!" << endl;
        }
    }
    
};


class Warior:public Player{
    public:
    //default constructor
    

    //overloaded constructor


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