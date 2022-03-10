#include "Dungeon.h"
#include "Room.h"
#include "Player.h"
#include <iostream>

Dungeon::Dungeon(SDL_Renderer* renderer, Tile* objArr[9], const int DUNGEON_X_SIZE, const int DUNGEON_Y_SIZE, const int OBJ_ARR_SIZE)
{
	gRenderer = renderer;
	nullRoomArr();

	dungeon_x_size = DUNGEON_X_SIZE;
	dungeon_y_size = DUNGEON_Y_SIZE;
	obj_arr_size = OBJ_ARR_SIZE;

	arraySizeCheck();

	for (int i = 0; i < 9; i++)
		this->objArr[i] = objArr[i];
}

Dungeon::~Dungeon()
{
}

void Dungeon::setRoomArr(Player* player)
{
	roomArr[4][3] = new Room("1", gRenderer, objArr);
	roomArr[4][4] = new Room("21", gRenderer, objArr);

	roomArr[4][5] = new Room("7", gRenderer, objArr);
	roomArr[4][6] = new Room("4", gRenderer, objArr);

	roomArr[5][4] = new Room("8", gRenderer, objArr);
	roomArr[6][4] = new Room("4", gRenderer, objArr);
	roomArr[7][4] = new Room("3", gRenderer, objArr);

	for (int y = 0; y < dungeon_y_size; y++)
		for (int x = 0; x < dungeon_x_size; x++)
		{
			if (roomArr[y][x] != NULL)
				intRoomArr[y][x] = 1;
		}

	player->getRoomArrSize(dungeon_x_size, dungeon_y_size);
	player->getIntRoomArr(intRoomArr);
}

Room* Dungeon::getCurrentRoom(Player* player)
{
	currentRoom = roomArr[player->getRoomYCoord()][player->getRoomXCoord()];
	return currentRoom;
}

void Dungeon::nullRoomArr()
{
	for (int y = 0; y < dungeon_y_size; y++)
		for (int x = 0; x < dungeon_x_size; x++)
		{
			roomArr[y][x] = NULL;
		}
}

bool Dungeon::arraySizeCheck()
{
	bool success = true;

	//gets length of the array for both dimensions
	int ySize = sizeof(roomArr) / sizeof(roomArr[0]);
	int xSize = sizeof(roomArr[0]) / sizeof(Room*);

	int yIntSize = sizeof(intRoomArr) / sizeof(intRoomArr[0]);
	int xIntSize = sizeof(intRoomArr[0]) / sizeof(int);

	int objArrSize = sizeof(objArr) / sizeof(objArr[0]);

	if (xSize != dungeon_x_size)
	{
		std::cout << "dungeon roomArr x size does not match global DUNGEON_X_SIZE\n";
		success = false;
	}

	if (ySize != dungeon_y_size)
	{
		std::cout << "dungeon roomArr y size does not match global DUNGEON_Y_SIZE\n";
		success = false;
	}

	if (objArrSize != obj_arr_size)
	{
		std::cout << "dungeon object array size does not match global OBJ_ARR_SIZE\n";
		success = false;
	}

	if (xSize != xIntSize)
	{
		std::cout << "dungeon Room* x array and int x array do not match\n";
		success = false;
	}

	if (ySize != yIntSize)
	{
		std::cout << "dungeon Room* y array and int y array do not match\n";
		success = false;
	}

	return success;
}
