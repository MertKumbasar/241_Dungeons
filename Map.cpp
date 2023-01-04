#include "Map.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

Map::Map(){
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
            if(i==2 && (j%4==0 && j != 0 && j!=20 ) || i==6 && (j%4==0 && j != 0 && j!=20)|| i==10 && 
            (j%4==0 && j != 0 && j!=20)|| i==14 && (j%4==0 && j != 0 && j!=20) || i==18 && (j%4==0 && j != 0 && j!=20)){
                map[i][j].ch = '|';
                map[i][j].index = -1;
            }
            else if(j==2 && (i%8==0 && i != 0 && i!=20 ) || j==18 && (i%4==0 && i != 0 && i!=20 && i != 8 && i != 16)){
                map[i][j].ch = '-';
                map[i][j].index = -1;
            }
            else if( i%4 == 0 || j%4 == 0){
                map[i][j].ch = '#';
                map[i][j].index = -1;
            }
            else{
                 map[i][j].ch = '.';
                 map[i][j].index = -1;
            }
        }    
    }
    map[dir_x_of_player][dir_y_of_player].ch = 'P';
    map[1][3].ch = 'M';
    map[1][3].index = 0;
    map[2][7].ch = 'M';
    map[2][7].index = 1;
    map[5][9].ch = 'M';
    map[5][9].index = 2;
    map[10][3].ch = 'M';
    map[10][3].index = 3;
    map[14][5].ch = 'M';
    map[14][5].index = 4;

    map[1][2].ch = 'I';
    map[1][2].index = 0;
    map[2][6].ch = 'I';
    map[2][6].index = 1;
    
}
void Map::printMap(){
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
          cout << map[i][j].ch << " ";
        }
        cout << endl;   
    }
}
char Map::movePlayer_up(){
    char event = '.';
    int temp_x = dir_x_of_player - 1;
    int temp_y = dir_y_of_player;
    if(map[temp_x][temp_y].ch == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y].ch == 'I'){
        event = 'I';
    }
    else if(map[temp_x][temp_y].ch == 'H'){
        event = 'H';
    }
    if(map[temp_x][temp_y].ch != '#'){
        map[dir_x_of_player][dir_y_of_player].ch = '.';
        dir_x_of_player -= 1;
        map[dir_x_of_player][dir_y_of_player].ch = 'P';
        
    }
    return event;
}
char Map::movePlayer_down(){
    char event = '.';
    int temp_x = dir_x_of_player + 1;
    int temp_y = dir_y_of_player;
    if(map[temp_x][temp_y].ch == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y].ch == 'I'){
        event = 'I';
    }
    else if(map[temp_x][temp_y].ch == 'H'){
        event = 'H';
    }
    if(map[temp_x][temp_y].ch != '#'){
        map[dir_x_of_player][dir_y_of_player].ch = '.';
        dir_x_of_player += 1;
        map[dir_x_of_player][dir_y_of_player].ch = 'P';
        
    }
    return event;
}
char Map::movePlayer_left(){
    char event = '.';
    int temp_x = dir_x_of_player;
    int temp_y = dir_y_of_player - 1;
    if(map[temp_x][temp_y].ch == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y].ch == 'I'){
        event = 'I';
    }
    else if(map[temp_x][temp_y].ch == 'H'){
        event = 'H';
    }
    if(map[temp_x][temp_y].ch != '#'){
        map[dir_x_of_player][dir_y_of_player].ch = '.';
        dir_y_of_player -= 1;
        map[dir_x_of_player][dir_y_of_player].ch = 'q';
        
    }
    return event;
}
char Map::movePlayer_right(){
    char event = '.';
    int temp_x = dir_x_of_player;
    int temp_y = dir_y_of_player + 1;
    if(map[temp_x][temp_y].ch == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y].ch == 'I'){
        event = 'I';
    }
    else if(map[temp_x][temp_y].ch == 'H'){
        event = 'H';
    }
    if(map[temp_x][temp_y].ch != '#'){
        map[dir_x_of_player][dir_y_of_player].ch = '.';
        dir_y_of_player += 1;
        map[dir_x_of_player][dir_y_of_player].ch = 'P';
       
    }
    return event;
}
void Map::movePlayer_left_if_monster_lives(void){
    map[dir_x_of_player][dir_y_of_player].ch = 'M';
    dir_y_of_player -= 1;
    map[dir_x_of_player][dir_y_of_player].ch = 'P';
}
void Map::pauseMenu(void){
    system("cls");
    cout << "USE W TO GO UP"<<endl;
    cout << "USE D TO GO DOWN"<<endl;
    cout << "USE D TO GO RIGHT"<<endl;
    cout << "USE A TO GO LEFT"<<endl;
    cout << "---- MAP LEGEND ------"<<endl;
    cout << "P is PLAYER"<<endl;
    cout << "M is MONSTER"<<endl;
    cout << "H is HEALTH POTION" << endl;
    
}


