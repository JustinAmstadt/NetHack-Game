#pragma once

#include "Tile.h"

#include <SDL.h>

class Player {
private:
    int xCoord = 17;
    int yCoord = 11;
    int middleXCoord = 17;
    int middleYCoord = 11;
    int roomXCoord;
    int roomYCoord;

    int health = 0;
    int attackDamage = 0;
    int armorRating = 0;

    Tile* tileArr[23][35];
    int intRoomArr[9][9] = { 0 };

    int roomArrXSize;
    int roomArrYSize;

    bool ghostMode = true;

public:
    Player(int roomXCoord, int roomYCoord);
    ~Player();

    int getXCoord();
    void setXCoord(int x);
    int getYCoord();
    void setYCoord(int y);
    int getRoomXCoord();
    void setRoomXCoord(int x);
    int getRoomYCoord();
    void setRoomYCoord(int y);

    void getTileArr(Tile* tileArr[23][35]);
    void getIntRoomArr(int intRoomArr[9][9]);
    void getRoomArrSize(int, int);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};


