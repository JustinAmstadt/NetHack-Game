#pragma once

#include "Texture.h"

#include <string>
#include <SDL.h>


class Tile {
	private:
		//int pixelWidth = (xCoord - 1) * 24 + 3; //not being used currently
		//int pixelHeight = (yCoord - 1) * 24; //not being used currently
		
		

	protected:
		SDL_Renderer* gRenderer;

		std::string name;

		SDL_Texture* texture;
		SDL_Surface* surface;

		int xCoord;
		int yCoord;

		int startingTileWidthDistance = 0;
		int startingTileHeightDistance = 64;

		const int SIZE_OF_TILE = 24;
		int wallX1 = -6 + xCoord * SIZE_OF_TILE + startingTileWidthDistance;
		int wallY1 = -4 + yCoord * SIZE_OF_TILE + startingTileHeightDistance;

		bool isWall = false;

		int tileWidthDistance = 1;
		int tileHeightDistance = 1;

	public:
		Tile();
		Tile(int x, int y);
		~Tile();

		int getPixelWidth();
		int getPixelHeight();

		virtual void render();

		virtual void setXCoord(int);
		virtual void setYCoord(int);
		int getXCoord();
		int getYCoord();

		int getTileWidthDistance();
		void setTileWidthDistance(int);
		int getTileHeightDistance();
		void setTileHeightDistance(int);

		int getStartingTileWidthDistance();
		void setStartingTileWidthDistance(int);
		int getStartingTileHeightDistance();
		void setStartingTileHeightDistance(int);

		void setTexture(SDL_Texture*);
		SDL_Texture* getTexture();

		void setSurface(SDL_Surface*);
		SDL_Surface* getSurface();

		void setName(std::string);
		std::string getName();

		virtual void draw();
		bool getIsWall();
		void setIsWall(bool);
};