#include "Texture.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

Texture::Texture(SDL_Renderer* renderer, std::string texture_name) {
	setName(texture_name);
	setFont();
	createSurface();
	createTexture(renderer);
	gRenderer = renderer;
}

std::string Texture::getName() {
	return name;
}

void Texture::setName(std::string name) {
	this->name = name;
}

TTF_Font* Texture::getFont() {
	return font;
}

SDL_Surface* Texture::getSurface() {
	return surface;
}

SDL_Texture* Texture::getTexture() {
	return texture;
}

bool Texture::setFont() {

	if (name == "floor")
		font = TTF_OpenFont("C:\\Windows\\Fonts\\ADOBEGOTHICSTD-BOLD.OTF", 25);
	else if (name == "player")
		font = TTF_OpenFont("C:\\Windows\\Fonts\\ADOBEGOTHICSTD-BOLD.OTF", 15);
	else
		std::cout << "name is incompatible with texture class.";

	if (font == NULL) {
		std::cout << "Failed to load font. TTF Error: " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}

bool Texture::createSurface() {
	if (name == "floor")
		surface = TTF_RenderText_Solid(font, "*", floorColor);
	else if (name == "player")
		surface = TTF_RenderText_Solid(font, "&", playerColor);
	else
		std::cout << "The name '" << name << "' is incompatible with texture class." << std::endl;

	if (surface == NULL) {
		std::cout << "Failed to create texture class surface. SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

bool Texture::createTexture(SDL_Renderer* renderer) {
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
		std::cout << "Failed to create texture class texture. SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}