#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include "rigidbody.h"
#include "transform.h"
#include "entity.h"
#include "vector.h"

const int WIDTH = 800;
const int HEIGHT = 600;
int main()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Error on initializing SDL_VIDEO");
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Rigidbody Usage Example", WIDTH, HEIGHT, SDL_WINDOW_MAXIMIZED);
    if (window == NULL)
    {
        SDL_Log("Error on initializing SDL_Window");
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        SDL_Log("Error on initializing SDL_Renderer");
        return -1;
    }

    int running = 1;
    SDL_Event event;

    Uint64 lastTime = SDL_GetTicks();
    float deltaTime;

    while (running)
    {
        Uint64 currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = 0;
        }
    }
}