#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"


class GameMap
{
    public:
        GameMap();

        MapCell cells[15][10];

        void draw(int PlayerX, int PlayerY);

        bool validationPlayerCell(int PlayerX, int PlayerY);

    protected:
        void loadMapFromFile();

    private:
};

#endif // GAMEMAP_H
