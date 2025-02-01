#pragma once
#include "helper.h"

#include <SDL2/SDL.h>
#include <string>

class Window
{
public:
  Window(std::string name, int width, int height);
  ~Window();
  SDL_Window *get() const;

private:
  SDL_Window *m_sdl{nullptr};
};
