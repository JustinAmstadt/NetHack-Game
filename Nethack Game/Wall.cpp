#include "Wall.h"
#include "Tile.h"
#include <iostream>

VertWall::VertWall(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	gRenderer = renderer;
	isWall = true;

}

VertWall::~VertWall()
{
}

void VertWall::render()
{
	wallX1 = -6 + xCoord * SIZE_OF_TILE + startingTileWidthDistance;
	wallY1 = -4 + yCoord * SIZE_OF_TILE + startingTileHeightDistance;
	int x2 = wallX1 + 1;
	int x3 = wallX1 + SIZE_OF_TILE;
	int x4 = x3 + 1;
	int y2 = wallY1 + SIZE_OF_TILE;

	SDL_RenderDrawLine(gRenderer, wallX1, wallY1, wallX1, y2);
	SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y2);
	SDL_RenderDrawLine(gRenderer, x3, wallY1, x3, y2);
	SDL_RenderDrawLine(gRenderer, x4, wallY1, x4, y2);
}

//--------------------------------------------------------------------------

HorizontalWall::HorizontalWall(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	gRenderer = renderer;
	isWall = true;
}

HorizontalWall::~HorizontalWall()
{
}

void HorizontalWall::render()
{
	wallX1 = -6 + xCoord * SIZE_OF_TILE + startingTileWidthDistance;
	wallY1 = -4 + yCoord * SIZE_OF_TILE + startingTileHeightDistance;
	int x2 = wallX1 + SIZE_OF_TILE;
	int y2 = wallY1 + 1;
	int y3 = wallY1 + SIZE_OF_TILE;
	int y4 = y3 + 1;

	SDL_RenderDrawLine(gRenderer, wallX1, wallY1, x2, wallY1);
	SDL_RenderDrawLine(gRenderer, wallX1, y2, x2, y2);
	SDL_RenderDrawLine(gRenderer, wallX1, y3, x2, y3);
	SDL_RenderDrawLine(gRenderer, wallX1, y4, x2, y4);
}

//--------------------------------------------------------------------------

RightUpCorner::RightUpCorner(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	gRenderer = renderer;
	isWall = true;
}

RightUpCorner::~RightUpCorner()
{
}

void RightUpCorner::render()
{
	wallX1 = -6 + xCoord * SIZE_OF_TILE + startingTileWidthDistance;
	wallY1 = -4 + yCoord * SIZE_OF_TILE + startingTileHeightDistance;
	int x2 = wallX1 + SIZE_OF_TILE;
	int x3 = x2 + 1;
	int y2 = wallY1 + 1;
	int y3 = wallY1 + SIZE_OF_TILE;

	SDL_RenderDrawLine(gRenderer, wallX1, wallY1, x2, wallY1);
	SDL_RenderDrawLine(gRenderer, wallX1, y2, x2, y2);
	SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y3);
	SDL_RenderDrawLine(gRenderer, x3, wallY1, x3, y3);
}

//--------------------------------------------------------------------------

RightDownCorner::RightDownCorner(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	gRenderer = renderer;
	isWall = true;
}

RightDownCorner::~RightDownCorner()
{
}

void RightDownCorner::render()
{
	wallX1 = -6 + xCoord * SIZE_OF_TILE + startingTileWidthDistance;
	wallY1 = -4 + yCoord * SIZE_OF_TILE + startingTileHeightDistance;
	int x2 = wallX1 + SIZE_OF_TILE;
	int x3 = x2 + 1;
	int y2 = wallY1 + SIZE_OF_TILE;
	int y3 = y2 + 1;

	SDL_RenderDrawLine(gRenderer, wallX1, y2, x2, y2);
	SDL_RenderDrawLine(gRenderer, wallX1, y3, x2, y3);
	SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y3);
	SDL_RenderDrawLine(gRenderer, x3, wallY1, x3, y3);
}

//--------------------------------------------------------------------------

LeftUpCorner::LeftUpCorner(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	gRenderer = renderer;
	isWall = true;
}

LeftUpCorner::~LeftUpCorner()
{
}

void LeftUpCorner::render()
{
	wallX1 = -6 + xCoord * SIZE_OF_TILE + startingTileWidthDistance;
	wallY1 = -4 + yCoord * SIZE_OF_TILE + startingTileHeightDistance;
	int x2 = wallX1 + 1;
	int x3 = wallX1 + SIZE_OF_TILE;
	int y2 = wallY1 + 1;
	int y3 = wallY1 + SIZE_OF_TILE;

	SDL_RenderDrawLine(gRenderer, wallX1, wallY1, wallX1, y3);
	SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y3);
	SDL_RenderDrawLine(gRenderer, wallX1, wallY1, x3, wallY1);
	SDL_RenderDrawLine(gRenderer, wallX1, y2, x3, y2);
}

//--------------------------------------------------------------------------

LeftDownCorner::LeftDownCorner(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	gRenderer = renderer;
	isWall = true;
}

LeftDownCorner::~LeftDownCorner()
{
}

void LeftDownCorner::render()
{
	wallX1 = -6 + xCoord * SIZE_OF_TILE + startingTileWidthDistance;
	wallY1 = -4 + yCoord * SIZE_OF_TILE + startingTileHeightDistance;
	int x2 = wallX1 + 1;
	int x3 = wallX1 + SIZE_OF_TILE;
	int y2 = wallY1 + SIZE_OF_TILE;
	int y3 = y2 + 1;

	SDL_RenderDrawLine(gRenderer, wallX1, wallY1, wallX1, y2);
	SDL_RenderDrawLine(gRenderer, x2, wallY1, x2, y2);
	SDL_RenderDrawLine(gRenderer, wallX1, y2, x3, y2);
	SDL_RenderDrawLine(gRenderer, wallX1, y3, x3, y3);
}