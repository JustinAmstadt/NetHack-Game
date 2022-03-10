#include "Player.h"
#include "Tile.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

Player::Player(int roomXCoord, int roomYCoord)
{
    this->roomXCoord = roomXCoord;
    this->roomYCoord = roomYCoord;
}

Player::~Player()
{
}

int Player::getXCoord() {
    return xCoord;
}

int Player::getYCoord() {
    return yCoord;
}

void Player::setXCoord(int x) {
    xCoord = x;
}

void Player::setYCoord(int y) {
    yCoord = y;
}

int Player::getRoomXCoord()
{
    return roomXCoord;
}

void Player::setRoomXCoord(int x)
{
    roomXCoord = x;
}

int Player::getRoomYCoord()
{
    return roomYCoord;
}

void Player::setRoomYCoord(int y)
{
    roomYCoord = y;
}

void Player::getTileArr(Tile* tileArr[23][35])
{
    for (int y = 0; y < 23; y++)
        for (int x = 0; x < 35; x++) {
            this->tileArr[y][x] = tileArr[y][x];
        }
}

void Player::getIntRoomArr(int intRoomArr[9][9])
{
    for (int y = 0; y < roomArrYSize; y++)
        for (int x = 0; x < roomArrXSize; x++)
            this->intRoomArr[y][x] = intRoomArr[y][x];
}

void Player::getRoomArrSize(int xSize, int ySize)
{
    roomArrXSize = xSize;
    roomArrYSize = ySize;
}

void Player::moveUp()
{
    if (yCoord != 0)
    {
        if (tileArr[yCoord - 1][xCoord]->getIsWall() == false || ghostMode) //simple up movement
        {
            yCoord -= 1;
        }
    }

    else if (yCoord == 0 && intRoomArr[roomYCoord - 1][roomXCoord] == 1) //change to room above
    {
        yCoord = 22;
        roomYCoord -= 1;
    }
}

void Player::moveDown()
{
    if (yCoord != 22) {
        if (tileArr[yCoord + 1][xCoord]->getIsWall() == false || ghostMode)
        {
            yCoord += 1;
        }
    }

    else if (yCoord == 22 && intRoomArr[roomYCoord + 1][roomXCoord] == 1)
    {
        yCoord = 0;
        roomYCoord += 1;
    }
}

void Player::moveLeft()
{
    if (xCoord != 0) {
        if (tileArr[yCoord][xCoord - 1]->getIsWall() == false || ghostMode)
        {
            xCoord -= 1;
        }
    }

    else if (xCoord == 0 && intRoomArr[roomYCoord][roomXCoord - 1] == 1)
    {
        xCoord = 34;
        roomXCoord -= 1;
    }
}

void Player::moveRight()
{
    if (xCoord != 34) {
        if (tileArr[yCoord][xCoord + 1]->getIsWall() == false || ghostMode)
        {
            xCoord += 1;
        }
    }

    else if (xCoord == 34 && intRoomArr[roomYCoord][roomXCoord + 1] == 1)
    {
        xCoord = 0;
        roomXCoord += 1;
    }
}
