#include "image.h"

Image::Image()
{
  helper::assert(SDL_InitSubSystem(SDL_INIT_VIDEO) == 0, __FILE__, __LINE__,
                 SDL_GetError());

  IMG_Init(IMG_INIT_PNG);

  SDL_WindowFlags flags = SDL_WINDOW_SHOWN, SDL_WINDOW_BORDERLESS,
                  SDL_WINDOW_OPENGL, SDL_WINDOW_ALWAYS_ON_TOP;
  SDL_Window *window =
      SDL_CreateWindow("rawr x3", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 640, 480, flags);
  helper::assert(window != nullptr, __FILE__, __LINE__, SDL_GetError());
  this->setWindow(window);

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  helper::assert(renderer != nullptr, __FILE__, __LINE__, SDL_GetError());
  this->setRenderer(renderer);

  SDL_Surface *surface = IMG_Load("image.png");
  helper::assert(surface != nullptr, __FILE__, __LINE__, SDL_GetError());
  this->setSurface(surface);

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  helper::assert(texture != nullptr, __FILE__, __LINE__, SDL_GetError());
  this->setTexture(texture);
}
void
Image::cleanupResources()
{
  SDL_DestroyTexture(this->getTexture());
  SDL_FreeSurface(this->getSurface());
  SDL_DestroyRenderer(this->getRenderer());
  SDL_DestroyWindow(this->getWindow());
  SDL_QuitSubSystem(SDL_INIT_VIDEO);

  IMG_Quit();
  SDL_Quit();
}

SDL_Window *
Image::getWindow() const
{
  return m_window;
}
void
Image::setWindow(SDL_Window *w)
{
  m_window = w;
}

SDL_Renderer *
Image::getRenderer() const
{
  return m_renderer;
}
void
Image::setRenderer(SDL_Renderer *r)
{
  m_renderer = r;
}

SDL_Surface *
Image::getSurface() const
{
  return m_surface;
}
void
Image::setSurface(SDL_Surface *s)
{
  m_surface = s;
}

SDL_Texture *
Image::getTexture() const
{
  return m_texture;
}
void
Image::setTexture(SDL_Texture *t)
{
  m_texture = t;
}
