#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include "rigidbody.h"
#include "transform.h"
#include "entity.h"
#include "vector.h"

const int WIDTH = 800;
const int HEIGHT = 600;

void SDL_CreateWhiteRectangle(
    SDL_Renderer *renderer,
    float x,
    float y,
    float scaleX,
    float scaleY)
{
    SDL_FRect rect = {
        .x = x,
        .y = y,
        .w = scaleX,
        .h = scaleY};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

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

    Entity *entidade = Entity_Create();
    Transform *transform = Transform_Create((Vector){WIDTH / 2, HEIGHT / 2}, (Vector){50, 50}, 0);
    Rigidbody *rb = Rigidbody_Create(4, 10);

    Entity_AddModule(entidade, (Module *)transform);
    Entity_AddModule(entidade, (Module *)rb);

    float speed = 5000;

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

        const bool *keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_W])
            Rigidbody_AddForce(rb, (Vector){0, -1 * speed});
        if (keys[SDL_SCANCODE_S])
            Rigidbody_AddForce(rb, (Vector){0, 1 * speed});
        if (keys[SDL_SCANCODE_A])
            Rigidbody_AddForce(rb, (Vector){-1 * speed, 0});
        if (keys[SDL_SCANCODE_D])
            Rigidbody_AddForce(rb, (Vector){1 * speed, 0});

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        Entity_Update(entidade, deltaTime);

        SDL_CreateWhiteRectangle(renderer, transform->position.x, transform->position.y, transform->scale.x, transform->scale.y);
        SDL_RenderPresent(renderer);
    }
}