
#ifndef MAP_H
#define MAP_H

class Map{
    private:
        int height = 21;
        int width = 21;
    public:
        char map[30][30];
        int dir_x_of_player = 2;
        int dir_y_of_player = 2;
        Map();
        void printMap();
        char movePlayer_up();
        char movePlayer_down();
        char movePlayer_right();
        char movePlayer_left();
        void movePlayer_left_if_monster_lives();
};

#endif 