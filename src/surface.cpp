#include "surface.h"

/*
 ** clang-format off
 *
 * @brief Constructs a Surface object.
 *
 * Loads an image from the specified file path into an SDL surface. Throws an
 * exception if the image cannot be loaded.
 *
 * @param img The path to the image file to load.
 *
 * @throws std::runtime_error If the image cannot be loaded.
 *
 ** clang-format on
 */

Surface::Surface(std::string img)
{
  this->m_sdl = IMG_Load(img.c_str());
  helper::assert(this->m_sdl != nullptr, SDL_GetError());
}

/*
 ** clang-format off
 *
 * @brief Destructs the Surface object.
 *
 * Frees the SDL surface resources. Called automatically when the object goes
 * out of scope.
 *
 ** clang-format on
 */

Surface::~Surface(void)
{
  if (this->m_sdl)
    SDL_FreeSurface(this->m_sdl);
}

/*
 ** clang-format off
 *
 * @brief Retrieves the underlying SDL surface.
 *
 * @return A pointer to the SDL_Surface object.
 *
 ** clang-format on
 */

SDL_Surface *
Surface::get(void) const
{
  return this->m_sdl;
}
