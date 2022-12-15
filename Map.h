
#ifndef MAP_H
#define MAP_H

class Map{
    private:
        int height = 21;
        int width = 21;
        char map[30][30];
    public:
        Map();
        void printMap();
};

#endif 