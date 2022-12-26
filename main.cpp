#include <iostream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Map.cpp"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"


using namespace std;

// function to move cursor to top
void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
// function to move cursor to top
int main(){

      

      Player p1;
      cout<<p1.GetHealth()<<endl;

      int game_is_on = 1;
      Map game_map;
      while(game_is_on){
            gotoxy(0,0);
            game_map.printMap();
            Sleep(100);
            if (_kbhit()){
            switch (getch()){  

            case 'w':
                  game_map.movePlayer_up();
                  
                  break;

            case 's':
                  game_map.movePlayer_down();
                  break;

            case 'a':
                  game_map.movePlayer_left();
                  break;

            case 'd':
                  game_map.movePlayer_right();
                  break;
                  
            default:
                  break;
                  
            }
      }
     
   }
   return 0;
}

