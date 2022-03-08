#pragma once

#include "Room.h"
#include "Player.h"

class Dungeon {
	private:
		SDL_Renderer* gRenderer;

		int roomArrXSize = 3;
		int roomArrYSize = 3;
		Room* roomArr[3][3];
		int intRoomArr[3][3];
		Tile* objArr[9];

		Room* currentRoom;
	public:

	Dungeon(SDL_Renderer*, Tile* [9]);
	~Dungeon();

	void setRoomArr(Player*);
	Room* getCurrentRoom(Player*);
	void nullRoomArr();
};