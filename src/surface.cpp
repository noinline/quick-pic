#include "surface.h"

SDL_Surface *
Surface::get(void) const
{
  return this->m_sdl;
}

Surface::Surface(std::string img)
{
  this->m_sdl = IMG_Load(img.c_str());
  helper::assert(this->m_sdl != nullptr, __FILE__, __LINE__, SDL_GetError());
}

Surface::~Surface(void)
{
  if (this->m_sdl)
    SDL_FreeSurface(this->m_sdl);
}
