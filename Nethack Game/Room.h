#pragma once

#include "Player.h"
#include "Tile.h"
#include "Texture.h"
#include "Wall.h"
#include "CharRender.h"
#include <string>

class Room {
	private:
		std::string layout_index;
		std::string room_name;

		SDL_Renderer* gRenderer;

		Tile* tileArr[23][35];
		Tile* tempTileArr[23][35];
		Tile* objArr[9];
		
		enum Tile_Index {floor, horizontal_wall, vertical_wall, ruc, rdc, luc, ldc};
		

	public:
		Room(std::string, SDL_Renderer*, Tile*[9]);

		bool replaceTileArrayWithRoomData();
		void setTileArr(Player*); //for when I need to replace floor tiles with player tiles

		void tempTileArrToNull();

		void loopTileRender(int tile_index_num, char facing, int length, int startingXCoord, int startingYCoord);

		void resetTilesToFloor();
		void resetTileArr();
		void drawTileTexturesToScreen();
};