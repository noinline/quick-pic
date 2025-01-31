#include "image.h"

Image::Image(void)
{
  helper::assert(SDL_Init(SDL_INIT_VIDEO) == 0, __FILE__, __LINE__,
                 SDL_GetError());

  helper::assert(IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG, __FILE__, __LINE__,
                 SDL_GetError());

  this->m_fileManager = std::make_unique<FileManager>();
  const std::string dir =
      this->m_fileManager->getHomeDirectory() + "/.config/quick-pic/";
  this->m_fileManager->setRootDirectory(dir);
  helper::assert(!this->m_fileManager->getRootDirectory().empty(), __FILE__,
                 __LINE__, "Failed to set Root Directory! Aborting...");

  this->m_window = std::make_unique<Window>(std::string("rawr x3"), 640, 480);
  this->m_renderer = std::make_unique<Renderer>(this->m_window->get());
  this->m_surface = std::make_unique<Surface>(
      this->m_fileManager->getRootDirectory() + "image.png");
  this->m_texture = std::make_unique<Texture>(this->m_renderer->get(),
                                              this->m_surface->get());
}

Image::~Image(void)
{
  IMG_Quit();
  SDL_Quit();
}

Window *
Image::getWindow() const
{
  return this->m_window.get();
}

Renderer *
Image::getRenderer() const
{
  return this->m_renderer.get();
}

Surface *
Image::getSurface() const
{
  return this->m_surface.get();
}

Texture *
Image::getTexture() const
{
  return this->m_texture.get();
}
