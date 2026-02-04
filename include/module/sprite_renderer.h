#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL.h>
#include "module.h"

typedef struct SpriteRenderer
{
    Module base;
    SDL_Texture *texture;
    SDL_FRect destiny;
} SpriteRenderer;

SpriteRenderer *SpriteRenderer_Create();
void SpriteRenderer_Destroy(Module *self);
void SpriteRenderer_Update(Module *self, float deltaTime);

void SpriteRenderer_SetTexture(SpriteRenderer *renderer, SDL_Texture *texture);
void SpriteRenderer_SetTextureFromPath(
    SpriteRenderer *renderer,
    SDL_Renderer *sdlRenderer,
    const char *path);

void SpriteRenderer_Render(
    SpriteRenderer *renderer,
    SDL_Renderer *sdlRenderer);

#endif