#pragma once

#include "Tile.h"

class Asterisk : public Tile {
	private:
		SDL_Renderer* gRenderer;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Color color = { 128,128,128 };
		int font_size = 25;

	public:
		Asterisk(SDL_Renderer*, int x, int y);
		~Asterisk();

		void render();
};

//--------------------------------------------------------------------------

class BrightAsterisk : public Tile {
private:
	SDL_Renderer* gRenderer;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Color color = { 255, 255, 255 };
	int font_size = 25;

public:
	BrightAsterisk(SDL_Renderer*, int x, int y);
	~BrightAsterisk();

	void render();
};

//--------------------------------------------------------------------------

class PlayerChar : public Tile {
	private:
		SDL_Renderer* gRenderer;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Color color = { 255, 255, 255 };
		int font_size = 15;

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