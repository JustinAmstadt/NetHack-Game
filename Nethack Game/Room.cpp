#include "Room.h"
#include "Texture.h"
#include "Tile.h"
#include "CharRender.h"
#include "Wall.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <array>


Room::Room(std::string x, SDL_Renderer* renderer, Tile* objArr[9])
{
    layout_index = x;
    gRenderer = renderer;

    for(int i = 0; i < 9; i++)
        this->objArr[i] = objArr[i];

    replaceTileArrayWithRoomData();
}

bool Room::replaceTileArrayWithRoomData()
{
    std::string line;
    std::string file_room_index = layout_index + ":";

    //index: plus one ex: 3: -> 4:
    int index_num = stoi(layout_index) + 1;
    std::string file_room_index_plus_one = std::to_string(index_num) + ":"; 

    std::ifstream roomDataFile;

    roomDataFile.open("Room Data.txt");

    if (roomDataFile.is_open()) {
        char facing, punctuation = ',';
        int startingXCoord,
            startingYCoord,
            tile_index_num,
            length;
        while (getline(roomDataFile, line))
        {
            if (line == file_room_index)
                while (punctuation != ';')
                {  
                    roomDataFile 
                     >> tile_index_num >> punctuation
                     >> facing >> punctuation
                     >> length >> punctuation
                     >> startingXCoord >> punctuation
                     >> startingYCoord >> punctuation;

                    loopTileRender(tile_index_num, facing, length, startingXCoord, startingYCoord);
                }   
        }
        roomDataFile.close();
    }
    else
        std::cout << "Room layout file failed to open." << std::endl;


    for (int y = 0; y < 23; y++)
        for (int x = 0; x < 35; x++) {
            if (!tileArr[y][x])
            tileArr[y][x] = objArr[8];
        }

	return true;
}

void Room::loopTileRender(int tile_index_num, char facing, int length, int startingXCoord, int startingYCoord)
{
    int curX = startingXCoord,
        curY = startingYCoord;
    for (int i = 0; i < length; i++) {
        tileArr[curY][curX] = objArr[tile_index_num];

        if (facing == 'N')
            curY -= 1;
        else if (facing == 'S')
            curY += 1;
        else if (facing == 'E')
            curX += 1;
        else if (facing == 'W')
            curX -= 1;
        else if (facing == 'X')
        {
        }
        else {
            std::cout << "Invalid facing argument" << std::endl;
            return;
        }
    }
}

void Room::setTileArr(Player* player) 
{
    resetTileArr();

    int playerX = player->getXCoord();
    int playerY = player->getYCoord();

    tempTileArr[playerY][playerX] = tileArr[playerY][playerX];
    tileArr[playerY][playerX] = objArr[7];
    tileArr[playerY][playerX]->setXCoord(playerX);
    tileArr[playerY][playerX]->setYCoord(playerY);
    /*std::cout << "x coord: " << playerX << std::endl
        << "y coord: " << playerY << std::endl << std::endl;*/

    player->getTileArr(tileArr);
}

void Room::resetTileArr()
{
    
    for (int y = 0; y < 23; y++)
        for (int x = 0; x < 35; x++) 
            if (tempTileArr[y][x] != NULL)
                tileArr[y][x] = tempTileArr[y][x];
        
    tempTileArrToNull();
}

void Room::drawTileTexturesToScreen()
{
    //draws tile textures onto screen
    for (int y = 0; y < 23; y++)
        for (int x = 0; x < 35; x++) {
            tileArr[y][x]->setXCoord(x);
            tileArr[y][x]->setYCoord(y);
            tileArr[y][x]->render();
        }

    SDL_RenderPresent(gRenderer);
}

void Room::tempTileArrToNull()
{
    for (int y = 0; y < 23; y++)
        for (int x = 0; x < 35; x++) 
            tempTileArr[y][x] = NULL;
}


