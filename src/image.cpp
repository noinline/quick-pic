#include "image.h"

/*
 ** clang-format off
 *
 * @brief Constructs an Image object.
 *
 * Initializes SDL, SDL_image, and the FileManager. Sets up the Window,
 * Renderer, Surface, and Texture for the image. If the provided image path is
 * invalid, falls back to the default image. Throws an exception if the default
 * image is also missing @_@.
 *
 * @param image The path to the image file. If not an absolute path or relative
 *              path, falls back to the default image.
 *
 * @throws std::runtime_error If SDL, SDL_image, or the FileManager fails to
 *                            initialize, or if the image file is missing.
 *
 ** clang-format on
 */

Image::Image(std::string image)
{
  helper::assert(SDL_Init(SDL_INIT_VIDEO) == 0, SDL_GetError());

  helper::assert(IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG, SDL_GetError());

  this->m_fileManager = std::make_unique<FileManager>();
  helper::assert(!this->m_fileManager->getRootDirectory().empty(),
                 "Root Directory is empty! Aborting...");

  const std::string defaultImagePath =
      this->m_fileManager->getRootDirectory() + "image.png";
  std::string imagePath = image;

  if (imagePath[0] != '/' && imagePath[0] != '.') {
    /* fallback to default image if not an absolute path
                              or not starts with '.' */
    imagePath = defaultImagePath;
    std::cerr
        << "Warning: '" << image
        << "' is not an image or not found.\n Falling back to default image: '"
        << defaultImagePath << "'" << '\n';
  }
  if (access(imagePath.c_str(), F_OK) != 0 && imagePath == defaultImagePath) {
    if (imagePath != image)
      throw std::runtime_error(
          "Image file '" + image +
          "' is not an image or does not exist, and default image '" +
          imagePath +
          "' is also missing. @_@\n"
          "\tDid you forgot to place it here?\n"
          "\tOr did you just assume the program would magically work with any "
          "file type?\n"
          "\tEither way, this is on you.");
    else
      throw std::runtime_error(
          "Default image '" + imagePath +
          "' is missing. @_@\n"
          "\tDid you forgot to place it here?\n"
          "\tOr did you just assume the program would magically work with any "
          "file type?\n"
          "\tEither way, this is on you.");
  }

  this->m_window = std::make_unique<Window>(std::string("rawr x3"), 640, 480);
  this->m_renderer = std::make_unique<Renderer>(this->m_window->get());
  this->m_surface = std::make_unique<Surface>(imagePath);
  this->m_texture = std::make_unique<Texture>(this->m_renderer->get(),
                                              this->m_surface->get());
}

/*
 ** clang-format off
 *
 * @brief Destructs the Image object.
 *
 * Cleans up SDL and SDL_image resources. Called automatically when the object
 * goes out of scope.
 *
 ** clang-format on
 */

Image::~Image(void)
{
  IMG_Quit();
  SDL_Quit();
}

/*
 ** clang-format off
 *
 * @brief Retrieves the window associated with the image.
 *
 * @return A pointer to the Window object.
 *
 ** clang-format on
 */

Window *
Image::getWindow() const
{
  return this->m_window.get();
}

/*
 ** clang-format off
 *
 * @brief Retrieves the renderer associated with the image.
 *
 * @return A pointer to the Renderer object.
 *
 ** clang-format on
 */

Renderer *
Image::getRenderer() const
{
  return this->m_renderer.get();
}

/*
 ** clang-format off
 *
 * @brief Retrieves the surface associated with the image.
 *
 * @return A pointer to the Surface object.
 *
 ** clang-format on
 */

Surface *
Image::getSurface() const
{
  return this->m_surface.get();
}

/*
 ** clang-format off
 *
 * @brief Retrieves the texture associated with the image.
 *
 * @return A pointer to the Texture object.
 *
 ** clang-format on
 */

Texture *
Image::getTexture() const
{
  return this->m_texture.get();
}

/*
 ** clang-format off
 *
 * @brief Retrieves the filemanager associated with the image.
 *
 * @return A pointer to the FileManager object.
 *
 ** clang-format on
 */

FileManager *
Image::getFileManager() const
{
  return this->m_fileManager.get();
}
