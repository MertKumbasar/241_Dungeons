#include <iostream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Map.cpp"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"



//template <typename T > 
// int *menuCH1 (const T *index){ //secimleri burada tutuyoruz

// }

// function to print title
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
      system("pause");
      system("cls");
}


string firstChapter(){
      string name;
      int answer;
      cout << "What your name will be?: ";
      cin  >> name;
      cout << "-----------------------"<<endl;
      cout << "---------------"<<endl;
      cout << "----------"<<endl;
      cout << "Once upon a time, in the south of the Mistlands, in the heat of the war between light and darkness, the two lovers had vowed to meet on a lonely night."<<endl;
      cout << "--------------"<<endl;
      cout << "You suddenly wake up to the sound of a scream and you start running straight to where the sound came from. "<<endl;
      cout << "At the end of the road you see a huge stone door surrounded by branches and moss. and suddenly you hear a sound."<<endl;
      cout << "The Voice: Welcome  "<< name << ",looking for your friend?" << endl;
      cout << endl;
      do{
            cout << "1.  Wait a minute, who are you ? How do you know my name? "<< endl;
            cout << "2.  Where is my beloved ? Tell me NOW !!!! " << endl;
            cout << "3.  *Explore the dungeon !!*(if you choose this, you will start playing.)"<<endl;
            cout << "Answer: ";
            cin >> answer;
            cout << endl;
            if(answer == 1){
                  cout << "The Voice: It really doesn't matter who i am. I am just here to help you"<<endl;
            }
            else if(answer == 2){
                  cout << "The Voice :  Thats a good question my friend but i think the answer is deep down in the dungeon"<<endl;
            }
      }while(answer != 3);
      system("cls");
      return name;
}
string chooseCharacter(){
      system("cls");
      int input;
      cout << "The voice: Wait before you go i need to bless my powers to you down there is too dangerous." << endl;
      cout << "The voice: You have 3 options: Warrior,Mage and Rogue each have their unique powers choose wisely." << endl;
      cout << "Press 1 to choose warrior" << endl;
      cout << "Press 2 to choose mage" << endl; 
      cout << "Press 3 to choose rogue" << endl;
      do{
            cin >> input;
            if(input == 1){
                  return "warrior";
            }
            else if(input == 2){
                  return "mage";
            }
            else if(input == 3){
                  return "rouge";
            }
            else{
                  cout << "enter a vaild input" << endl;
            }
      }while(1);
}


// function to move cursor to top
void gotoxy(short x, short y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}


int main(){
      // variables for main
      string name,player_type;
      int input;
      char event = '.';
      int game_is_on = 1;
      // variables for main

      // objects for main
      Map game_map;
      Player *player;
      Enemy e1;
      // objects for main

      printTitle();
      name = firstChapter();
      player_type = chooseCharacter();

      if(player_type == "warrior"){
            cout << "You choosed warrior" << endl << endl;
            player = new Warrior;
      }
      else if(player_type == "mage"){
            cout << "You choosed mage" << endl << endl;
            player = new Mage;
      }
      else{
            cout << "You choosed rogue" << endl << endl;
            player = new Rogue;
      }
      player->Setname(name);

      cout << "The voice: Then here, This is a map for you to see where you are GOOD LUCK!!" << endl;
      system("pause");
      system("cls");
      
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
                  case 27:
                        game_map.pauseMenu();
                        system("pause");
                        system("cls");      
                  default:
                        break;
                        
                  }
            }
            if(event == 'M'){
                  system("cls");
                  player->battle(e1);
                  system("cls");
                  //if( monster lives ){
                  //      game_map.movePlayer_left_if_monster_lives();
                  // }
                  system("cls");      
            }
            else if(event == 'I'){
                  system("cls");
                  cout << "item event!!!";
                  //Returnn to map in 3 sec
                  Sleep(1000);
            }

            // reseting the event variable
            event = '.';
      }
      delete player;
      return 0;
}