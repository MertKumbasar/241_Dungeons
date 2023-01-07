#ifndef Enemy_H
#define Enemy_H
#include "Entity.h"
using namespace std;
#include <string>
#include <iostream>
#include <string>
#include <map>
#include <random>

class Enemy : public Entity
{

public:
    // constructors//
    Enemy() : Entity() {}

    // overloaded constructors
    Enemy(string name, int h, int a, int d) : Entity(name, h, a, d) {}

    // destructor
    ~Enemy() {}
};

class RPC{
    private:
      string *c {nullptr},Computer_Name;
      int index;
      int winner1,winner2;

    public:
      RPC(): index{3}, Computer_Name{"AI"}, winner1 {0}, winner2{0} {

          Mrpc= new string [index];
          Mrpc[0]="rock";
          Mrpc[1]="paper";
          Mrpc[2]="scissors";        
      }
    ~RPC(){
        delete [] Mrpc;
    }
      
      int GetWinner (string x, string y){

        if(x=="rock")
          {
            if (y=="rock")
              return 0;
            else if (y=="paper")
              winner1++;
            else if (y=="scissors")
              winner2++;

          }
        else if (x=="paper"){

            if (y=="rock")
              winner1++;
            else if (y=="paper")
              return 0;
            else if (y=="scissors")
              winner2++;

        }
        else if (x=="scissors"){

            if (y=="rock")
              winner2++;
            else if (y=="paper")
              winner1++;
            else if (y=="scissors")
              return 0;

        }

          
      }
      void CheckResult(){
        int rnd;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 3);

        rnd=dis(gen);

        string round,computer;      

        do{

          computer=Mrpc[rnd]; 

          cout<<"Enter Your Choice "<<endl;
          cin>>round;
          cout<<Computer_Name<<" Generated "<<computer<<endl;

          GetWinner (round,computer);

        }while (winner1!=3||winner2!=3);
        
        if (winner1==3){
          cout<<"PLAYER WINS"<<endl;
        }
        else if(winner2==3)
          cout<<"Computer wins"<<endl;
        
      }
      

};



#endif
