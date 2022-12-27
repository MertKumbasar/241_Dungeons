
#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include "Enemy.h"
#include "Item.h"
using namespace std;

class Player{

    protected:  

        //position on the map//
        string Name;
        int Score;
        int Defense;
        int Health;
        int Attack;
        int Total_Gold;

    public:
    //Default Constructor//
        Player(): Name{"Unknown"}, Score{0}, Defense{10}, Health{100}, Attack{10}, Total_Gold{0}{}
    
    //Overloaded Constructors//
    
    //Copy constructor//

    //Move Constructor??//

    //Destructor//
    
    //Setters//
    void SetDefense(int input){Defense=input;};
    void SetAttack(int input){Attack=input;};
    void Setname(string input){Name = input;}
    void SetHealth(int input){Health=input;}
    void SetScore(int input){Score=input;}
    void SetTotalGold(int input){Total_Gold=input;}
    //Getters//
    int GetDefense(void){return Defense;};
    int GetAttack(void){return Attack;};
    string GetName(void){return Name;}
    int GetHealth(void){return Health;}
    int GetScore(void){return Score;}
    int GetTotalGold(void){return Total_Gold;}
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
        srand((unsigned) time(NULL));
        
        cout<<E.GetName();
        cout<<Name;
        int RndAttack;
        //cout<<"Storyline"
        while(E.GetHealth()>0){  //player yaşıyorsa, Enemy ölene kadar 
            cout<<"Press 1 to attack";

            RndAttack= 0 + (rand() % Attack);

            E.SetHealth(E.GetHealth()-RndAttack);

            RndAttack= 0 + (rand() % E.GetAttack());

            SetHealth(GetHealth()-RndAttack);


        }
        
    }

    //Defend Method virtual//
    //virtual Player Defend (Enemy &E){

   // }
    

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