#include "image.h"

int
main(void)
{
  Image     image;
  Renderer *renderer = image.getRenderer();
  Texture  *texture = image.getTexture();
  SDL_Event event;

  bool shouldQuit = false;
  do {
    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
        shouldQuit = true;

    SDL_RenderCopy(renderer->get(), texture->get(), NULL, NULL);
    SDL_RenderPresent(renderer->get());
  } while (!shouldQuit);

  return 0;
}
