#include "Player.h"
#include "Tile.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

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

int Player::subYCoord(Tile* tileArr[24][35])
{
    if (tileArr[yCoord - 1][xCoord]->getIsWall() == false)
    {
        yCoord -= 1;
        return yCoord;
    }
}

int Player::addYCoord(Tile* tileArr[24][35])
{
    if (tileArr[yCoord + 1][xCoord]->getIsWall() == false)
    {
        yCoord += 1;
        return yCoord;
    }
}

int Player::subXCoord(Tile* tileArr[24][35])
{
    if (tileArr[yCoord][xCoord - 1]->getIsWall() == false)
    {
        xCoord -= 1;
        return xCoord;
    }
}

int Player::addXCoord(Tile* tileArr[24][35])
{
    if (tileArr[yCoord][xCoord + 1]->getIsWall() == false)
    {
        xCoord += 1;
        return xCoord;
    }
}
