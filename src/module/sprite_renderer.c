#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL.h>
#include "module.h"
#include "sprite_renderer.h"
#include "rect.h"

void SpriteRenderer_Destroy(Module *self)
{
    SpriteRenderer *sprite_renderer = (SpriteRenderer *)self;
    if (self == NULL)
        return;
    free(sprite_renderer);

    sprite_renderer = NULL;
    self = NULL;
}

void SpriteRenderer_SetTexture(SpriteRenderer *renderer, SDL_Texture *texture)
{
    if (renderer == NULL)
        return;
    renderer->texture = texture;
}
void SpriteRenderer_SetTextureFromPath(
    SpriteRenderer *renderer,
    const char *path)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer->renderer, path);
    SpriteRenderer_SetTexture(renderer, texture);
}

void SpriteRenderer_Render(
    SpriteRenderer *renderer)
{
    SDL_FRect Frect = {renderer->destiny.x, renderer->destiny.y, renderer->destiny.h, renderer->destiny.w};
    SDL_RenderTexture(renderer->renderer, renderer->texture, NULL, &Frect);
}

SpriteRenderer *SpriteRenderer_Create(SDL_Renderer *sdl_renderer)
{
    SpriteRenderer *sprite_renderer = (SpriteRenderer *)malloc(sizeof(SpriteRenderer));
    if (sprite_renderer == NULL)
    {
        return NULL;
    }
    sprite_renderer->base.type = MODULE_TRANSFORM;
    sprite_renderer->base.update = SpriteRenderer_Update;
    sprite_renderer->base.destroy = SpriteRenderer_Destroy;
    sprite_renderer->base.owner = NULL;

    sprite_renderer->renderer = sdl_renderer;
    sprite_renderer->texture = NULL;

    return sprite_renderer;
}

void SpriteRenderer_Update(Module *self, float deltaTime)
{
    SpriteRenderer *sprite_renderer = (SpriteRenderer *)self;
    if (sprite_renderer == NULL)
    {
        return NULL;
    }
    SpriteRenderer_Render(sprite_renderer);
}