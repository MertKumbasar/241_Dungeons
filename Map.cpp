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
                map[i][j] = '|';
            }
            else if(j==2 && (i%8==0 && i != 0 && i!=20 ) || j==18 && (i%4==0 && i != 0 && i!=20 && i != 8 && i != 16)){
                map[i][j] = '-';
            }
            else if( i%4 == 0 || j%4 == 0){
                map[i][j] = '#';
            }
            else{
                 map[i][j] = '.';
            }
        }    
    }
    map[dir_x_of_player][dir_y_of_player] = 'P';
    map[2][3] = 'M';
}
void Map::printMap(){
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
          cout << map[i][j] << " ";
        }
        cout << endl;   
    }
}
char Map::movePlayer_up(){
    char event = '.';
    int temp_x = dir_x_of_player - 1;
    int temp_y = dir_y_of_player;
    if(map[temp_x][temp_y] == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y] == 'I'){
        event = 'I';
    }
    if(map[temp_x][temp_y] != '#'){
        map[dir_x_of_player][dir_y_of_player] = '.';
        dir_x_of_player -= 1;
        map[dir_x_of_player][dir_y_of_player] = 'P';
        
    }
    return event;
}
char Map::movePlayer_down(){
    char event = '.';
    int temp_x = dir_x_of_player + 1;
    int temp_y = dir_y_of_player;
    if(map[temp_x][temp_y] == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y] == 'I'){
        event = 'I';
    }
    if(map[temp_x][temp_y] != '#'){
        map[dir_x_of_player][dir_y_of_player] = '.';
        dir_x_of_player += 1;
        map[dir_x_of_player][dir_y_of_player] = 'P';
        
    }
    return event;
}
char Map::movePlayer_left(){
    char event = '.';
    int temp_x = dir_x_of_player;
    int temp_y = dir_y_of_player - 1;
    if(map[temp_x][temp_y] == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y] == 'I'){
        event = 'I';
    }
    if(map[temp_x][temp_y] != '#'){
        map[dir_x_of_player][dir_y_of_player] = '.';
        dir_y_of_player -= 1;
        map[dir_x_of_player][dir_y_of_player] = 'P';
        
    }
    return event;
}
char Map::movePlayer_right(){
    char event = '.';
    int temp_x = dir_x_of_player;
    int temp_y = dir_y_of_player + 1;
    if(map[temp_x][temp_y] == 'M'){
        event = 'M';
    }
    else if(map[temp_x][temp_y] == 'I'){
        event = 'I';
    }
    if(map[temp_x][temp_y] != '#'){
        map[dir_x_of_player][dir_y_of_player] = '.';
        dir_y_of_player += 1;
        map[dir_x_of_player][dir_y_of_player] = 'P';
       
    }
    return event;
}


