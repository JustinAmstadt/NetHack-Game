#pragma once

#include "Tile.h"

#include <SDL.h>

class Player {
private:
    int xCoord = 17;
    int yCoord = 11;
    int middleXCoord = 17;
    int middleYCoord = 11;
    int roomXCoord = 1;
    int roomYCoord = 1;

    int health = 0;
    int attackDamage = 0;
    int armorRating = 0;

    Tile* tileArr[23][35];
    int intRoomArr[3][3];

    int roomArrXSize;
    int roomArrYSize;

    bool ghostMode = true;

public:
    
    int getXCoord();
    void setXCoord(int x);
    int getYCoord();
    void setYCoord(int y);
    int getRoomXCoord();
    void setRoomXCoord(int x);
    int getRoomYCoord();
    void setRoomYCoord(int y);

    void getTileArr(Tile* tileArr[23][35]);
    void getIntRoomArr(int intRoomArr[3][3]);
    void getRoomArrSize(int, int);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};


