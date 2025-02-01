#include "flag.h"
#include "image.h"

int
main(int argc, char *argv[])
{
  Flag flag;

  ADD_BOOL(flag, "help", "Show this pretty help message.");
  ADD_STRING(flag, "file",
             "Specify image file to be displayed. Defaults to 'image.png' if "
             "not provided.");
  flag.parse(argc, argv);

  if (IS_SET(flag, "help")) {
    flag.printHelp(argv);
EXIT:
    return 0;
  }

  std::unique_ptr<FileManager> fileManager = std::make_unique<FileManager>();
  /* clang-format off */
  Image     image(GET_VALUE(flag, "file").empty()
                           ? fileManager->getRootDirectory() + "image.png"
                          /*
                           * The image file should be placed in
                           * '~/.config/quick-pic/'. If it's not there and no
                           * file flag provided, the
                           * program will go full existential crisis mode. So,
                           * save yourself the drama and just put the file where
                           * it belongs. Or else...
                           * Don't say i didn't warn you. @_@
                           */
                           : GET_VALUE(flag, "file"));
  /* clang-format on */
  Renderer *renderer = image.getRenderer();
  Texture  *texture = image.getTexture();

  SDL_Event event;
  bool      shouldQuit = false;
  do {
    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
        shouldQuit = true;

    SDL_RenderCopy(renderer->get(), texture->get(), NULL, NULL);
    SDL_RenderPresent(renderer->get());
  } while (!shouldQuit);
  goto EXIT;
}
