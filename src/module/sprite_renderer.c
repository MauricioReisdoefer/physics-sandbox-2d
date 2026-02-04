#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "module.h"
#include "sprite_renderer.h"
#include "rect.h"

#include <stdlib.h>

void SpriteRenderer_Destroy(Module *self)
{
    if (!self)
        return;

    SpriteRenderer *sprite_renderer = (SpriteRenderer *)self;

    if (sprite_renderer->texture)
    {
        SDL_DestroyTexture(sprite_renderer->texture);
        sprite_renderer->texture = NULL;
    }

    free(sprite_renderer);
}

void SpriteRenderer_SetTexture(SpriteRenderer *renderer, SDL_Texture *texture)
{
    if (!renderer)
        return;

    if (renderer->texture)
    {
        SDL_DestroyTexture(renderer->texture);
    }

    renderer->texture = texture;
}

void SpriteRenderer_SetTextureFromPath(SpriteRenderer *renderer, const char *path)
{
    if (!renderer || !renderer->renderer || !path)
        return;

    SDL_Texture *texture = IMG_LoadTexture(renderer->renderer, path);
    if (!texture)
    {
        SDL_Log("IMG_LoadTexture failed (%s): %s", path, SDL_GetError());
        return;
    }

    SpriteRenderer_SetTexture(renderer, texture);
}

void SpriteRenderer_Update(Module *self, float deltaTime)
{
    (void)deltaTime;

    if (!self)
        return;

    SpriteRenderer *sprite_renderer = (SpriteRenderer *)self;
    SpriteRenderer_Render(sprite_renderer);
}

void SpriteRenderer_Render(SpriteRenderer *renderer)
{
    if (!renderer || !renderer->renderer || !renderer->texture)
        return;

    SDL_FRect frect = {
        .x = renderer->destiny.x,
        .y = renderer->destiny.y,
        .w = renderer->destiny.scaleX,
        .h = renderer->destiny.scaleY};

    SDL_RenderTexture(renderer->renderer, renderer->texture, NULL, &frect);
}

SpriteRenderer *SpriteRenderer_Create(SDL_Renderer *sdl_renderer)
{
    if (!sdl_renderer)
        return NULL;

    SpriteRenderer *sprite_renderer = malloc(sizeof(SpriteRenderer));
    if (!sprite_renderer)
        return NULL;

    sprite_renderer->base.type = MODULE_RENDERER;
    sprite_renderer->base.update = SpriteRenderer_Update;
    sprite_renderer->base.destroy = SpriteRenderer_Destroy;
    sprite_renderer->base.owner = NULL;

    sprite_renderer->renderer = sdl_renderer;
    sprite_renderer->texture = NULL;
    sprite_renderer->destiny = (Rect){0, 0, 0, 0};

    return sprite_renderer;
}
