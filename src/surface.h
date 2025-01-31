#pragma once
#include "helper.h"

#include <SDL2/SDL_image.h>

class Surface
{
public:
  Surface(std::string img);
  ~Surface();
  SDL_Surface *get() const;

private:
  SDL_Surface *m_sdl{nullptr};
};
