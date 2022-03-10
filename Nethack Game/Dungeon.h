#pragma once

#include "Room.h"
#include "Player.h"

class Dungeon {
	private:
		SDL_Renderer* gRenderer;

		int dungeon_x_size;
		int dungeon_y_size;
		int obj_arr_size;

		Room* roomArr[9][9];
		int intRoomArr[9][9] = { 0 };
		Tile* objArr[9];

		Room* currentRoom;
	public:

	Dungeon(SDL_Renderer*, Tile* [9], const int, const int, const int);
	~Dungeon();

	bool arraySizeCheck();

	void setRoomArr(Player*);
	Room* getCurrentRoom(Player*);
	void nullRoomArr();
};