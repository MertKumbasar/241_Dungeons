#include <iostream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Map.cpp"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "ASCII_arts.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "MiniGame.h"

// template <typename T >
//  int *menuCH1 (const T *index){ //secimleri burada tutuyoruz

// }

string firstChapter()
{
      string name;
      int answer;
      cout << "What your name will be?: ";
      cin >> name;
      cout << "-----------------------" << endl;
      cout << "---------------" << endl;
      cout << "----------" << endl;
      cout << "Once upon a time, in the south of the Mistlands, in the heat of the war between light and darkness, the two lovers had vowed to meet on a lonely night." << endl;
      cout << "--------------" << endl;
      cout << "You suddenly wake up to the sound of a scream and you start running straight to where the sound came from. " << endl;
      cout << "At the end of the road you see a huge stone door surrounded by branches and moss. and suddenly you hear a sound." << endl;
      cout << "The Voice: Welcome  " << name << ",looking for your friend?" << endl;
      cout << endl;
      do
      {
            cout << "1.  Wait a minute, who are you ? How do you know my name? " << endl;
            cout << "2.  Where is my beloved ? Tell me NOW !!!! " << endl;
            cout << "3.  *Explore the dungeon !!*(if you choose this, you will start playing.)" << endl;
            cout << "Answer: ";
            cin >> answer;
            cout << endl;
            if (answer == 1)
            {
                  cout << "The Voice: It really doesn't matter who i am. I am just here to help you" << endl;
            }
            else if (answer == 2)
            {
                  cout << "The Voice :  Thats a good question my friend but i think the answer is deep down in the dungeon" << endl;
            }
            else if (answer == 3)
            {
                  system("cls");
                  return name;
            }
      } while (answer != 1 || answer != 2 || answer != 3);
}
string chooseCharacter()
{
      system("cls");
      int input;
      cout << "The voice: Wait before you go i need to bless my powers to you down there is too dangerous." << endl;
      cout << "The voice: You have 3 options: Warrior,Mage and Rogue each have their unique powers choose wisely." << endl;
      cout << "Press 1 to choose warrior" << endl;
      cout << "Press 2 to choose mage" << endl;
      cout << "Press 3 to choose rogue" << endl;
      do
      {
            cin >> input;
            if (input == 1)
            {
                  return "warrior";
            }
            else if (input == 2)
            {
                  return "mage";
            }
            else if (input == 3)
            {
                  return "rouge";
            }
            else
            {
                  cout << "enter a valid input" << endl;
            }
      } while (1);
}
void boss_story()
{
      cout << "-After all the war and hardship, you see a dark room with a huge entrance." << endl;
      cout << "........";
      cout << "....";
      cout << "-You also enter this desolate dark room hoping to find the one you love AND suddenly the torches start burning in order......." << endl;
      cout << "-With the last torch burning, you see your loved one exhausted and next to it you see a monster as gigantic as it is terrifying!!!!" << endl;
      cout << "And you hear a voice. You've come at last." << endl;
      cout << "The voice: You've come at last.";
      cout << "Unfortunately your coming this far means nothing, You will be ruined at last " << endl;
      cout << "-You recognize this sound and immediately draw your weapon!!" << endl;
      cout << "                                  FIGHT BEGINS!!!!                                " << endl;
}

// function to move cursor to top
void gotoxy(short x, short y)
{
      COORD pos = {x, y};
      HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleCursorPosition(output, pos);
}

int main()
{
      // variables for main
      string name, player_type;
      int input, counter{0}, battle_result{0};
      char event = '.';
      int game_is_on = 1;
      // variables for main

      // objects for main
      RPC game1;
      Map game_map;
      Player *player;
      Enemy monsters[5];
      Weapon weapons[5];
      Potion potions[4];

      potions[0] = Potion("mini_health_potion", 25);
      potions[1] = Potion("large_health_potion", 50);

      weapons[0] = Weapon(5, 5, "Sword");
      weapons[1] = Weapon(10, 1, "Axe");
      weapons[2] = Weapon(8, 5, "Dagger");
      weapons[3] = Weapon(13, 0, "Bow");
      weapons[4] = Weapon(15, 15, "Spear");

      monsters[0] = Enemy("Koblin", 150, 35, 45);
      monsters[1] = Enemy("Melkor", 150, 45, 25);
      monsters[2] = Enemy("Talrog", 150, 50, 35);
      monsters[3] = Enemy("Bohr", 60, 110, 20);
      monsters[4] = Enemy("Asmodeus", 350, 60, 45); // final boss
                                                    // objects for main

      MagicScroll scrolls[3];
      scrolls[0] = MagicScroll(10, 0, "Fire Ball", 15);
      scrolls[1] = MagicScroll(20, 0, "Lightning Bolt", 30);
      scrolls[2] = MagicScroll(100, 0, "Nuke", 70);

      printTitle();
      name = firstChapter();
      player_type = chooseCharacter();

      if (player_type == "warrior")
      {
            cout << "YOU CHOSE WARRIOR" << endl
                 << endl;
            player = new Warrior;
            printWarrior();
            cout << endl;
      }
      else if (player_type == "mage")
      {
            int ch;
            cout << "YOU CHOSE MAGE" << endl
                 << endl;

            player = new Mage;
            do
            {
                  cout << "Pick any scroll: " << endl;
                  cout << "Press 1 to choose Fire Ball (low mana low damage)" << endl;
                  cout << "Press 2 to choose Lightning Bolt  (mid mana mid damage)" << endl;
                  cout << "Press 3 to choose Nuke (high mana high damage)" << endl;
                  cin >> ch;
                  if (ch == 1)
                  {
                        player->SetMagicScroll(scrolls[0]);
                  }
                  else if (ch == 2)
                  {
                        player->SetMagicScroll(scrolls[1]);
                  }
                  else if (ch == 3)
                  {
                        player->SetMagicScroll(scrolls[2]);
                  }
                  else
                  {
                        cout << "Invalid number" << endl;
                  }
            } while (ch != 1 && ch != 2 && ch != 3);

            printMage();
            cout << endl;
      }
      else
      {
            cout << "YOU CHOSE ROGUE" << endl
                 << endl;
            player = new Rogue;
            printRogue();
            cout << endl;
      }
      player->Setname(name);

      cout << "The voice: Then here, This is a map for you to see where you are GOOD LUCK!!" << endl;
      system("pause");
      system("cls");
      while (game_is_on)
      {
            gotoxy(0, 0);

            game_map.printMap();
            Sleep(100);

            if (_kbhit())
            {
                  switch (getch())
                  {
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
                  case 'i':
                        player->PrintStatus();
                        system("pause");
                        system("cls");
                        break;
                  case 27:
                        game_map.pauseMenu();
                        system("pause");
                        system("cls");
                  default:
                        break;
                  }
            }
            if (event == 'M')
            {
                  system("cls");
                  if (game_map.map[game_map.dir_x_of_player][game_map.dir_y_of_player].index == 4)
                  {
                        boss_story();
                        system("pause");
                        system("cls");
                        battle_result = player->battle(monsters[game_map.map[game_map.dir_x_of_player][game_map.dir_y_of_player].index]);
                        if (battle_result == 2)
                        {
                              cout << "MONSTER IS DEAD!! " << endl
                                   << "GOOD JOB" << endl;
                              game_is_on = 0;
                        }
                        else if (battle_result == 1)
                        {
                              cout << "COWARD !-! " << endl;
                              game_map.movePlayer_left_if_monster_lives();
                        }
                        else
                        {
                              game_is_on = 0;
                        }
                  }
                  else
                  {
                        battle_result = player->battle(monsters[game_map.map[game_map.dir_x_of_player][game_map.dir_y_of_player].index]);
                        if (battle_result == 2)
                        {
                              cout << "MONSTER IS DEAD!! " << endl
                                   << "GOOD JOB" << endl;
                        }
                        else if (battle_result == 1)
                        {
                              cout << "COWARD !-! " << endl;
                              game_map.movePlayer_left_if_monster_lives();
                        }
                        else
                        {
                              game_is_on = 0;
                        }
                  }
                  system("pause");
                  system("cls");
            }
            else if (event == 'I')
            {
                  system("cls");
                  cout << "You found an item!!!" << endl;
                  cout << "Atributes of item are:" << endl;
                  player->AddWeapon(weapons[game_map.map[game_map.dir_x_of_player][game_map.dir_y_of_player].index]);
                  system("pause");
                  system("cls");
            }
            else if (event == 'H')
            {
                  system("cls");
                  cout << "You found an potion!!!" << endl;
                  cout << "Atributes of potion are:" << endl;
                  player->DrinkPotion(potions[game_map.map[game_map.dir_x_of_player][game_map.dir_y_of_player].index]);
                  system("pause");
                  system("cls");
            }
            else if (event == 'G')
            {
                  system("cls");
                  cout << "You entered MINI GAME AREA !!" << endl;
                  cout << "Have fun playing !" << endl;
                  game1.CheckResult();
                  system("pause");
                  system("cls");
            }

            // reseting the event variable
            event = '.';
      }
      if (battle_result == 0)
      {
            cout << "YOU ARE DEAD !! " << endl;
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "                                     THE END                                         " << endl;
      }
      else
      {
            cout << "-With the beast falling to the ground" << endl;
            cout << "....." << endl;
            cout << "-Your loved one is slowly sobering up" << endl;
            cout << "After darkness has banished, a door opens by itself and beams of light enter the dungeon " << endl;
            cout << "You and your lover manage escape out of the dungeon by walking out that door " << endl;
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "                                     THE END                                         " << endl;
      }
      delete player;
      return 0;
}
