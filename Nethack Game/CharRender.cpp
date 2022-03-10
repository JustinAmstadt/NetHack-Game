#include "CharRender.h"

#include <iostream>

Asterisk::Asterisk(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	Texture* floor_texture = new Texture(renderer, "floor", color, font_size);
	gRenderer = renderer;
	this->surface = floor_texture->getSurface();
	this->texture = floor_texture->getTexture();
	
}

Asterisk::~Asterisk()
{
}

void Asterisk::render()
{
	tileWidthDistance = xCoord * SIZE_OF_TILE;
	tileHeightDistance = yCoord * SIZE_OF_TILE + startingTileHeightDistance;
	
	SDL_Rect floor_destination = { tileWidthDistance, tileHeightDistance, surface->w, surface->h };

	if (SDL_RenderCopy(gRenderer, texture, NULL, &floor_destination) < 0)
		std::cout << SDL_GetError();
}

//--------------------------------------------------------------------------

BrightAsterisk::BrightAsterisk(SDL_Renderer* renderer, int x, int y)
	: Tile(x, y)
{
	Texture* floor_texture = new Texture(renderer, "floor", color, font_size);
	gRenderer = renderer;
	this->surface = floor_texture->getSurface();
	this->texture = floor_texture->getTexture();

}

BrightAsterisk::~BrightAsterisk()
{
}

void BrightAsterisk::render()
{
	tileWidthDistance = xCoord * SIZE_OF_TILE;
	tileHeightDistance = yCoord * SIZE_OF_TILE + startingTileHeightDistance;

	SDL_Rect floor_destination = { tileWidthDistance, tileHeightDistance, surface->w, surface->h };

	if (SDL_RenderCopy(gRenderer, texture, NULL, &floor_destination) < 0)
		std::cout << SDL_GetError();
}

//--------------------------------------------------------------------------

PlayerChar::PlayerChar(SDL_Renderer* renderer, int x, int y)
: Tile(x, y)
{
	Texture* player_texture = new Texture(renderer, "player", color, font_size);
	gRenderer = renderer;
	this->surface = player_texture->getSurface();
	this->texture = player_texture->getTexture();
}

PlayerChar::~PlayerChar()
{
}

void PlayerChar::render()
{
	tileWidthDistance = xCoord * SIZE_OF_TILE;
	tileHeightDistance = yCoord * SIZE_OF_TILE + startingTileHeightDistance;

	SDL_Rect floor_destination = { tileWidthDistance, tileHeightDistance, surface->w, surface->h };

	if (SDL_RenderCopy(gRenderer, texture, NULL, &floor_destination) < 0)
		std::cout << SDL_GetError();
}

//--------------------------------------------------------------------------

Blank::Blank(int x, int y)
: Tile(x, y)
{}

Blank::~Blank()
{
}

void Blank::render()
{
}
