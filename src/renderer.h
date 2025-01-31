#pragma once
#include "helper.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer
{
public:
  Renderer(SDL_Window *window);
  ~Renderer();
  SDL_Renderer *get() const;

private:
  SDL_Renderer *m_sdl{nullptr};
};
