/*
To-Do List:
add an info section on the top
- add health bar/info
- currently equipped items
- current level/area
- text message section

bombs
walls block sight
cracked walls
item that increases sight range
add enemies
add attacks
add magic
add arrows
make a door
make it so you can only see enemies within a certain range
add item menu/screen
make a treasure chest
*/

/*
0: starting room
1: side connected room with two openings
2: "" right side open
3: "" left side open
4: south opening dead end
5: north south hallway with room in middle
6: 4-way intersection
*/

#include "Player.h"
#include "Texture.h"
#include "Tile.h"
#include "Wall.h"
#include "CharRender.h"
#include "Room.h"
#include "Dungeon.h"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <fstream>
#include <array>

const int SCREEN_WIDTH = 828;
const int SCREEN_HEIGHT = 606;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

bool drawStatusSection(SDL_Renderer* renderer) {
    /*const int SCREEN_WIDTH = 828;
    int x1 = tileArr[0][0]->getStartingTileWidthDistance();
    int x2 = x1 + SCREEN_WIDTH;
    int y1 = -4 + tileArr[0][0]->getStartingTileHeightDistance();
    int y2 = y1 - 1;
    
    SDL_RenderDrawLine(renderer, x1, y1, x2, y1);
    SDL_RenderDrawLine(renderer, x1, y2, x2, y2);
    SDL_RenderPresent(renderer);*/
    return true;
}

bool drawBoard(Player* player, SDL_Surface* screenSurface, SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, Dungeon* dungeon, Room* room) {
    
    //resets rendering target
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    //makes a black screen
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 00, 00, 00));
    SDL_UpdateWindowSurface(window);

    //makes sure room is up to date
    room = dungeon->getCurrentRoom(player);

    //gets rid of player then replaces player in new position
    room->setTileArr(player);

    //draws tile textures onto screen
    room->drawTileTexturesToScreen();

    return true;
}

int gameLoop(Player* player, SDL_Surface* screenSurface, SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture) {
    bool quit = false;

    SDL_Event e;

    Tile* objArr[9];

    objArr[0] = new Asterisk(renderer, -1, -1);
    objArr[1] = new HorizontalWall(renderer, -1, -1);
    objArr[2] = new VertWall(renderer, -1, -1);
    objArr[3] = new RightUpCorner(renderer, -1, -1);
    objArr[4] = new RightDownCorner(renderer, -1, -1);
    objArr[5] = new LeftUpCorner(renderer, -1, -1);
    objArr[6] = new LeftDownCorner(renderer, -1, -1);
    objArr[7] = new PlayerChar(renderer, player->getXCoord(), player->getYCoord());
    objArr[8] = new Blank(-1, -1);

    //create a new object with the starting room id

    Room* room = NULL;
    Dungeon* dungeon = new Dungeon(renderer, objArr);
    dungeon->setRoomArr(player);

    drawBoard(player, screenSurface, window, renderer, texture, dungeon, room);
    drawStatusSection(renderer);

    while (!quit) {

        
        //keyboard event handling
        while (SDL_WaitEvent(&e) != 0) {
            //if the user does an action that triggers the SDL_QUIT
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    
                    case SDLK_UP:
                        player->moveUp();
                        break;

                    case SDLK_DOWN:
                        player->moveDown();
                        break;

                    case SDLK_LEFT:
                        player->moveLeft();
                        break;

                    case SDLK_RIGHT:
                        player->moveRight();
                        break;

                }
                drawBoard(player, screenSurface, window, renderer, texture, dungeon, room);
                drawStatusSection(renderer);
            }
        }
    }
    return 0;
}

bool sdlAssignWindowSurfaceRendererTexture(SDL_Window*& window, SDL_Surface*& screenSurface, SDL_Renderer*& renderer, SDL_Texture*& texture) {
    
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL video init error. SDL Error : " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() < 0) {
        std::cout << "SDL2_TTF failed to initialize. TTF Error: " << TTF_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Nethack Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    screenSurface = SDL_GetWindowSurface(window);
    if (screenSurface == NULL) {
        std::cout << "Screen surface could not be created. SDL Error: " << SDL_GetError() << std::endl;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (texture == NULL) {
        std::cout << "Texture could not be created. SDL Error: " << SDL_GetError() << std::endl;
    }

    return true;
}

int main(int argc, char* args[]) {


    sdlAssignWindowSurfaceRendererTexture(window, screenSurface, renderer, texture);

    Player* player = new Player();
    
    gameLoop(player, screenSurface, window, renderer, texture);

    SDL_StopTextInput();
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    screenSurface = NULL;
    renderer = NULL;
    texture = NULL;
    player = NULL;
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}