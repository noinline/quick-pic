#include "window.h"

SDL_Window *
Window::get(void) const
{
  return this->m_sdl;
}

Window::Window(std::string name, int width, int height)
{
  this->m_sdl = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, width, height,
                                 SDL_WINDOW_ALWAYS_ON_TOP);
  helper::assert(this->m_sdl != nullptr, __FILE__, __LINE__, SDL_GetError());
}

Window::~Window(void)
{
  if (this->m_sdl)
    SDL_DestroyWindow(this->m_sdl);
}
