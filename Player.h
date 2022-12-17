
#ifndef Player_H
#define Player_H

#include <iostream>
using namespace std;

class Player{
    

    protected:
        string name;
        int Health=0;
        int Mana;
        int Level;
        int Xp;
        int Attack;
        int Defense;
    public:
    //Default Constructor//
    
    //Overloaded Constructors//
    

    //Destructor//
    
    //Methods//
    void Setname(string input){name = input;}
    string GetName(void){return name;}
    void SetHealth(int input){Health=input;}
    int GetHealth(void){return Health;}
    



};

#endif