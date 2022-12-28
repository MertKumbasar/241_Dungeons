#include <iostream>
#include <string>
using namespace std;

class Entity{

    protected:
    string Name;
    int Score;
    int Defense;
    int Health;
    int Attack;
    int Total_Gold;
    public:
    //Default Constructor//
    Entity():Name{"Unknown"},Score{0},Health{100},Attack{20},Defense{0},Total_Gold{0}{}
    //Getter//
    int GetDefense(void){return Defense;};
    int GetAttack(void){return Attack;};
    string GetName(void){return Name;}
    int GetHealth(void){return Health;}
    int GetScore(void){return Score;}
    int GetTotalGold(void){return Total_Gold;}
    //Setter//
    void SetDefense(int input){Defense=input;};
    void SetAttack(int input){Attack=input;};
    void Setname(string input){Name = input;}
    void SetHealth(int input){Health=input;}
    void SetScore(int input){Score=input;}
    void SetTotalGold(int input){Total_Gold=input;}
    



};