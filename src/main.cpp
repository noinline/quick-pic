#include "image.h"

int
main(void)
{
  Image     sdl;
  SDL_Event event;
  bool      shouldQuit = false;

  while (!shouldQuit) {
    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
        shouldQuit = true;

    SDL_RenderClear(sdl.getRenderer());
    SDL_RenderCopy(sdl.getRenderer(), sdl.getTexture(), NULL, NULL);
    SDL_RenderPresent(sdl.getRenderer());
  }

  sdl.cleanupResources();

  return 0;
}
