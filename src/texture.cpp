#include "texture.h"

SDL_Texture *
Texture::get(void) const
{
  return this->m_sdl;
}

Texture::Texture(SDL_Renderer *renderer, SDL_Surface *surface)
{
  this->m_sdl = SDL_CreateTextureFromSurface(renderer, surface);
  helper::assert(this->m_sdl != nullptr, __FILE__, __LINE__, SDL_GetError());
}

Texture::~Texture(void)
{
  if (this->m_sdl)
    SDL_DestroyTexture(this->m_sdl);
}
