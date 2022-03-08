#include "Tile.h"

#include <iostream>

Tile::Tile()
{
	xCoord = -1;
	yCoord = -1;

	texture = NULL;
	surface = NULL;

	name = "filler";

	gRenderer = NULL;
}

Tile::Tile(int x, int y)
{
	xCoord = x;
	yCoord = y;
}

Tile::~Tile()
{
}

//int Tile::getPixelWidth() 
//{
//	return pixelWidth;
//}
//
//int Tile::getPixelHeight() 
//{
//	return pixelHeight;
//}

int Tile::getXCoord() 
{
	return xCoord;
}

int Tile::getYCoord() 
{
	return yCoord;
}

int Tile::getTileWidthDistance()
{
	return tileWidthDistance;
}

void Tile::setTileWidthDistance(int w) 
{
	tileWidthDistance = w;
}

int Tile::getTileHeightDistance()
{
	return tileHeightDistance;
}

void Tile::setTileHeightDistance(int h) 
{
	tileHeightDistance = h;
}

int Tile::getStartingTileWidthDistance()
{
	return startingTileWidthDistance;
}

int Tile::getStartingTileHeightDistance()
{
	return startingTileHeightDistance;
}

void Tile::setTexture(SDL_Texture* texture) 
{
	this->texture = texture;
}

SDL_Texture* Tile::getTexture() 
{
	return texture;
}

void Tile::setSurface(SDL_Surface* surface) 
{
	this->surface = surface;
}

SDL_Surface* Tile::getSurface() 
{
	return surface;
}

void Tile::setXCoord(int x) 
{
	xCoord = x;
}

void Tile::setYCoord(int y) 
{
	yCoord = y;
}

//currently acts as the way to change from char tile to wall tile or any other draw line tile
void Tile::setName(std::string newName) 
{
	name = newName;

	if (name == "vertical wall" || name == "horizontal wall" || name == "right up corner" || name == "right down corner" || name == "left up corner" || name == "left down corner"
		|| name == "chest")
		draw();
	else if (name == "blank")
	{
		texture = NULL;
		surface = NULL;
	}
}

std::string Tile::getName() 
{
	return name;
}

void Tile::draw() 
{
	texture = NULL;
	surface = NULL;

	const int X_WIDTH_OF_TILE = 24;
	const int Y_HEIGHT_OF_TILE = 24;
	int wallX1 = -6 + xCoord * X_WIDTH_OF_TILE + startingTileWidthDistance;
	int wallY1 = -4 + yCoord * Y_HEIGHT_OF_TILE + startingTileHeightDistance;

	isWall = true;

	if (name == "vertical wall") 
	{
		int x2 = wallX1 + 1;
		int x3 = wallX1 + X_WIDTH_OF_TILE;
		int x4 = x3 + 1;
		int y2 = wallY1 + Y_HEIGHT_OF_TILE;
		
		SDL_RenderDrawLine(gRenderer, wallX1, wallY1, wallX1, y2);
		SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y2);
		SDL_RenderDrawLine(gRenderer, x3, wallY1, x3, y2);
		SDL_RenderDrawLine(gRenderer, x4, wallY1, x4, y2);
	}

	else if (name == "horizontal wall") 
	{
		int x2 = wallX1 + X_WIDTH_OF_TILE;
		int y2 = wallY1 + 1;
		int y3 = wallY1 + Y_HEIGHT_OF_TILE;
		int y4 = y3 + 1;

		SDL_RenderDrawLine(gRenderer, wallX1, wallY1, x2, wallY1);
		SDL_RenderDrawLine(gRenderer, wallX1, y2, x2, y2);
		SDL_RenderDrawLine(gRenderer, wallX1, y3, x2, y3);
		SDL_RenderDrawLine(gRenderer, wallX1, y4, x2, y4);
	}

	else if (name == "right up corner")
	{
		int x2 = wallX1 + X_WIDTH_OF_TILE;
		int x3 = x2 + 1;
		int y2 = wallY1 + 1;
		int y3 = wallY1 + Y_HEIGHT_OF_TILE;

		SDL_RenderDrawLine(gRenderer, wallX1, wallY1, x2, wallY1);
		SDL_RenderDrawLine(gRenderer, wallX1, y2, x2, y2);
		SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y3);
		SDL_RenderDrawLine(gRenderer, x3, wallY1, x3, y3);
	}

	else if (name == "right down corner")
	{
		int x2 = wallX1 + X_WIDTH_OF_TILE;
		int x3 = x2 + 1;
		int y2 = wallY1 + Y_HEIGHT_OF_TILE;
		int y3 = y2 + 1;

		SDL_RenderDrawLine(gRenderer, wallX1, y2, x2, y2);
		SDL_RenderDrawLine(gRenderer, wallX1, y3, x2, y3);
		SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y3);
		SDL_RenderDrawLine(gRenderer, x3, wallY1, x3, y3);
	}

	else if (name == "left up corner")
	{
		int x2 = wallX1 + 1;
		int x3 = wallX1 + X_WIDTH_OF_TILE;
		int y2 = wallY1 + 1;
		int y3 = wallY1 + Y_HEIGHT_OF_TILE;

		SDL_RenderDrawLine(gRenderer, wallX1, wallY1, wallX1, y3);
		SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y3);
		SDL_RenderDrawLine(gRenderer, wallX1, wallY1, x3, wallY1);
		SDL_RenderDrawLine(gRenderer, wallX1, y2, x3, y2);
	}

	else if (name == "left down corner")
	{
		int x2 = wallX1 + 1;
		int x3 = wallX1 + X_WIDTH_OF_TILE;
		int y2 = wallY1 + Y_HEIGHT_OF_TILE;
		int y3 = y2 + 1;

		SDL_RenderDrawLine(gRenderer, wallX1, wallY1, wallX1, y2);
		SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y2);
		SDL_RenderDrawLine(gRenderer, wallX1, y2, x3, y2);
		SDL_RenderDrawLine(gRenderer, wallX1, y3, x3, y3);
	}

	else if (name == "chest")
	{

	}
}

bool Tile::getIsWall()
{
	return isWall;
}

void Tile::setIsWall(bool isWall)
{
	this->isWall = isWall;
}

void Tile::render() {

}