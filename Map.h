
#ifndef MAP_H
#define MAP_H

class Map{
    private:
        int height = 21;
        int width = 21;
        char map[30][30];
    public:
        int dir_x_of_player = 2;
        int dir_y_of_player = 2;
        Map();
        void printMap();
        void movePlayer_up();
        void movePlayer_down();
        void movePlayer_right();
        void movePlayer_left();
       
};

#endif 