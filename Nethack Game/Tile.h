#pragma once

#include "Texture.h"

#include <string>
#include <SDL.h>


class Tile {
	private:
		int xCoord;
		int yCoord;
		int pixelWidth = (xCoord - 1) * 24 + 3; //not being used currently
		int pixelHeight = (yCoord - 1) * 24; //not being used currently
		int startingTileWidthDistance = 0;
		int startingTileHeightDistance = 40;
		int tileWidthDistance = 1;
		int tileHeightDistance = 1;

		bool isWall = false;

		std::string name;

		SDL_Texture* texture;
		SDL_Surface* surface;

		SDL_Renderer* gRenderer;

	public:
		Tile(SDL_Texture*, SDL_Surface*, std::string, SDL_Renderer*);
		~Tile();

		int getPixelWidth();
		int getPixelHeight();

		void setXCoord(int);
		void setYCoord(int);
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

		void draw();
		bool getIsWall();
		void setIsWall(bool);
};