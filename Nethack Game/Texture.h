#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Texture {
	private:
		std::string name;
		
		TTF_Font* font;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Color color = { 0 };
		int font_size;

		SDL_Renderer* gRenderer;

	public:

		Texture(SDL_Renderer*, std::string, SDL_Color, int);
		~Texture();

		std::string getName();
		
		TTF_Font* getFont();
		SDL_Surface* getSurface();
		SDL_Texture* getTexture();


		void setName(std::string);
		bool setFont();
		bool createSurface();
		bool createTexture(SDL_Renderer*);
};

