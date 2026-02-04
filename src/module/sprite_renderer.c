#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL.h>
#include "module.h"
#include "sprite_renderer.h"

void SpriteRenderer_Destroy(Module *self)
{
    SpriteRenderer *sprite_renderer = (SpriteRenderer *)self;
    if (self == NULL)
        return;
    free(sprite_renderer);

    sprite_renderer = NULL;
    self = NULL;
}

void SpriteRenderer_Update(Module *self, float deltaTime);

void SpriteRenderer_SetTexture(SpriteRenderer *renderer, SDL_Texture *texture);
void SpriteRenderer_SetTextureFromPath(
    SpriteRenderer *renderer,
    SDL_Renderer *sdlRenderer,
    const char *path);

void SpriteRenderer_Render(
    SpriteRenderer *renderer,
    SDL_Renderer *sdlRenderer);

SpriteRenderer *SpriteRenderer_Create()
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

    sprite_renderer->texture = NULL;

    return sprite_renderer;
}