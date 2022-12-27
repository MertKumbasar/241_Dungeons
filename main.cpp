#include <iostream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Map.cpp"
using namespace std;
// gençler test yapmak için buraları sildim bi daha eklerirz sonra


//template <typename T > 
// int *menuCH1 (const T *index){ //secimleri burada tutuyoruz

// }
void printTitle(void){
      cout << "             _ " << endl;
      cout << "            | |" << endl;
      cout << "          __| |_   _ _ __   __ _  ___  ___  _ __  ___ " << endl;
      cout << "         / _` | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\/ __|" << endl;
      cout << "        | (_| | |_| | | | | (_| |  __/ (_) | | | \\__ \\" << endl;
      cout << "         \\__,_|\\__,_|_| |_|\\__, |\\___|\\___/|_| |_|___/" << endl;
      cout << "                            __/ |" << endl;
      cout << "                           |___/" << endl;
      cout << "   _________________________________________________________" << endl;
      cout << " /|     -_-                                             _-  |\\" << endl;
      cout << "/ |_-_- _                                         -_- _-   -| \\" << endl;
      cout << "  |                            _-  _--                      |" << endl;
      cout << "  |                            ,                            |" << endl;
      cout << "  |      .-'````````'.        '(`        .-'```````'-.      |" << endl;
      cout << "  |    .` |           `.      `)'      .` |           `.    |" << endl;
      cout << "  |   /   |   ()        \\      U      /   |    ()       \\   |" << endl;
      cout << "  |  |    |    ;         | o   T   o |    |    ;         |  |" << endl;
      cout << "  |  |    |     ;        |  .  |  .  |    |    ;         |  |" << endl;
      cout << "  |  |    |     ;        |   . | .   |    |    ;         |  |" << endl;
      cout << "  |  |    |     ;        |    .|.    |    |    ;         |  |" << endl;
      cout << "  |  |    |____;_________|     |     |    |____;_________|  |" << endl;
      cout << "  |  |   /  __ ;   -     |     !     |   /     `'() _ -  |  |" << endl;
      cout << "  |  |  / __  ()        -|        -  |  /  __--      -   |  |" << endl;
      cout << "  |  | /        __-- _   |   _- _ -  | /        __--_    |  |" << endl;
      cout << "  |__|/__________________|___________|/__________________|__|" << endl;
      cout << " /                                             _ -           \\" << endl;
      cout << "/   -_- _ -             _- _---                       -_-  -_ \\" << endl;
}
// function to move cursor to top
void gotoxy(short x, short y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
// function to move cursor to top

int main(){
      // variables for main
      string name;
      int input;
      char event = '.';
      int game_is_on = 1;
      // variables for main
      printTitle();
      cout << "Press 1 to play "<<endl;
      do{
            cin >> input;
      }while(input != 1);
      system("cls");


      cout << "The voice: Welcome stranger, what is your name ? "<< endl;
      cin >> name;
      cout << endl;
      cout << "Well met " << name << ". Here is the deal " << name << ", you were camping with your girlfriend in the forest but somehow you end up here and your girlfirend is missing" << endl;
      cout << "'ask a question' "<< endl;
      cout << endl;
      do{
            cout << "1. Wait a minute, who are you ? "<< endl;
            cout << "2. Where is my girlfriend ? Tell me NOW !!!! " << endl;
            cout << "3. Explore the dungeon !!"<<endl;
            cin >> input;
            cout << endl;
            if(input == 1){
                  cout << "The voice: It really doesn't matter who i am. I am just here to help you this is a wired place to be in you need a guide"<<endl;
            }
            else if(input == 2){
                  cout << "The voice: Thats a good question my friend but i think the answer is deep down in the dungeon"<<endl;
            }
      }while(input != 3);

      system("cls");
      cout << "The voice: Then here, This is a map for you to see where you are GOOD LUCK!!";
      Sleep(3000);
      system("cls");

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
                  //if( monster lives ){
                  //       game_map.movePlayer_left_if_monster_lives();
                  // }
                  
            }
            else if(event == 'I'){
                  system("cls");
                  cout << "item event!!!";
                  //Returnn to map in 3 sexx
                  Sleep(1000);
            }
            // reseting the event variable
            event = '.';
      }
      return 0;
}

