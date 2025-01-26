#include "helper.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Image
{
public:
  Image();
  void cleanupResources();

  SDL_Window *getWindow() const;
  void        setWindow(SDL_Window *w);

  SDL_Renderer *getRenderer() const;
  void          setRenderer(SDL_Renderer *r);

  SDL_Surface *getSurface() const;
  void         setSurface(SDL_Surface *s);

  SDL_Texture *getTexture() const;
  void         setTexture(SDL_Texture *t);

private:
  SDL_Window   *m_window{nullptr};
  SDL_Renderer *m_renderer{nullptr};
  SDL_Surface  *m_surface{nullptr};
  SDL_Texture  *m_texture{nullptr};
};
