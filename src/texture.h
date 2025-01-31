#pragma once
#include "helper.h"

#include <SDL2/SDL.h>

class Texture
{
public:
  Texture(SDL_Renderer *renderer, SDL_Surface *surface);
  ~Texture();
  SDL_Texture *get() const;

private:
  SDL_Texture *m_sdl{nullptr};
};
