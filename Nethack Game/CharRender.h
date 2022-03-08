#pragma once

#include "Tile.h"

class Asterisk : public Tile {
	private:
		SDL_Renderer* gRenderer;
		SDL_Surface* surface;
		SDL_Texture* texture;

	public:
		Asterisk(SDL_Renderer*, int x, int y);
		~Asterisk();

		void render();
};

//--------------------------------------------------------------------------

class PlayerChar : public Tile {
	private:
		SDL_Renderer* gRenderer;
		SDL_Surface* surface;
		SDL_Texture* texture;

	public:
		PlayerChar(SDL_Renderer*, int x, int y);
		~PlayerChar();

		void render();
};

//--------------------------------------------------------------------------

class Blank : public Tile {
private:

public:
	Blank(int x, int y);
	~Blank();

	void render();
};