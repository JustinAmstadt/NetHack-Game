#include "Dungeon.h"
#include "Room.h"
#include "Player.h"
#include <iostream>

Dungeon::Dungeon(SDL_Renderer* renderer, Tile* objArr[9])
{
	gRenderer = renderer;
	nullRoomArr();

	for (int i = 0; i < 9; i++)
		this->objArr[i] = objArr[i];
}

Dungeon::~Dungeon()
{
}

void Dungeon::setRoomArr(Player* player)
{
	roomArr[1][0] = new Room("1", gRenderer, objArr);
	roomArr[1][1] = new Room("0", gRenderer, objArr);
	roomArr[2][1] = new Room("5", gRenderer, objArr);

	for (int y = 0; y < roomArrYSize; y++)
		for (int x = 0; x < roomArrXSize; x++)
		{
			if (roomArr[y][x] != NULL)
				intRoomArr[y][x] = 1;
		}

	player->getRoomArrSize(roomArrXSize, roomArrYSize);
	player->getIntRoomArr(intRoomArr);
}

Room* Dungeon::getCurrentRoom(Player* player)
{
	currentRoom = roomArr[player->getRoomYCoord()][player->getRoomXCoord()];
	return currentRoom;
}

void Dungeon::nullRoomArr()
{
	for (int y = 0; y < roomArrYSize; y++)
		for (int x = 0; x < roomArrXSize; x++)
		{
			roomArr[y][x] = NULL;
			intRoomArr[y][x] = 0;
		}
}
