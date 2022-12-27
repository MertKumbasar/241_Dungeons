#include <iostream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Map.cpp"





using namespace std;

// function to move cursor to top
void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
// function to move cursor to top
int main(){
      char event = '.';
      int game_is_on = 1;
      Map game_map;
      while(game_is_on){
            gotoxy(0,0);
            game_map.printMap();
            Sleep(100);
            if (_kbhit()){
                  switch (getch()){  
                  case 'w':
                        event = game_map.movePlayer_up();
                        break;
                  case 's':
                        event = game_map.movePlayer_down();
                        break;
                  case 'a':
                        event = game_map.movePlayer_left();
                        break;
                  case 'd':
                        event = game_map.movePlayer_right();
                        break;
                  default:
                        
                        break;
                        
                  }
            }
            if(event == 'M'){
                  system("cls");
                  cout << "monster event !!!";
                  Sleep(1000);
                  
            }
            else if(event == 'I'){
                  system("cls");
                  cout << "item event!!!";
            }
            // reseting the event variable
            event = '.';
   }
   return 0;
}

