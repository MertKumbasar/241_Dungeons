#ifndef Player_H
#define Player_H


class Player{
    

    protected:
        string Name;
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
    void Setname(string input){Name = input;}
    string GetName(void){return Name;}
    void SetHealth(int input){Health=input;}
    int GetHealth(void){return Health;}
    



};

#endif