
#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include <Enemy.h>
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

    
    //Overloaded Constructors//
    
    //Copy constructor//

    //Move Constructor??//

    //Destructor//
    
    //Setters//
    void Setname(string input){Name = input;}
    void SetHealth(int input){Health=input;}
    void SetScore(int input){Score=input;}
    void SetTotalGold(int input){Total_Gold=input;}
    //Getters//
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
    virtual Player Attack(Enemy &E){
        
    }

    //Defend Method virtual//
    virtual Player Defend (Enemy &E){

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