#include "renderer.h"

SDL_Renderer *
Renderer::get(void) const
{
  return this->m_sdl;
}

Renderer::Renderer(SDL_Window *window)
{
  this->m_sdl = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  helper::assert(this->m_sdl != nullptr, __FILE__, __LINE__, SDL_GetError());
}

Renderer::~Renderer(void)
{
  if (this->m_sdl)
    SDL_DestroyRenderer(this->m_sdl);
}
