/*
To-Do List:
add an info section on the top
- add health bar/info
- currently equipped items
- current level/area
- remove one height and add a permanent upper wall to separate status area from playable area
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

#include "Player.h"
#include "Texture.h"
#include "Tile.h"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <fstream>
#include <array>

bool drawBoard(Player* player, Texture* floor_texture, Texture* player_texture, SDL_Surface* screenSurface, SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, Tile* tileArr[24][35]) {
    
    //resets all tiles to the floor tile
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 35; j++) {
            tileArr[i][j]->setTexture(floor_texture->getTexture());
            tileArr[i][j]->setSurface(floor_texture->getSurface());
            tileArr[i][j]->setName("floor");
        }
    }

    //replace a floor tile with player tile
    tileArr[player->getYCoord()][player->getXCoord()]->setName("player");
    tileArr[player->getYCoord()][player->getXCoord()]->setTexture(player_texture->getTexture());
    tileArr[player->getYCoord()][player->getXCoord()]->setSurface(player_texture->getSurface());
    
    //resets rendering target
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    //makes a black screen
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 00, 00, 00));
    SDL_UpdateWindowSurface(window);

    tileArr[10][7]->setName("vertical wall");
    tileArr[9][7]->setName("right up corner");
    tileArr[9][6]->setName("horizontal wall");

    tileArr[11][7]->setName("right down corner");
    tileArr[11][5]->setName("left down corner");
    tileArr[9][5]->setName("left up corner");

    tileArr[10][5]->setName("vertical wall");
    tileArr[11][6]->setName("horizontal wall");

    tileArr[10][6]->setName("blank");

    //draws tile textures onto screen
    for (int i = 0; i < 24; i++) 
    {
        for (int j = 0; j < 35; j++) 
        {
            if (tileArr[i][j]->getName() == "floor")
            {
                SDL_Rect floor_destination = { tileArr[i][j]->getTileWidthDistance(), tileArr[i][j]->getTileHeightDistance(), tileArr[i][j]->getSurface()->w, tileArr[i][j]->getSurface()->h };

                if (SDL_RenderCopy(renderer, tileArr[i][j]->getTexture(), NULL, &floor_destination) < 0)
                    std::cout << SDL_GetError();
            }
            else if (tileArr[i][j]->getName() == "player")
            {
                                                                  //adds plus one to account for the fact that the & was a pixel off to the left
                SDL_Rect player_destination = { tileArr[i][j]->getTileWidthDistance() + 1, tileArr[i][j]->getTileHeightDistance(), tileArr[i][j]->getSurface()->w, tileArr[i][j]->getSurface()->h };

                if (SDL_RenderCopy(renderer, tileArr[i][j]->getTexture(), NULL, &player_destination) < 0)
                    std::cout << SDL_GetError();
            }
        }
    }

    

    SDL_RenderPresent(renderer);

    return true;
}

int gameLoop(Player* player, Texture* floor_texture, Texture* player_texture, SDL_Surface* screenSurface, SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture) {
    bool quit = false;

    SDL_Event e;

    //creates a 2D tile array and assigns the objects to the floor texture, gives them the floor name, and gives them proper pixel coordinates and x/y coordinates
    Tile* tileArr[24][35];
    //must first create objects to be able to pull out starting tile width distance. This way I can control that value from the class, not search for the variable in the main function
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 35; j++) {
            tileArr[i][j] = new Tile(floor_texture->getTexture(), floor_texture->getSurface(), "floor", renderer);
        }
    }

    int tileWidthDistance = tileArr[0][0]->getStartingTileWidthDistance();
    int tileHeightDistance = tileArr[0][0]->getStartingTileHeightDistance();

    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 35; j++) {
            tileArr[i][j]->setTileWidthDistance(tileWidthDistance);
            tileArr[i][j]->setTileHeightDistance(tileHeightDistance);
            tileArr[i][j]->setXCoord(j);
            tileArr[i][j]->setYCoord(i);
            tileWidthDistance += 24;
        }
        tileHeightDistance += 24;
        tileWidthDistance = tileArr[0][0]->getStartingTileWidthDistance();
    }

    drawBoard(player, floor_texture, player_texture, screenSurface, window, renderer, texture, tileArr);

    while (!quit) {

        
        //keyboard event handling
        while (SDL_WaitEvent(&e) != 0) {
            //if the user does an action that triggers the SDL_QUIT
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    
                    case SDLK_UP:
                        if (player->getYCoord() != 0)
                            player->subYCoord(tileArr);
                        break;

                    case SDLK_DOWN:
                        if (player->getYCoord() != 23)
                            player->addYCoord(tileArr);
                        break;

                    case SDLK_LEFT:
                        if (player->getXCoord() != 0)
                            player->subXCoord(tileArr);
                        break;

                    case SDLK_RIGHT:
                        if (player->getXCoord() != 34)
                            player->addXCoord(tileArr);
                        break;

                }
                drawBoard(player, floor_texture, player_texture, screenSurface, window, renderer, texture, tileArr);
            }
        }
    }

    return 0;
}

bool sdlAssignWindowSurfaceRendererTexture(SDL_Window*& window, SDL_Surface*& screenSurface, SDL_Renderer*& renderer, SDL_Texture*& texture) {
    const int SCREEN_WIDTH = 832;
    const int SCREEN_HEIGHT = 610; //orig height was 570
    
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
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;

    Player* player = NULL;
    Texture* player_texture = NULL;
    Texture* floor_texture = NULL;

    sdlAssignWindowSurfaceRendererTexture(window, screenSurface, renderer, texture);

    player = new Player();
    player_texture = new Texture(renderer, "player");
    floor_texture = new Texture(renderer, "floor");

    gameLoop(player, floor_texture, player_texture, screenSurface, window, renderer, texture);

    SDL_StopTextInput();
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    screenSurface = NULL;
    renderer = NULL;
    texture = NULL;
    player = NULL;
    player_texture = NULL;
    floor_texture = NULL;
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}